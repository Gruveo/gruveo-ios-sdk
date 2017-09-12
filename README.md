# GruveoSDK
GruveoSDK framework and sample project

## Installation with CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like GruveoSDK in your projects. 
You can install it with the following command:

```bash
$ gem install cocoapods
```

#### Podfile

To integrate GruveoSDK into your Xcode project using CocoaPods, specify it in your `Podfile`:

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

# How to setup without CocoaPods:

1. Create a single view application
2. Add GruveoSDK.framework and WebRTC.framework to project’s “Embedded Binaries”: “+” -> “Add Other…” -> select framework and press “Open” -> “Finish”. It should appear in both “Embedded Binaries” and “Linked Frameworks and Libraries”
3. Add NSCameraUsageDescription and NSMicrophoneUsageDescription to the Info.plist
4. Set Enable Bitcode value to NO in “Target -> Build Settings -> Enable Bitcode”
5. Import GruveoPublicSDK to AppDelegate and your ViewController class
```objective-c
@import GruveoPublicSDK;
```
6. Register you clientId after application startup: 
```objective-c
`[GruveoCallManager setClientId:@"demo”]` 
```
7. Set delegate for GruveoCallManager in viewDidLoad function
```objective-c
[GruveoCallManager setDelegate:self]
```
8. Implement call creation:
```objective-c
[GruveoCallManager callCode:@"hello" videoCall:YES onViewController:self callCreationCompletion:^(CallInitError creationError) {
if (creationError != CallInitErrorNone) {
// show error here
}
}];
```
9. Implement delegate functions:
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
- (void)callEstablished {}
- (void)callEnd:(GruveoCallEndReason)reason {}
- (void)recordingStateChanged {}
```
10. Build and run
