//
//  GruveoCallManager.h
//  GruveoSDK
//
//  Created by Max Gurkivskyi on 8/17/17.
//  Copyright © 2017 Gruveo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GruveoSDK/CallInitError.h>
#import <GruveoSDK/GruveoCallRecordingStatus.h>

@class UIViewController;

typedef NS_ENUM(NSUInteger, GruveoCallEndReason) {
    GruveoCallEndReasonInvalidCredentials = 0,        // Invalid token signature provided
    GruveoCallEndReasonInternalError,                 // Internal error when creating call
    GruveoCallEndReasonOutdatedProtocolVersion,       // Outdated SDK version
    GruveoCallEndReasonBusy,                          // Call room is locked
    GruveoCallEndReasonHandleUnreachable,             // Callee is unreachable
    GruveoCallEndReasonHandleBusy,                    // Callee is busy with another call
    GruveoCallEndReasonHandleNonExist,                // Gruveo handle doesn't exist
    GruveoCallEndReasonFreeDemoEnded,                 // The 5-minute call limit has been reached (when using the demo client ID)
    GruveoCallEndReasonRoomLimitReached,              // Room limit of 8 participants has been reached
    GruveoCallEndReasonNoConnection,                  // Lost connection
    GruveoCallEndReasonUser,                          // Call ended normally from UI
    GruveoCallEndReasonOtherParty                     // Call ended normally by other party
};

typedef NS_ENUM(NSUInteger, GruveoCallRecordingLayout) {
    GruveoCallRecordingLayoutTiled = 0,
    GruveoCallRecordingLayoutMaximized
};

@protocol GruveoCallManagerDelegate <NSObject>

/**
 * This method is called when the SDK requests you to sign a random token as part the SDK authentication scheme. The token parameter contains the token value to sign. Please see Authentication for details. https://about.gruveo.com/developers/ios-sdk/authentication/
 */
- (void)requestToSignApiAuthToken:(NSString *)token;

/**
 * Called once a call between at least 2 participants is established.
 */
- (void)callEstablished;

/**
 * This method is called when the call ends.
 *
 * @param reason Reason why the call ended. See the CallEndReason enum.
 */
- (void)callEnd:(GruveoCallEndReason)reason;

/**
 * This method is called whenever the call recording state changes, e.g. one of the call participants starts or stops call recording.
 */
- (void)recordingStateChanged;

/**
 * Returns filename of new recording output file.
 */
- (void)recordingFilename:(NSString *)filename;

@end

@interface GruveoCallManager : NSObject

/**
 * Setups GruveoCallManager with a specific clientID.
 *
 * @param clientID Your client ID that you get as part of your API credentials: https://about.gruveo.com/developers/api-credentials/
 * @warning Needs to be called in AppDelegate's didFinishLaunchingWithOptions method.
 */
+ (void)setClientId:(NSString *)clientID;

/**
 * Initializes a new call and shows it on your view controller.
 *
 * @param code The room name to join or the Gruveo @handle to call.
 * @param video Whether local camera should be enabled or not.
 * @param chat Whether to enable the text chat.
 * @param viewController Source view controller.
 * @param callCreationCompletionBlock Called after the call is initialized. Passes CallInitErrorNone on success or an error value. See the CallInitError enum for the possible errors.
 */
+ (void)callCode:(NSString *)code videoCall:(BOOL)video textChat:(BOOL)chat onViewController:(UIViewController *)viewController callCreationCompletion:(void(^)(CallInitError creationError))callCreationCompletionBlock;

/**
 * Initializes a new call and returns the call view controller to show.
 *
 * @param code The room name to join or the Gruveo @handle to call.
 * @param video Whether local camera should be enabled or not.
 * @param chat Whether to enable the text chat.
 * @param callCreationCompletionBlock Called after the call is initialized. Passes CallInitErrorNone on success or an error value, as well as the UIViewController that need to be presented. See the CallInitError enum for the possible errors.
 */
+ (void)callCode:(NSString *)code videoCall:(BOOL)video textChat:(BOOL)chat callCreationCompletion:(void(^)(CallInitError creationError, UIViewController *callViewController))callCreationCompletionBlock;

/**
 * Sets the delegate for the GruveoCallManagerDelegate events.
 *
 * @param delegate A pointer to the object that conforms to the GruveoCallManagerDelegate protocol.
 */
+ (void)setDelegate:(id <GruveoCallManagerDelegate>)delegate;

/**
 * Supplies the token signature to the SDK. See Authentication for details: https://about.gruveo.com/developers/ios-sdk/authentication/
 *
 * @param token The token string.
 */
+ (void)authorize:(NSString *)token;

/**
 * Ends the current call.
 *
 */
+ (void)endCall;

/**
 * Returns a boolean indicating if there is an ongoing established call.
 *
 */
+ (BOOL)isCallActive;

/**
 * Sets the microphone status.
 *
 * @param enable Whether to enable the microphone.
 */
+ (void)toggleAudio:(BOOL)enable;

/**
 * Sets the camera status.
 *
 * @param enable Whether to enable the camera.
 */
+ (void)toggleVideo:(BOOL)enable;

/**
 * Sets the source for the outgoing video stream.
 *
 * @param useFront Whether to use the front (YES) or back (NO) camera.
 */
+ (void)switchCamera:(BOOL)useFront;

/**
 * Sets the room lock state.
 *
 * @param enable Set to YES to lock the room or to NO to unlock it.
 */
+ (void)toggleRoomLock:(BOOL)enable;

/**
 * Starts or stops call recording. With layout parameter GruveoCallRecordingLayoutMaximized.
 *
 * @param enable Set to YES to start recording or to NO to stop it.
 */
+ (void)toggleRecording:(BOOL)enable;

/**
 * Starts or stops call recording.
 *
 * @param enable Set to YES to start recording or to NO to stop it.
 * @param layout Set to GruveoCallRecordingLayout to select recording layout.
 */
+ (void)toggleRecording:(BOOL)enable withLayout:(GruveoCallRecordingLayout)layout;

/**
 * Returns a random code for room name.
 *
 *
 */
+ (NSString *)generateRandomCode;

@end
