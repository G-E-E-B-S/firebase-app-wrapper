cmake_minimum_required(VERSION 3.8)

set(FIREBASE_JS_BINDING_SRC)

if (COCOS_3_7_PLUS)
    list(APPEND FIREBASE_JS_BINDING_SRC
        ${CMAKE_CURRENT_LIST_DIR}/../bindings/auto/3.7.x/jsb_native_firebase_auto.cpp
    )
elseif(COCOS_3_X_PLUS)
    list(APPEND FIREBASE_JS_BINDING_SRC
        ${CMAKE_CURRENT_LIST_DIR}/../bindings/auto/3.x.x_3.6.x/jsb_native_firebase_auto.cpp
    )
else()
    list(APPEND FIREBASE_JS_BINDING_SRC
        ${CMAKE_CURRENT_LIST_DIR}/../bindings/auto/2.x/jsb_native_firebase_auto.cpp
    )
endif()

source_group(TREE ${CMAKE_CURRENT_LIST_DIR}/../bindings PREFIX "js-bindings/native-firebase" FILES ${FIREBASE_JS_BINDING_SRC})

list(APPEND CC_ALL_SOURCES ${FIREBASE_JS_BINDING_SRC})