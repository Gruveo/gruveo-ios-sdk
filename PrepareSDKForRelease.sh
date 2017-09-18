'use strict';

const exec = require('child_process').execSync;

const ARCH_TYPES = ['x86_64','armv7','arm64'];

const WEBRTC_BIN_PATH = `${__dirname}/Example/GruveoSampleApp/WebRTC.framework`;

console.log(`Extracting WebRTC...`);
ARCH_TYPES.forEach(elm => {
exec(`lipo -extract ${elm} WebRTC -o WebRTC-${elm}`,{cwd:WEBRTC_BIN_PATH});
});
exec('cp WebRTC WebRTC-all',{cwd:WEBRTC_BIN_PATH});
console.log(exec('ls -ahl | grep WebRTC-',{cwd:WEBRTC_BIN_PATH}).toString().trim());
console.log('Done!');

console.log(`Cutting WebRTC for device...`);
exec(`lipo -o WebRTC -create WebRTC-armv7 WebRTC-arm64`,{cwd:WEBRTC_BIN_PATH});
console.log(exec('ls -ahl | grep WebRTC',{cwd:WEBRTC_BIN_PATH}).toString().trim());
console.log('Done!');

const GruveoSDK_BIN_PATH = `${__dirname}/GruveoSDK/GruveoPublicSDK.framework`;

console.log(`Extracting GruveoPublicSDK...`);
ARCH_TYPES.forEach(elm => {
exec(`lipo -extract ${elm} GruveoPublicSDK -o GruveoPublicSDK-${elm}`,{cwd:GruveoSDK_BIN_PATH});
});
exec('cp GruveoPublicSDK GruveoPublicSDK-all',{cwd:GruveoSDK_BIN_PATH});
console.log(exec('ls -ahl | grep GruveoPublicSDK-',{cwd:GruveoSDK_BIN_PATH}).toString().trim());
console.log('Done!');

console.log(`Cutting GruveoPublicSDK for device...`);
exec(`lipo -o GruveoPublicSDK -create GruveoPublicSDK-armv7 GruveoPublicSDK-arm64`,{cwd:GruveoSDK_BIN_PATH});
console.log(exec('ls -ahl | grep GruveoPublicSDK',{cwd:GruveoSDK_BIN_PATH}).toString().trim());
console.log('Done!');
