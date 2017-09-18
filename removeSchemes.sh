echo "Extracting WebRTC..."

# readonly WEBRTCPATH="./Example/GruveoSampleApp/WebRTC.framework"

lipo -extract armv7 Example/GruveoSampleApp/WebRTC.framework/WebRTC -o WebRTC-armv7
lipo -extract arm64 Example/GruveoSampleApp/WebRTC.framework/WebRTC -o WebRTC-arm64

echo "Packing WebRTC..."
lipo -o WebRTC -create WebRTC-armv7 WebRTC-arm64

rm Example/GruveoSampleApp/WebRTC.framework/WebRTC
cp WebRTC Example/GruveoSampleApp/WebRTC.framework
rm WebRTC-armv7
rm WebRTC-arm64
rm WebRTC

echo "Extracting GruveoSDK..."

# readonly GruveoSDKPATH="./GruveoSDK/GruveoPublicSDK.framework/GruveoPublicSDK"

lipo -extract armv7 GruveoSDK/GruveoPublicSDK.framework/GruveoPublicSDK -o GruveoPublicSDK-armv7
lipo -extract arm64 GruveoSDK/GruveoPublicSDK.framework/GruveoPublicSDK -o GruveoPublicSDK-arm64

echo "Packing GruveoSDK..."
lipo -o GruveoPublicSDK -create GruveoPublicSDK-armv7 GruveoPublicSDK-arm64

rm GruveoSDK/GruveoPublicSDK.framework/GruveoPublicSDK
cp GruveoPublicSDK GruveoSDK/GruveoPublicSDK.framework
rm GruveoPublicSDK-armv7
rm GruveoPublicSDK-arm64
rm GruveoPublicSDK
