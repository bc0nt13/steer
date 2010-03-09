//
//  CarControl.h
//  Acsend
//
//  Created by Bruno Conti on 7/7/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "SendUDP.h"

@interface CarControl : NSObject {
  BOOL _noRepeatCommands;
  char _lastCommand[4];
}

@property (assign, nonatomic) BOOL noRepeatCommands;

- (id)initWithIP:(NSString *)ipAddressString;
- (void)stop;
- (void)sendCommandToMotor:(double)motor andSteering:(double) steering;

@end
