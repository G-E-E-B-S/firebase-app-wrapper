set(PROJ_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/cpp/firebase_app.cpp
)
add_definitions(-DIS_ANDROID)
if (COCOS_3_7_PLUS)
    list(APPEND PROJ_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/bindings/auto/3.7.x/jsb_native_firebase_auto.cpp
    )
elseif(COCOS_3_X_PLUS)
    list(APPEND PROJ_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/bindings/auto/3.x.x_3.6.x/jsb_native_firebase_auto.cpp
    )
else()
    list(APPEND PROJ_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/bindings/auto/2.x/jsb_native_firebase_auto.cpp
    )
endif()

set(NATIVE_FIREBASE_INCLUDE_DIR
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/external/includes)
add_library(native_firebase STATIC ${PROJ_SOURCES})

target_include_directories(native_firebase PUBLIC
    ${COCOS_X_PATH}
    ${COCOS_X_PATH}/cocos
    ${COCOS_X_PATH}/cocos/renderer
if (COCOS_3_7_PLUS)
    ${COCOS_X_PATH}/cocos/bindings/jswrapper
endif()
    ${platform_spec_path}/include/v8
    ${JSB_HELPER_INCLUDE_DIR}
    ${NATIVE_FIREBASE_INCLUDE_DIR}
)
target_link_libraries(native_firebase ${CMAKE_CURRENT_LIST_DIR}/external/libs/android/${ANDROID_ABI}/libfirebase_app.a)