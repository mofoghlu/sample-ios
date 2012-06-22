//
//  ABSViewController.m
//  AppboySample
//
//  Created by Jonathan Hyman on 5/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ABSViewController.h"
#import "ABSAppDelegate.h"
#import "AppboySession.h"

@interface ABSViewController ()

@end

@implementation ABSViewController

- (void)viewDidLoad
{
  [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
  [super viewDidUnload];
  // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
  if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
      return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
  } else {
      return YES;
  }
}

// Is notified when [AppboySession isReady] goes from false to true
- (void) AppboyDelegateStatusChange {
  NSLog(@"In AppboyDelegateStatusChange");
}

- (void) AppboyDelegateAccountStatus {
  // Use the helper methods [AppboySession get*AccessToken] to access the OAuth information.
  NSLog(@"AppboyDelegateAccountStatus facebook:%@ expiresAt:%@, twitterAccessToken:%@, twitterAccessSecret:%@",
        [AppboySession getFacebookAccessToken],
        [AppboySession getFacebookAccessExpiration],
        [AppboySession getTwitterAccessToken],
        [AppboySession getTwitterAccessSecret]);
}

@synthesize appboyButton;
@synthesize appboyButtonPortrait;
@synthesize appboyFeedbackButton;
@synthesize appboyFeedbackButtonPortrait;
@synthesize appboyExploreButton;
@synthesize appboyExploreButtonPortrait;
@synthesize shareButton;
@synthesize titleLabel;
@synthesize loginWithFacebookButton;
@synthesize logoutWithFacebookButton;

- (IBAction)toAppboyNews:(id)sender {
  [AppboySession displayNews];   
}

- (IBAction)toAppboyFeedback:(id)sender {
  [AppboySession displayFeedback];
}

- (IBAction)toAppboyExplore:(id)sender {
  [AppboySession displayExplore];
}


- (IBAction)loginWithFacebook:(id)sender {
  [[self getDelegate] loginWithFacebook];
}

- (IBAction)logoutWithFacebook:(id) sender {
  [[self getDelegate].facebook logout];
}

- (ABSAppDelegate *) getDelegate {
  return (ABSAppDelegate *)[[UIApplication sharedApplication] delegate]; 
}

- (IBAction)shareContent:(id)sender {
  [AppboySession shareMessage:@"I just finished using the Appboy Sample iOS App!" imageUrlString:@"http://a0.twimg.com/profile_images/1880187671/avatar_reasonably_small.jpg"];
}

@end
