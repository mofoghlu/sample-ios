//
//  ABSAppDelegate.h
//  AppboySample
//
//  Created by Jonathan Hyman on 5/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "src/FBConnect.h"

@class ABSViewController;

@interface ABSAppDelegate : UIResponder <UIApplicationDelegate, FBSessionDelegate> {
    Facebook *facebook;
}
-(void) loginWithFacebook;

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) ABSViewController *viewController;
@property (nonatomic, retain) Facebook *facebook;

@end
