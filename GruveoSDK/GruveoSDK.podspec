Pod::Spec.new do |s|
  s.name         = "GruveoSDK"
  s.version      = "1.0"
  s.summary      = "GruveoSDK is framework to make call using Gruveo API"

  s.homepage     = "http://www.gruveo.com"
  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author             = { "Gruveo" => "max.gurkivskyi@gmail.com" }

  s.platform     = :ios, "9.0"

# s.source       = { :git => "http://EXAMPLE/GruveoSDK.git", :tag => "#{s.version}" }
  s.source       = { :path => '.' }

  # s.frameworks = "SomeFramework", "AnotherFramework"

  s.dependency "GoogleWebRTC", "~> 1.0.136171"

  s.vendored_frameworks = 'GruveoPublicSDK.framework'

end
