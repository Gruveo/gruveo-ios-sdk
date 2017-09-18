Pod::Spec.new do |s|
  s.name         = "GruveoSDK"

  s.version      = "1.0"

  s.summary      = "GruveoSDK is framework to make call using Gruveo API"
  
  s.description  = "The Gruveo SDK for iOS lets you quickly and easily add a white-label screen with a video calling UI to your iOS app. It is the ready-to-use solution you need to add video and voice calling to your iOS app in minutes."
  
  s.homepage     = "https://github.com/Gruveo/gruveo-ios-sdk"

  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author       = { "Gruveo" => "art@gruveo.com" }

  s.platform     = :ios, "9.0"

  s.source       = { :git => "https://github.com/Gruveo/gruveo-ios-sdk.git", :tag => "#{s.version}" }

  s.dependency "GoogleWebRTC", "~> 1.0.136171"

  s.vendored_frameworks = 'GruveoSDK/GruveoPublicSDK.framework'

end
