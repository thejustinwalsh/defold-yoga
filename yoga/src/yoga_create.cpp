#include "yoga_module.h"
#include "yoga_create.h"

int yoga_create(lua_State* L)
{
    YGNodeRef node = YGNodeNew();
    *(YGNodeRef*)lua_newuserdata(L, sizeof(YGNodeRef)) = node;
    if (luaL_newmetatable(L, MODULE_NAME"_node")) {        
        lua_pushcfunction(L, yoga_destroy); lua_setfield(L, -2, "__gc");
        lua_pushvalue(L, -1); lua_setfield(L, -2, "__index");
    }
    lua_setmetatable(L, -2);

    return 1;
}

int yoga_createWithConfig(lua_State* L)
{
    // TODO: Parse Config options
    return yoga_create(L);
}

int yoga_destroy(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);

    YGNodeRef node = isYogaNodeRef(L, 1);
    if (node) {
        YGNodeRef parent = YGNodeGetParent(node);
        if (parent) {
            dmLogWarning("Yoga node still attached to a parent, not freeing it");
        }
        else {
            YGNodeFreeRecursive(node);
            node = nullptr;
        }
    }

    return 0;
}
