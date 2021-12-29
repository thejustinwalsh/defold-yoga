#include "yoga_module.h"
#include "yoga_create.h"
#include "yoga_node.h"

YGNodeRef isYogaNodeRef(lua_State* L, int index) {
    void* pUserData = luaL_checkudata(L, 1, MODULE_NAME"_node");
    luaL_argcheck(L, pUserData != NULL, 1, "yoga node expected");

    return *(YGNodeRef*)pUserData;
}

static const luaL_reg ModuleInterface[] =
{
    {"create", yoga_create},
    {"createWithConfig", yoga_createWithConfig},
    {"destroy", yoga_destroy},
    {"calculateLayout", node_calculateLayout},
    {"copyStyle", node_copyStyle},
    {"free", node_free},
    {"freeRecursive", node_freeRecursive},
    {"getAlignContent", node_getAlignContent},
    {"getAlignItems", node_getAlignItems},
    {"getAlignSelf", node_getAlignSelf},
    {"getAspectRatio", node_getAspectRatio},
    {"getBorder", node_getBorder},
    {"getChild", node_getChild},
    {"getChildCount", node_getChildCount},
    {"getComputedBorder", node_getComputedBorder},
    {"getComputedBottom", node_getComputedBottom},
    {"getComputedHeight", node_getComputedHeight},
    {"getComputedLayout", node_getComputedLayout},
    {"getComputedLeft", node_getComputedLeft},
    {"getComputedMargin", node_getComputedMargin},
    {"getComputedPadding", node_getComputedPadding},
    {"getComputedRight", node_getComputedRight},
    {"getComputedTop", node_getComputedTop},
    {"getComputedWidth", node_getComputedWidth},
    {"getDisplay", node_getDisplay},
    {"getFlexBasis", node_getFlexBasis},
    {"getFlexDirection", node_getFlexDirection},
    {"getFlexGrow", node_getFlexGrow},
    {"getFlexShrink", node_getFlexShrink},
    {"getFlexWrap", node_getFlexWrap},
    {"getHeight", node_getHeight},
    {"getJustifyContent", node_getJustifyContent},
    {"getMargin", node_getMargin},
    {"getMaxHeight", node_getMaxHeight},
    {"getMaxWidth", node_getMaxWidth},
    {"getMinHeight", node_getMinHeight},
    {"getMinWidth", node_getMinWidth},
    {"getOverflow", node_getOverflow},
    {"getPadding", node_getPadding},
    {"getParent", node_getParent},
    {"getPosition", node_getPosition},
    {"getPositionType", node_getPositionType},
    {"getWidth", node_getWidth},
    {"insertChild", node_insertChild},
    {"isDirty", node_isDirty},
    {"markDirty", node_markDirty},
    {"removeChild", node_removeChild},
    {"reset", node_reset},
    {"setAlignContent", node_setAlignContent},
    {"setAlignItems", node_setAlignItems},
    {"setAlignSelf", node_setAlignSelf},
    {"setAspectRatio", node_setAspectRatio},
    {"setBorder", node_setBorder},
    {"setDisplay", node_setDisplay},
    {"setFlex", node_setFlex},
    {"setFlexBasis", node_setFlexBasis},
    {"setFlexBasisPercent", node_setFlexBasisPercent},
    {"setFlexDirection", node_setFlexDirection},
    {"setFlexGrow", node_setFlexGrow},
    {"setFlexShrink", node_setFlexShrink},
    {"setFlexWrap", node_setFlexWrap},
    {"setHeight", node_setHeight},
    {"setHeightAuto", node_setHeightAuto},
    {"setHeightPercent", node_setHeightPercent},
    {"setJustifyContent", node_setJustifyContent},
    {"setMargin", node_setMargin},
    {"setMarginAuto", node_setMarginAuto},
    {"setMarginPercent", node_setMarginPercent},
    {"setMaxHeight", node_setMaxHeight},
    {"setMaxHeightPercent", node_setMaxHeightPercent},
    {"setMaxWidth", node_setMaxWidth},
    {"setMaxWidthPercent", node_setMaxWidthPercent},
    {"setMeasureFunc", node_setMeasureFunc},
    {"setMinHeight", node_setMinHeight},
    {"setMinHeightPercent", node_setMinHeightPercent},
    {"setMinWidth", node_setMinWidth},
    {"setMinWidthPercent", node_setMinWidthPercent},
    {"setOverflow", node_setOverflow},
    {"setPadding", node_setPadding},
    {"setPaddingPercent", node_setPaddingPercent},
    {"setPosition", node_setPosition},
    {"setPositionPercent", node_setPositionPercent},
    {"setPositionType", node_setPositionType},
    {"setWidth", node_setWidth},
    {"setWidthAuto", node_setWidthAuto},
    {"setWidthPercent", node_setWidthPercent},
    {"unsetMeasureFunc", node_unsetMeasureFunc},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);

    luaL_register(L, MODULE_NAME, ModuleInterface);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result app_init(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result app_final(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result init(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    dmLogInfo("Registered %s Extension", MODULE_NAME);

    return dmExtension::RESULT_OK;
}

dmExtension::Result update(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

void on_event(dmExtension::Params* params, const dmExtension::Event* event)
{
    
}

dmExtension::Result final(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(Yoga, LIB_NAME, app_init, app_final, init, update, on_event, final)
