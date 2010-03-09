//
//  ControlViewController.h
//  Steer
//
//  Created by Bruno Conti on 3/7/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "CarControl.h"

@class ControlViewController;

@protocol ControlViewControllerDelegate
- (void)controlViewControllerWillClose:(ControlViewController *)controlViewController;
@end

@interface ControlViewController : UIViewController {
  CarControl *_carControl;
  id<ControlViewControllerDelegate> _delegate;
}

@property (assign, nonatomic) id<ControlViewControllerDelegate> delegate;

- (void)setSteering:(double)steering power:(double)power;

@end