#pragma once

#include "include/firebase_app_getter.h"

namespace wrapper
{
    class FirebaseApp: public wrapper::jsbhelper::IFirebaseAppGetter
    {
    public:
            FirebaseApp();
            virtual ~FirebaseApp() {};
            virtual firebase::App* getApp() override;
    private:
        firebase::App* _app;
    };
}