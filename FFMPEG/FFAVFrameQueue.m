//
//  FFAVFrameQueue.m
//  FFMPEG
//
//  Created by Bruno Conti on 3/8/10.
//  Copyright 2010. All rights reserved.
//

#import "FFAVFrameQueue.h"
#import "FFDefines.h"

@implementation FFAVFrameQueue

@synthesize player=_player;

- (id)initWithURL:(NSURL *)URL format:(NSString *)format {
  if ((self = [self init])) {
    _URL = [URL retain];
    _format = [format retain];
    _lock = [[NSLock alloc] init];
    _frame = NULL;
  }
  return self;
}

- (void)dealloc {
  _running = NO;
  [_player release];
  [_URL release];
  [_format release];
  [_lock release];
  [super dealloc];
}

- (void)_run {
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];  
  _running = YES;
  FFDebug(@"Started");
    
  // TODO(gabe): Must be power of 2 for texture
  FFPlayer *player = [[FFPlayer alloc] initWithWidth:256 height:256 pixelFormat:PIX_FMT_RGB24];
  
  while (![player isOpen] && _running) {    
    if (![player openWithURL:_URL format:_format error:nil]) {
      FFDebug(@"Error opening player, waiting & trying again");
      [NSThread sleepForTimeInterval:2];
    }
  }

  // Frame decoded from video stream (before conversion)
  _frame = avcodec_alloc_frame();
  // TODO(gabe): if (_frame == NULL)  
  
  _player = player;
  
  _videoDataSize = [_player bufferLength];
  _videoData = (uint8_t*)av_malloc(_videoDataSize * sizeof(uint8_t));
  
  BOOL running = YES;
  while (running && _running) {  
    NSError *error = nil;
    [_player readFrame:_frame error:&error];    
    if (error) {
      running = NO;
      continue;
    }
    _readFrameIndex++;
    //[NSThread sleepForTimeInterval:0.1];
  }
  
  av_free(_frame);
  av_free(_videoData);
  
  _running = NO;
  _started = NO;
  FFDebug(@"Stopped");
  [pool release];  
}

- (uint8_t *)nextData {  
  if (!_started) {
    _started = YES;    
    [NSThread detachNewThreadSelector:@selector(_run) toTarget:self withObject:nil];          
  }
  
  if (![_player isOpen]) return NULL;
  if (_frame == NULL) return NULL;
  
  if (_readFrameIndex == _frameIndex) {
    //FFDebug(@"Skipping, frame unchanged");
    return NULL;
  }

  [_lock lock];
  AVFrame *frame = [_player scaleFrame:_frame error:nil];
  memcpy(_videoData, frame->data[0], _videoDataSize);
  _frameIndex = _readFrameIndex;
  [_lock unlock];
  return _videoData;
}

@end
