
// clang-format off
#include "bindings/auto/3.x.x_3.6.x/jsb_native_firebase_auto.h"
#include "cocos/bindings/manual/jsb_conversions.h"
#include "cocos/bindings/manual/jsb_global.h"
#include "includes/firebase_app.h"

#ifndef JSB_ALLOC
#define JSB_ALLOC(kls, ...) new (std::nothrow) kls(__VA_ARGS__)
#endif

#ifndef JSB_FREE
#define JSB_FREE(ptr) delete ptr
#endif

#if CC_DEBUG
static bool js_firebase_getter_return_true(se::State& s) // NOLINT(readability-identifier-naming)
{
    s.rval().setBoolean(true);
    return true;
}
SE_BIND_PROP_GET(js_firebase_getter_return_true)
#endif
se::Object* __jsb_wrapper_FirebaseApp_proto = nullptr; // NOLINT
se::Class* __jsb_wrapper_FirebaseApp_class = nullptr;  // NOLINT

SE_DECLARE_FINALIZE_FUNC(js_wrapper_FirebaseApp_finalize)

static bool js_firebase_FirebaseApp_constructor(se::State& s) // NOLINT(readability-identifier-naming) constructor.c
{
    auto *ptr = JSB_MAKE_PRIVATE_OBJECT(wrapper::FirebaseApp);
    s.thisObject()->setPrivateObject(ptr);
    return true;
}
SE_BIND_CTOR(js_firebase_FirebaseApp_constructor, __jsb_wrapper_FirebaseApp_class, js_wrapper_FirebaseApp_finalize)

static bool js_wrapper_FirebaseApp_finalize(se::State& s) // NOLINT(readability-identifier-naming)
{
    return true;
}
SE_BIND_FINALIZE_FUNC(js_wrapper_FirebaseApp_finalize)

bool js_register_firebase_FirebaseApp(se::Object* obj) // NOLINT(readability-identifier-naming)
{
    auto* cls = se::Class::create("FirebaseApp", obj, nullptr, _SE(js_firebase_FirebaseApp_constructor));

#if CC_DEBUG
    cls->defineStaticProperty("isJSBClass", _SE(js_firebase_getter_return_true), nullptr);
#endif
    cls->defineFinalizeFunction(_SE(js_wrapper_FirebaseApp_finalize));
    cls->install();
    JSBClassType::registerClass<wrapper::FirebaseApp>(cls);

    __jsb_wrapper_FirebaseApp_proto = cls->getProto();
    __jsb_wrapper_FirebaseApp_class = cls;


    se::ScriptEngine::getInstance()->clearException();
    return true;
}
bool register_all_firebase(se::Object* obj)    // NOLINT
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("firebase", &nsVal, true))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("firebase", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_firebase_FirebaseApp(ns);
    return true;
}

// clang-format on