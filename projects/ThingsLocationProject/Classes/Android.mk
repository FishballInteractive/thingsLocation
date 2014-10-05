LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := thingslocation_shared
LOCAL_MODULE_FILENAME := libthingslocation
LOCAL_SRC_FILES := hellocpp/main.cpp\
../../Classes/./Application/app_models/CGPSPoint.cpp\
../../Classes/./Application/AppDelegate.cpp\
../../Classes/./Application/CAppCore.cpp\
../../Classes/./Application/CAppData.cpp\
../../Classes/./Application/CGPSManager.cpp\
../../Classes/./Application/platform/android/CGPSControllerNative_android.cpp\
../../Classes/./lib/CNotificationCenter.cpp\
../../Classes/./lib/data/CBufferReader.cpp\
../../Classes/./lib/data/CBufferWriter.cpp\
../../Classes/./lib/data/CValue.cpp\
../../Classes/./lib/third_part/jsoncpp/jsoncpp.cpp\
../../Classes/./lib/Utils.cpp\
\
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./Application/app_models
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./Application/interface
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./Application/platform/android
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./Application/platform/ios
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./Application/platform
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./Application
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./lib/data
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./lib/debug
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./lib/interface
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./lib/third_part/jsoncpp
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./lib/third_part
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/./lib
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../cocos2dx/platform/
LOCAL_LDLIBS := $(NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi-v7a/libsupc++.a
LOCAL_LDLIBS += $(NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi-v7a/libgnustl_static.a
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static
include $(BUILD_SHARED_LIBRARY)
$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
