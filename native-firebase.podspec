Pod::Spec.new do |spec|
  spec.name         = "native-firebase"
  spec.version      = "0.0.1"
  spec.summary      = "Holder of base firebase xcframework"
  spec.description  = <<-DESC
  Holder of base firebase xcframework
  This is in turn used by other firebase extensions
                        DESC
  spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  spec.platform     = :ios
  spec.ios.deployment_target = "12.0"
  spec.source       = { :git => "https://github.com/G-E-E-B-S/firebase-app-wrapper", :tag => "#{spec.version}" }
  spec.module_name = "native_firebase"
  spec.source_files  = ["cpp/*.cpp"]
  spec.static_framework = true
  spec.pod_target_xcconfig = {
    "HEADER_SEARCH_PATHS" => '${inherited} '+
    '"${PODS_TARGET_SRCROOT}/external/includes" ',
    "USER_HEADER_SEARCH_PATHS" => '${inherited} '+
    '"${PODS_TARGET_SRCROOT}" ' +
    '"${PODS_TARGET_SRCROOT}"/external/includes/firebase ' +
    '"${PODS_TARGET_SRCROOT}/../jsb-helper" '
  }
end
