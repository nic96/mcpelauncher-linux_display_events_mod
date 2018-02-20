LOCAL_PATH := $(call my-dir)
CWD := $(shell pwd)

include $(CLEAR_VARS)

LOCAL_MODULE := display_events_mod
LOCAL_SRC_FILES := main.cpp mcpelauncher_api.c
LOCAL_LDLIBS := -L$(LOCAL_PATH)/ -ldl -lminecraftpe
include $(BUILD_SHARED_LIBRARY)
