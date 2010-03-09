//
//  FFMPEGAppDelegate.h
//  FFMPEG
//
//  Created by Bruno Conti on 3/4/10.
//  Copyright 2010. All rights reserved.
//

#import "GHGLViewController.h"

#import "FFAVFrameQueue.h"

@interface FFMPEGAppDelegate : NSObject <UIApplicationDelegate> {
  UIWindow *_window;
	GHGLViewController *_GLViewController;
  FFAVFrameQueue *_frameQueue;
}

@end

