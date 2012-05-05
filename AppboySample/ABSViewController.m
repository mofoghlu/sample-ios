//
//  ABSViewController.m
//  AppboySample
//
//  Created by Jonathan Hyman on 5/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ABSViewController.h"
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

@synthesize appboyButton;
- (IBAction)toAppboy:(id)sender {
    if ([AppboySession isReady]) {
        [AppboySession displayWith:kAppboyDisplayView];
    }
    else {
        // If Appboy is not ready, it could be unavailable due to no internet connectivity,
        // or it could still be loading. Customize this portion of the code to take whatever action you want.
        NSString *message = @"Appboy is currently loading. Please try again in a moment.";
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle: nil message: message delegate: nil
                                              cancelButtonTitle: @"OK" otherButtonTitles: nil];
        [alert show];
        [alert release];
    }
}

@synthesize shareButton;
- (IBAction)shareContent:(id)sender {
    if ([AppboySession isReady]) {
        [AppboySession shareMessage:@"I just finished using the Appboy Sample iOS App!" imageUrlString:@"http://a0.twimg.com/profile_images/1880187671/avatar_reasonably_small.jpg"];
    }
    else {
        // If Appboy is not ready, it could be unavailable due to no internet connectivity,
        // or it could still be loading. Customize this portion of the code to take whatever action you want.
        NSString *message = @"Appboy is currently loading. Please try again in a moment.";
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle: nil message: message delegate: nil
                                              cancelButtonTitle: @"OK" otherButtonTitles: nil];
        [alert show];
        [alert release];
    }
}

@end
