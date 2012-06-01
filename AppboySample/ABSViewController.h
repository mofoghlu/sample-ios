//
//  ABSViewController.h
//  AppboySample
//
//  Created by Jonathan Hyman on 5/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppboySession.h"

@interface ABSViewController : UIViewController <AppboySessionDelegate> {
    IBOutlet UIButton *appboyButton;
    IBOutlet UIButton *appboyButtonPortrait;    
    IBOutlet UIButton *appboyFeedbackButton;
    IBOutlet UIButton *appboyFeedbackButtonPortrait;    
    IBOutlet UIButton *appboyExploreButton;
    IBOutlet UIButton *appboyExploreButtonPortrait;    
    IBOutlet UIButton *shareButton;
    IBOutlet UIButton *loginWithFacebookButton;
    IBOutlet UIButton *logoutWithFacebookButton;
}
@property (nonatomic, retain) UIButton *appboyButton;
@property (nonatomic, retain) UIButton *appboyButtonPortrait;
@property (nonatomic, retain) UIButton *appboyFeedbackButton;
@property (nonatomic, retain) UIButton *appboyFeedbackButtonPortrait;
@property (nonatomic, retain) UIButton *appboyExploreButton;
@property (nonatomic, retain) UIButton *appboyExploreButtonPortrait;
@property (nonatomic, retain) UIButton *loginWithFacebookButton;
@property (nonatomic, retain) UIButton *logoutWithFacebookButton;
@property (nonatomic, retain) UILabel *titleLabel;
@property (nonatomic, retain) UIButton *shareButton;

@end