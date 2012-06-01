//
//  AppboySession.h
//  AppboySDK
//
//  Created by Rob Haydt on 8/18/11.
//  Copyright 2011 appboy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


enum kApppboyDisplayControl {
  kAppboyDisplayPrompt=1,           // Allow Appboy to flow the bubble prompt
  kAppboyDisplayStartNewSession=2,  // Appboy will record a new session and can prompt
  kAppboyDisplayView=4              // Transfer control to Appboy
} ;

@interface AppboySession : NSObject;

/*!
 * @method sessionWithApiKey:usingDelegate:
 * @discussion start the SDK and try to create a new session
 * @param apikey for the app
 * @param delegate optional AppboySessionDelegate
 * @return YES if started; NO if unavailable
 */
+ (BOOL) sessionWithApiKey:(NSString *)apikey usingDelegate:(id)delegate; 

/*!
 * @method displayAppboy:
 * @discussion display the Appboy UI
 * @return NO if appboy is unavailable
 */
+ (BOOL) displayAppboy;

+ (BOOL) registerPushToken:(NSString *) token;

/*!
 * @method shareMessage:[imageUrlString]
 * @discussion display the shared page for the message image
 * @param message string to share on social network
 * @param imagePath optional image URL string
 * @return NO if appboy is unavailable
 */
+ (BOOL) shareMessage:(NSString *)message;
+ (BOOL) shareMessage:(NSString *)message imageUrlString:(NSString *)imagePath;

/*!
 * @method displayFeedback
 * @discussion try to display the Appboy feedback section
 * return NO if Appboy unavailable or already displayed
 */
+ (BOOL) displayFeedback;

/*!
 * @method displayNews
 * @discussion try to display the Appboy news and alerts section
 * return NO if Appboy unavailable or already displayed
 */
+ (BOOL) displayNews;

/*!
 * @method displayExplore
 * @discussion try to display the Appboy Explore section
 * return NO if Appboy unavailable or already displayed
 */
+ (BOOL) displayExplore;

/*!
 * @method displayOverview
 * @discussion try to display the Appboy overview section
 * return NO if Appboy unavailable or already displayed
 */
+ (BOOL) displayOverview;

/*!
 * @method isReady
 * @discussion test whether the session is connected to the Appboy Servers
 * @return YES/NO
 */
+ (BOOL) isReady;     // the Appboy Session is ready (and can be displayed)

/*!
 * @method isDisplayed
 * @discussion test whether the Appboy UI is being displayed
 * @return YES/NO
 */
+ (BOOL) isDisplayed; // the Appboy Session is displayed (appboy is in control)


+ (void) setFacebookAccessToken:(NSString *)accessToken expiration:(NSDate *)expiresAt;
+ (void) setTwitterAccessToken:(NSString *)accessToken secret:(NSString *)secret;
+ (NSString *) getFacebookAccessToken;
+ (NSDate *) getFacebookAccessExpiration;
+ (NSString *) getTwitterAccessToken;
+ (NSString *) getTwitterAccessSecret;


@end

@protocol AppboySessionDelegate 
@optional
/*!
 * @method AppboyDelegateStatusChange
 * @discussion notify the App that Appboy's Server Connection has changed
 */
- (void) AppboyDelegateStatusChange;

/*!
 * @method AppboyDelegateShouldDisplaySlideup
 * @discussion ask the App whether the slide should be displayed
 * @param slideupContext a dictionary of information describing the slideup
 * @return YES/NO for Appboy to display the slideUp
 */
- (BOOL) AppboyDelegateShouldDisplaySlideup:(NSDictionary *)slideupContext;

// Keywords in the slideupContext dictionary

// objectForKey:kAppboySlideupContextKey - the NSString displayed in the slideup 
#define kAppboySlideupKeyMessage @"message"

@end
