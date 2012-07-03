//
//  AppboySession.h
//  AppboySDK
//
//  Created by Rob Haydt on 8/18/11.
//  Copyright 2011, 2012 Appboy, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


enum kAppboyDisplayControl {
  kAppboyDisplayPrompt = 1,           // Allow Appboy to flow the bubble prompt
  kAppboyDisplayStartNewSession = 2,  // Appboy will record a new session and can prompt
  kAppboyDisplayView=4              // Transfer control to Appboy
};

@interface AppboySession : NSObject;

/*!
 * @method sessionWithApiKey:usingDelegate:
 * @discussion This method tells Appboy to start a new session for this {device, app} pair.
 * @param apikey The API key for your app. You can find this on www.appboy.com in the "Settings" section for your app.
 * @param delegate The delegate that implements AppboySessionDelegate.
 * @return YES if Appboy was able to start a new session; NO if unsuccessful.
 */
+ (BOOL) sessionWithApiKey:(NSString *)apikey usingDelegate:(id)delegate; 

/*!
 * @method displayAppboy:
 * @discussion Displays the Appboy user interface. This method will display whatever tab or section the user last
 *   visited.
 * @return YES or NO on success.
 */
+ (BOOL) displayAppboy;

/*!
 * @method registerPushToken:token:
 * @discussion This method posts a token to Appboy's servers to associate with the current device.
 * @param token Device token that you would receive in the didRegisterForRemoteNotificationsWithDeviceToken delegate.
 * @return YES or NO on success.
 */
+ (BOOL) registerPushToken:(NSString *) token;

/*!
 * @method shareMessage:[imageUrlString]
 * @discussion Prompts the user to post a message to Facebook and Twitter.
 * @param message The string which will pre-populate the textbox containing the message to share on a user's
 *   social networks.
 * @param imagePath Optionally provide an image URL string to be used alongside the share. If the user shares on
 *   Facebook, this image will be displayed alongside the share message.
 * @return YES or NO on success.
 */
+ (BOOL) shareMessage:(NSString *)message;
+ (BOOL) shareMessage:(NSString *)message imageUrlString:(NSString *)imagePath;

/*!
 * @method displayFeedback
 * @discussion Opens the Appboy user interface and takes the user to the Feedback section.
 * @return YES on success; NO if Appboy is already displayed.
 */
+ (BOOL) displayFeedback;

/*!
 * @method displayNews
 * @discussion Displays the News Section in Appboy.
 * @return YES on success; NO if Appboy is already displayed.
 */
+ (BOOL) displayNews;

/*!
 * @method displayExplore
 * @discussion Displays the Explore tab in Appboy.
 * @return YES on success; NO if Appboy is already displayed.
 */
+ (BOOL) displayExplore;

/*!
 * @method displayOverview
 * @discussion Displays the Overview tab in Appboy.
 * @return YES on success; NO if Appboy is already displayed.
 */
+ (BOOL) displayOverview;

/*!
 * @method isReady
 * @discussion This method is used to indicate that Appboy is available and refreshed with the latest information
 *   from the Appboy servers. Note that a return value of NO does not mean that Appboy cannot be displayed to the user.
 * @return YES if Appboy has the latest information from the Appboy servers, NO otherwise.
 */
+ (BOOL) isReady;

/*!
 * @method isDisplayed
 * @discussion Indicates whether or not the Appboy user interface is currently displayed and Appboy is in control of
 *   the view.
 * @return YES if Appboy is displayed, NO otherwise.
 */
+ (BOOL) isDisplayed;

/*!
 * @method setFacebookAccessToken:expiration:
 * @discussion This method passes Facebook OAuth token information for the current user to Appboy. For examples
 *   of why you want to do this and how to configure your app in the Appboy Dashboard, refer to
 *   https://www.appboy.com/documentation.
 * @param accessToken The OAuth token for the user you receive from Facebook. Refer to the Facebook SDK documentation
 *   at https://developers.facebook.com/docs/reference/iossdk/authentication/ for information about how to retrieve
 *   this value. Typically this can be retrieved through a call to [facebook accessToken].
 * @param expiration The date at which the OAuth access token expires. Refer to the Facebook SDK documentation for
 *   information about how to retrieve this value.  Typically this can be retrieved through a call to
 *   [facebook expirationDate].
 * @return YES if the SDK posts this information to Appboy's servers successfully; NO otherwise.
 */
+ (BOOL) setFacebookAccessToken:(NSString *)accessToken expiration:(NSDate *)expiresAt;

/*!
 * @method setTwitterAccessToken:secret:
 * @discussion This method passes Twitter OAuth token information for the current user to Appboy. For examples
 *   of why you want to do this and how to configure your app in the Appboy Dashboard, refer to
 *   https://www.appboy.com/documentation.
 * @param accessToken The OAuth token for the user you receive from Twitter. Refer to the Twitter SDK documentation
 *   at https://dev.twitter.com/docs/auth/obtaining-access-tokens for information about how to retrieve
 *   this value.
 * @param secret The OAuth secret for the user you receive from Twitter. Refer to the Twitter SDK documentation
 *   at https://dev.twitter.com/docs/auth/obtaining-access-tokens for information about how to retrieve
 *   this value.
 * @return YES if the SDK posts this information to Appboy's servers successfully; NO otherwise.
 */
+ (BOOL) setTwitterAccessToken:(NSString *)accessToken secret:(NSString *)secret;

/*!
 * @method setFoursquareAccessToken:secret:
 * @discussion This method passes Foursquare OAuth token information for the current user to Appboy. For examples
 *   of why you want to do this, refer to https://www.appboy.com/documentation.
 * @param accessToken The OAuth token for the user you receive from Foursquare. Refer to the Foursquare SDK
 *   documentation at https://developer.foursquare.com/overview/auth for information about how
 *   to retrieve this value.
 * @return YES if the SDK posts this information to Appboy's servers successfully; NO otherwise.
 */
+ (BOOL) setFoursquareAccessToken:(NSString *)accessToken;

/*!
* @method setFirstName:lastName:andEmail:
* @discussion This method passes user identifiable information for the current user to Appboy. For examples
*   of why you want to do this, refer to https://www.appboy.com/documentation.
* @param firstName The user's first name you want to record in the user's profile.
* @param lastName The user's last name you want to record in the user's profile.
* @param andEmail The email address of the user to record in the user's profile.
* @return YES if the SDK posts this information to Appboy's servers successfully; NO otherwise.
*/
+ (BOOL) setFirstName:(NSString *)firstName lastName:(NSString *)lastName andEmail:(NSString *)email;

/*!
* @method setEmail:email:
* @discussion This method passes user identifiable information for the current user to Appboy. For examples
*   of why you want to do this, refer to https://www.appboy.com/documentation.
* @param email The email address of the user to record in the user's profile.
* @return YES if the SDK posts this information to Appboy's servers successfully; NO otherwise.
*/
+ (BOOL) setEmail:(NSString *)email;

/*!
* @method getFacebookAccessToken:
* @discussion Returns the Facebook OAuth token for the current user that Appboy after the user has
*   authenticated inside the Appboy user interface (e.g., links his Facebook account to his profile). This value will
*   only be available if you have configured your Facebook app information on your app's settings page on the Appboy
*   Dashboard. If it is not configured, this method will not return anything. Typically you will want to call this
*   method from the AppboyDelegateAccountStatus delegate, which is called after a user successfully authenticates.
* @return The Facebook OAuth token for the current user after an authentication inside the Appboy user interface.
*/
+ (NSString *) getFacebookAccessToken;

/*!
* @method getFacebookAccessExpiration:
* @discussion Returns the Facebook OAuth token expiration date for the current user that Appboy after the user has
*   authenticated inside the Appboy user interface (e.g., links his Facebook account to his profile). This value will
*   only be available if you have configured your Facebook app information on your app's settings page on the Appboy
*   Dashboard. If it is not configured, this method will not return anything. Typically you will want to call this
*   method from the AppboyDelegateAccountStatus delegate, which is called after a user successfully authenticates.
* @return The Facebook OAuth token expiration date for the current user after an authentication inside the Appboy
*   user interface.
*/
+ (NSDate *) getFacebookAccessExpiration;

/*!
* @method getTwitterAccessToken:
* @discussion Returns the Twitter OAuth token for the current user that Appboy after the user has
*   authenticated inside the Appboy user interface (e.g., links his Twitter account to his profile). This value will
*   only be available if you have configured your Twitter app information on your app's settings page on the Appboy
*   Dashboard. If it is not configured, this method will not return anything. Typically you will want to call this
*   method from the AppboyDelegateAccountStatus delegate, which is called after a user successfully authenticates.
* @return The Twitter OAuth token for the current user after an authentication inside the Appboy user interface.
*/
+ (NSString *) getTwitterAccessToken;

/*!
* @method getTwitterAccessSecret:
* @discussion Returns the Twitter OAuth secret for the current user that Appboy after the user has
*   authenticated inside the Appboy user interface (e.g., links his Twitter account to his profile). This value will
*   only be available if you have configured your Twitter app information on your app's settings page on the Appboy
*   Dashboard. If it is not configured, this method will not return anything. Typically you will want to call this
*   method from the AppboyDelegateAccountStatus delegate, which is called after a user successfully authenticates.
* @return The Twitter OAuth secret for the current user after an authentication inside the Appboy user interface.
*/
+ (NSString *) getTwitterAccessSecret;
@end

@protocol AppboySessionDelegate 
@optional
/*!
 * @method AppboyDelegateStatusChange
 * @discussion This delegate is notified when [AppboySession isReady] changes from false to true. An example use case is
 *   that you could use this delegate to create custom loading pages until Appboy has finished loading when your app
 *   starts up.
 */
- (void) AppboyDelegateStatusChange;

/*!
 * @method AppboyDelegateAccountStatus
 * @discussion This delegate is notified after a user has successfully authenticated to a social network inside the
 *   Appboy user interface. It will only be triggered if you have Facebook and Twitter app information configured on
 *   your app's settings page. If this is not configured, the delegate will not be invoked.
 *
 *   As for timing, this delegate will be called when the user hits the Close button to exit out of Appboy and return
 *   to your application.
 */
- (void) AppboyDelegateAccountStatus;

/*!
 * @method AppboyDelegateShouldDisplaySlideup
 * @discussion Appboy sometimes slides up notifications to alert the user to new content. This delegate allows you to
 *   control whether or not the slideup is shown if Appboy has a message to display in it. This delegate is only called
 *   if Appboy has a message to display in the slideup.
 * @param slideupContext A dictionary of information describing the slideup. The main value you might want to inspect is
 *   the objectForKey:kAppboySlideupKeyMessage, which contains the message of the slideup.
 * @return You should return YES or NO in this delegate. When NO, Appboy will not display the slideup. When YES, the
 *   slideup will be displayed.
 */
- (BOOL) AppboyDelegateShouldDisplaySlideup:(NSDictionary *)slideupContext;

/*!
 * Keywords to be used in the AppboyDelegateShouldDisplaySlideup:slideupContext dictionary.
 */

/*!
 * objectForKey:kAppboySlideupKeyMessage contains the message of the slideup.
 */
#define kAppboySlideupKeyMessage @"message"

@end
