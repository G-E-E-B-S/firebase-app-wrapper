#include "includes/firebase_app.h"
#ifdef IS_ANDROID
#if CC_VERSION_3_X
#include "platform/java/jni/JniHelper.h"
using namespace cc;
#else
#include "platform/android/jni/JniHelper.h"
using namespace cocos2d;
#endif
#endif

#include <firebase/app.h>

namespace wrapper
{

    FirebaseApp::FirebaseApp()
    {
#ifdef IS_ANDROID
        _app = firebase::App::Create(firebase::AppOptions(),
                                     JniHelper::getEnv(),
                                     JniHelper::getActivity());
#else
        _app = ::firebase::App::Create(::firebase::AppOptions());
#endif
    }

    firebase::App *FirebaseApp::getApp()
    {
        return _app;
    }

}
