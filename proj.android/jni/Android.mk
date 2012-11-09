LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp\
                   ../../Classes/Scene/StartScene.cpp \
                   ../../Classes/Scene/MenuScene.cpp \
                   ../../Classes/Scene/StageOneScene.cpp \
                   ../../Classes/Scene/StageTwoScene.cpp \
                    ../../Classes/Scene/StageThreeScene.cpp \
                    ../../Classes/Scene/GameLayer.cpp\
                    ../../Classes/Scene/StageLayer.cpp
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
					

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static box2d_static ryandroidlib_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android)\
$(call import-module,cocos2dx)\
$(call import-module,extensions)\
$(call import-module,Box2D)\
$(call import-module,ryAndroidLib)