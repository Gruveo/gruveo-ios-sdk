# Gruveo SDK for iOS
The Gruveo SDK for iOS  and a sample project.

## Pod Installation

To add the Gruveo SDK for iOS to your app, you will need [CocoaPods](http://cocoapods.org), which is a dependency manager for Objective-C. You can install CocoaPods with the following command:

```bash
$ gem install cocoapods
```

### Podfile

To integrate the Gruveo SDK into your Xcode project using CocoaPods, add the `GruveoSDK` pod to your `Podfile`:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '9.0'

target 'TargetName' do
pod 'GruveoSDK'
end
```

Then, run the following command:

```bash
$ pod install
```

## Application Setup and Usage

1. Add `NSCameraUsageDescription` and `NSMicrophoneUsageDescription` to your application's Info.plist
2. Set “Enable Bitcode” to NO in Target -> Build Settings -> Enable Bitcode
3. Check the "Audio, AirPlay, and Picture in Picture" checkbox under Capabilities -> Background Modes
4. Import `GruveoSDK` to the `AppDelegate` and your `ViewController` class:
```objective-c
@import GruveoSDK;
```
5. Register your [сlient ID](https://about.gruveo.com/developers/api-credentials/) after application startup: 
```objective-c
[GruveoCallManager setClientId:@"demo”]
```
6. Set delegate for `GruveoCallManager` in the `viewDidLoad` function:
```objective-c
[GruveoCallManager setDelegate:self]
```
7. Implement creation of the Gruveo call screen:
```objective-c
[GruveoCallManager callCode:@"hello" videoCall:YES onViewController:self callCreationCompletion:^(CallInitError creationError) {
    if (creationError != CallInitErrorNone) {
        // Show error here
    }
}];
```
8. Implement the delegate function for token signing. **Warning**: The sample implementation below uses a signing endpoint provided by Gruveo and will only work for the `demo` client ID:
```objective-c
- (void)requestToSignApiAuthToken:(NSString *)token {
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"https://api-demo.gruveo.com/signer"]];
    [request setHTTPMethod:@"POST"];
    [request setValue:@"text/plain" forHTTPHeaderField:@"Content-Type"];
    [request setHTTPBody:[token dataUsingEncoding:NSUTF8StringEncoding]];

    NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:configuration delegate:nil delegateQueue:nil];

    [[session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if ([data isKindOfClass:[NSData class]]) {
            NSString *signedToken = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            [GruveoCallManager authorize:signedToken];
        } else {
            [GruveoCallManager authorize:nil];
        }
    }] resume];
}
```
9. Implement the other useful delegate functions:
```objective-c
- (void)callEstablished {}
- (void)callEnd:(GruveoCallEndReason)reason {}
- (void)recordingStateChanged {}
```
10. Build and run your application.
