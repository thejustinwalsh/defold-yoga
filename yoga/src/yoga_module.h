#pragma once

#include <dmsdk/sdk.h>
#include <Yoga.h>

#define LIB_NAME "Yoga"
#define MODULE_NAME "__yoga_internal"
#define DLIB_LOG_DOMAIN "YOGA"

YGNodeRef isYogaNodeRef(lua_State* L, int index);

