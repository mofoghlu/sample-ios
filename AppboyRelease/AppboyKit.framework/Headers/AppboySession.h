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
+ (BOOL) sessionWithApiKey:(NSString *)apikey 
         usingDelegate:(id)delegate; 

/*!
 * @method displayWith:
 * @discussion display the Appboy UI
 * @param control whether to create a new session
 * @return NO if appboy is unavailable
 */
+ (BOOL) displayWith:(NSInteger)control;
+ (BOOL) displayAppboy;             // becomes displayWith:kAppboyDisplayView


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
 * @method enableAccountWithApiKey:usingDelegate:
 * @discussion reenable the SDK if it's been disabled
 * @param apikey for the app
 * @param delegate optional AppboySessionDelegate
 * @return YES if started; NO if unavailable
 */
+ (BOOL) enableAccountWithApiKey:(NSString *)apikey 
             usingDelegate:(id)delegate;

/*!
 * @method isEnabled
 * @discussion test whether the Appboy SDK is enabled
 * @return YES/NO
 */
+ (BOOL) isEnabled;   // appboy has not been disabled by the user

/*!
 * @method isStarted
 * @discussion test whether sessionWithApiKey has been invoked
 * @return YES/NO
 */
+ (BOOL) isStarted;   // the Appboy library has been invoked

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

/*!
 * @method hasConnectivity
 * @discussion test whether the network is available for connection to Appboy
 * @return YES/NO
 */
+ (BOOL) hasConnectivity; // there is internet connectivity

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
