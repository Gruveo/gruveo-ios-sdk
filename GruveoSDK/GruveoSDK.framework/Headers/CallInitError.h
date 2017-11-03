//
//  CallInitError.h
//  GruveoSDK
//
//  Created by Max Gurkivskyi on 8/29/17.
//  Copyright © 2017 Gruveo. All rights reserved.
//

typedef NS_ENUM(NSUInteger, CallInitError) {
    CallInitErrorNone = 0,              // Сall created successfully
    CallInitErrorCodeCallExist,         // Curretn call not ended
    CallInitErrorMissingClientID,       // The clientId value hasn't been set
    CallInitErrorInvalidCode,           // The code value contains invalid characters
    CallInitErrorNetworkUnreachable,    // The device is offline
    CallInitErrorMicrophoneAccessDenied // Microphone access denied by user
};
