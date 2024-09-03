// clang-format off
#pragma once

#include <type_traits>
#include "cocos/bindings/jswrapper/SeApi.h"
#include "cocos/bindings/manual/jsb_conversions.h"
#include "includes/firebase_app.h"

bool register_all_firebase(se::Object *obj);                   // NOLINT

JSB_REGISTER_OBJECT_TYPE(wrapper::FirebaseApp);


extern se::Object *__jsb_wrapper_FirebaseApp_proto;   // NOLINT
extern se::Class *__jsb_wrapper_FirebaseApp_class;    // NOLINT

bool js_register_wrapper_FirebaseApp(se::Object *obj); // NOLINT

SE_DECLARE_FUNC(js_firebase_FirebaseApp_FirebaseApp);
// clang-format on
