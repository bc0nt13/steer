//
//  SharedSettings.h
//  Waterloo
//
//  Created by Bruno Conti on 10/19/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface SharedSettings : NSObject {
  // Accelerometer View
  double _accelerometerSteeringDeadZone;
  double _accelerometerPowerDeadZone;
  double _accelerometerSteeringSensitivity;
  double _accelerometerPowerSensitivity;
  double _accelerometerFrequency;
  
  // Dual Joystick View
  double _dualJoystickDeadZone;
  
  // Connection info
  NSString *_ipAddress;
  NSString *_cameraAddress;
}

@property (assign, nonatomic) double accelerometerSteeringDeadZone;
@property (assign, nonatomic) double accelerometerPowerDeadZone;
@property (assign, nonatomic) double accelerometerSteeringSensitivity;
@property (assign, nonatomic) double accelerometerPowerSensitivity;
@property (assign, nonatomic) double accelerometerFrequency;
@property (assign, nonatomic) double dualJoystickDeadZone;
@property (retain, nonatomic) NSString *ipAddress;
@property (retain, nonatomic) NSString *cameraAddress;

+ (SharedSettings*) sharedManager;
- (void) saveDefaults;
- (void) retrieveDefaults;

@end
