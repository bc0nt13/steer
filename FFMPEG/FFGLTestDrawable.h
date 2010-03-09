//
//  FFGLTestDrawable.h
//  FFMPEG
//
//  Created by Bruno Conti on 3/7/10.
//  Copyright 2010. All rights reserved.
//

#import "GHGLView.h"
#import "GHGLTexture.h"

@interface FFGLTestDrawable : NSObject <GHGLViewDrawable> {
  GHGLTexture *_texture;
}

@end
