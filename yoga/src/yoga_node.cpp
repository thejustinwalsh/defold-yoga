#include "yoga_module.h"
#include "yoga_node.h"

int node_calculateLayout(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float availableWidth = luaL_checknumber(L, 2);
    float availableHeight = luaL_checknumber(L, 3);
    YGDirection direction = (YGDirection)luaL_checkinteger(L, 4);
    
    YGNodeCalculateLayout(node, availableWidth, availableHeight, direction);
    
    return 0;
}

int node_copyStyle(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGNodeRef from = isYogaNodeRef(L, 2);
    YGNodeCopyStyle(node, from);

    return 0;
}

int node_free(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGNodeFree(node);
    node = nullptr;

    return 0;
}

int node_freeRecursive(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGNodeFreeRecursive(node);
    node = nullptr;

    return 0;
}

int node_getAlignContent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGAlign align = YGNodeStyleGetAlignContent(node);
    
    lua_pushinteger(L, align);
    return 1;
}

int node_getAlignItems(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGAlign align = YGNodeStyleGetAlignItems(node);

    lua_pushinteger(L, align);
    return 1;
}

int node_getAlignSelf(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGAlign align = YGNodeStyleGetAlignSelf(node);

    lua_pushinteger(L, align);
    return 1;
}

int node_getAspectRatio(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float aspectRatio = YGNodeStyleGetAspectRatio(node);

    lua_pushnumber(L, aspectRatio);
    return 1;
}

int node_getBorder(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    float border = YGNodeStyleGetBorder(node, edge);

    lua_pushnumber(L, border);
    return 1;
}

int node_getChild(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    int index = luaL_checkinteger(L, 2);
    YGNodeRef child = YGNodeGetChild(node, index);

    *(YGNodeRef*)lua_newuserdata(L, sizeof(YGNodeRef)) = child;
    return 1;
}

int node_getChildCount(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    int count = YGNodeGetChildCount(node);

    lua_pushinteger(L, count);
    return 1;
}

int node_getComputedBorder(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    float border = YGNodeLayoutGetBorder(node, edge);

    lua_pushnumber(L, border);
    return 1;
}

int node_getComputedBottom(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float bottom = YGNodeLayoutGetBottom(node);

    lua_pushnumber(L, bottom);
    return 1;
}

int node_getComputedHeight(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float height = YGNodeLayoutGetHeight(node);

    lua_pushnumber(L, height);
    return 1;
}

int node_getComputedLayout(lua_State* L)
{
    // TODO: Implement ??
    return 0;
}

int node_getComputedLeft(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float left = YGNodeLayoutGetLeft(node);

    lua_pushnumber(L, left);
    return 1;
}

int node_getComputedMargin(lua_State* L)
{
    return 0;
}

int node_getComputedPadding(lua_State* L)
{
    return 0;
}

int node_getComputedRight(lua_State* L)
{
    return 0;
}

int node_getComputedTop(lua_State* L)
{
    return 0;
}

int node_getComputedWidth(lua_State* L)
{
    return 0;
}

int node_getDisplay(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGDisplay display = YGNodeStyleGetDisplay(node);

    lua_pushinteger(L, display);
    return 1;
}

int node_getFlexBasis(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGValue flexBasis = YGNodeStyleGetFlexBasis(node);

    lua_pushnumber(L, flexBasis.value);
    lua_pushinteger(L, flexBasis.unit);
    return 2;
}

int node_getFlexDirection(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGFlexDirection flexDirection = YGNodeStyleGetFlexDirection(node);

    lua_pushinteger(L, flexDirection);
    return 1;
}

int node_getFlexGrow(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float flexGrow = YGNodeStyleGetFlexGrow(node);

    lua_pushnumber(L, flexGrow);
    return 1;
}

int node_getFlexShrink(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float flexShrink = YGNodeStyleGetFlexShrink(node);

    lua_pushnumber(L, flexShrink);
    return 1;
}

int node_getFlexWrap(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGWrap flexWrap = YGNodeStyleGetFlexWrap(node);

    lua_pushinteger(L, flexWrap);
    return 1;
}

int node_getHeight(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGValue height = YGNodeStyleGetHeight(node);

    lua_pushnumber(L, height.value);
    lua_pushnumber(L, height.unit);
    return 2;
}

int node_getJustifyContent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGJustify justifyContent = YGNodeStyleGetJustifyContent(node);

    lua_pushinteger(L, justifyContent);
    return 1;
}

int node_getMargin(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    YGValue margin = YGNodeStyleGetMargin(node, edge);
    
    lua_pushnumber(L, margin.value);
    lua_pushnumber(L, margin.unit);
    return 2;
}

int node_getMaxHeight(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGValue maxHeight = YGNodeStyleGetMaxHeight(node);

    lua_pushnumber(L, maxHeight.value);
    lua_pushnumber(L, maxHeight.unit);
    return 2;
}

int node_getMaxWidth(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGValue maxWidth = YGNodeStyleGetMaxWidth(node);

    lua_pushnumber(L, maxWidth.value);
    lua_pushnumber(L, maxWidth.unit);
    return 2;
}

int node_getMinHeight(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGValue minHeight = YGNodeStyleGetMinHeight(node);

    lua_pushnumber(L, minHeight.value);
    lua_pushnumber(L, minHeight.unit);
    return 2;
}

int node_getMinWidth(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGValue minWidth = YGNodeStyleGetMinWidth(node);

    lua_pushnumber(L, minWidth.value);
    lua_pushnumber(L, minWidth.unit);
    return 2;
}

int node_getOverflow(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGOverflow overflow = YGNodeStyleGetOverflow(node);

    lua_pushinteger(L, overflow);
    return 1;
}

int node_getPadding(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    YGValue padding = YGNodeStyleGetPadding(node, edge);

    lua_pushnumber(L, padding.value);
    lua_pushnumber(L, padding.unit);
    return 2;
}

int node_getParent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGNodeRef parent = YGNodeGetParent(node);

    *(YGNodeRef*)lua_newuserdata(L, sizeof(YGNodeRef)) = parent;
    return 1;
}

int node_getPosition(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    YGValue position = YGNodeStyleGetPosition(node, edge);

    lua_pushnumber(L, position.value);
    lua_pushnumber(L, position.unit);
    return 2;
}

int node_getPositionType(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGPositionType positionType = YGNodeStyleGetPositionType(node);

    lua_pushinteger(L, positionType);
    return 1;
}

int node_getWidth(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGValue width = YGNodeStyleGetWidth(node);

    lua_pushnumber(L, width.value);
    lua_pushnumber(L, width.unit);
    return 2;
}

int node_insertChild(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGNodeRef child = isYogaNodeRef(L, 2);
    int index = luaL_checkinteger(L, 3);
    YGNodeInsertChild(node, child, index);

    return 0;
}

int node_isDirty(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    bool isDirty = YGNodeIsDirty(node);

    lua_pushboolean(L, isDirty);
    return 1;
}

int node_markDirty(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGNodeMarkDirty(node);

    return 0;
}

int node_removeChild(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGNodeRef child = isYogaNodeRef(L, 2);
    YGNodeRemoveChild(node, child);

    return 0;
}

int node_reset(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGNodeReset(node);

    return 0;
}

int node_setAlignContent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGAlign alignContent = (YGAlign)luaL_checkinteger(L, 2);
    YGNodeStyleSetAlignContent(node, alignContent);

    return 0;
}

int node_setAlignItems(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGAlign alignItems = (YGAlign)luaL_checkinteger(L, 2);
    YGNodeStyleSetAlignItems(node, alignItems);

    return 0;
}

int node_setAlignSelf(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGAlign alignSelf = (YGAlign)luaL_checkinteger(L, 2);
    YGNodeStyleSetAlignSelf(node, alignSelf);

    return 0;
}

int node_setAspectRatio(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float aspectRatio = luaL_checknumber(L, 2);
    YGNodeStyleSetAspectRatio(node, aspectRatio);

    return 0;
}

int node_setBorder(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    float border = luaL_checknumber(L, 3);
    YGNodeStyleSetBorder(node, edge, border);

    return 0;
}

int node_setDisplay(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGDisplay display = (YGDisplay)luaL_checkinteger(L, 2);
    YGNodeStyleSetDisplay(node, display);

    return 0;
}

int node_setFlex(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float flex = luaL_checknumber(L, 2);
    YGNodeStyleSetFlex(node, flex);

    return 0;
}

int node_setFlexBasis(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float flexBasis = luaL_checknumber(L, 2);
    YGNodeStyleSetFlexBasis(node, flexBasis);

    return 0;
}

int node_setFlexBasisPercent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float flexBasisPercent = luaL_checknumber(L, 2);
    YGNodeStyleSetFlexBasisPercent(node, flexBasisPercent);

    return 0;
}

int node_setFlexDirection(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGFlexDirection flexDirection = (YGFlexDirection)luaL_checkinteger(L, 2);
    YGNodeStyleSetFlexDirection(node, flexDirection);

    return 0;
}

int node_setFlexGrow(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float flexGrow = luaL_checknumber(L, 2);
    YGNodeStyleSetFlexGrow(node, flexGrow);

    return 0;
}

int node_setFlexShrink(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float flexShrink = luaL_checknumber(L, 2);
    YGNodeStyleSetFlexShrink(node, flexShrink);

    return 0;
}

int node_setFlexWrap(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGWrap flexWrap = (YGWrap)luaL_checkinteger(L, 2);
    YGNodeStyleSetFlexWrap(node, flexWrap);

    return 0;
}

int node_setHeight(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float height = luaL_checknumber(L, 2);
    YGNodeStyleSetHeight(node, height);

    return 0;
}

int node_setHeightAuto(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGNodeStyleSetHeightAuto(node);

    return 0;
}

int node_setHeightPercent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float heightPercent = luaL_checknumber(L, 2);
    YGNodeStyleSetHeightPercent(node, heightPercent);

    return 0;
}

int node_setJustifyContent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGJustify justifyContent = (YGJustify)luaL_checkinteger(L, 2);
    YGNodeStyleSetJustifyContent(node, justifyContent);

    return 0;
}

int node_setMargin(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    float margin = luaL_checknumber(L, 3);
    YGNodeStyleSetMargin(node, edge, margin);

    return 0;
}

int node_setMarginAuto(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    YGNodeStyleSetMarginAuto(node, edge);

    return 0;
}

int node_setMarginPercent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    float marginPercent = luaL_checknumber(L, 3);
    YGNodeStyleSetMarginPercent(node, edge, marginPercent);

    return 0;
}

int node_setMaxHeight(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float maxHeight = luaL_checknumber(L, 2);
    YGNodeStyleSetMaxHeight(node, maxHeight);

    return 0;
}

int node_setMaxHeightPercent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float maxHeightPercent = luaL_checknumber(L, 2);
    YGNodeStyleSetMaxHeightPercent(node, maxHeightPercent);

    return 0;
}

int node_setMaxWidth(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float maxWidth = luaL_checknumber(L, 2);
    YGNodeStyleSetMaxWidth(node, maxWidth);

    return 0;
}

int node_setMaxWidthPercent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float maxWidthPercent = luaL_checknumber(L, 2);
    YGNodeStyleSetMaxWidthPercent(node, maxWidthPercent);

    return 0;
}

int node_setMeasureFunc(lua_State* L)
{
    //TODO: setMeasureFunc
    YGNodeRef node = isYogaNodeRef(L, 1);
    lua_pushvalue(L, 2);
    int ref = luaL_ref(L, LUA_REGISTRYINDEX);
    //YGNodeSetContext(node, {L, ref});
    YGNodeSetMeasureFunc(node, [](YGNodeRef node, float width, YGMeasureMode widthMode, float height, YGMeasureMode heightMode) -> YGSize {
        //lua_State* L = (lua_State*)YGNodeGetContext(node);
        //lua_rawgeti(L, LUA_REGISTRYINDEX, ref);
        //lua_pushnumber(L, width);
        //lua_pushinteger(L, widthMode);
        //lua_pushnumber(L, height);
        //lua_pushinteger(L, heightMode);
        //lua_call(L, 4, 2);
        //float resultWidth = luaL_checknumber(L, -2);
        //float resultHeight = luaL_checknumber(L, -1);
        //lua_pop(L, 2);
        //return (YGSize){resultWidth, resultHeight};
    });
    
    return 0;
}

int node_setMinHeight(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float minHeight = luaL_checknumber(L, 2);
    YGNodeStyleSetMinHeight(node, minHeight);

    return 0;
}

int node_setMinHeightPercent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float minHeightPercent = luaL_checknumber(L, 2);
    YGNodeStyleSetMinHeightPercent(node, minHeightPercent);

    return 0;
}

int node_setMinWidth(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float minWidth = luaL_checknumber(L, 2);
    YGNodeStyleSetMinWidth(node, minWidth);

    return 0;
}

int node_setMinWidthPercent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float minWidthPercent = luaL_checknumber(L, 2);
    YGNodeStyleSetMinWidthPercent(node, minWidthPercent);

    return 0;
}

int node_setOverflow(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGOverflow overflow = (YGOverflow)luaL_checkinteger(L, 2);
    YGNodeStyleSetOverflow(node, overflow);

    return 0;
}

int node_setPadding(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    float padding = luaL_checknumber(L, 3);
    YGNodeStyleSetPadding(node, edge, padding);

    return 0;
}

int node_setPaddingPercent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    float paddingPercent = luaL_checknumber(L, 3);
    YGNodeStyleSetPaddingPercent(node, edge, paddingPercent);

    return 0;
}

int node_setPosition(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    float position = luaL_checknumber(L, 3);
    YGNodeStyleSetPosition(node, edge, position);

    return 0;
}

int node_setPositionPercent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGEdge edge = (YGEdge)luaL_checkinteger(L, 2);
    float positionPercent = luaL_checknumber(L, 3);
    YGNodeStyleSetPositionPercent(node, edge, positionPercent);

    return 0;
}

int node_setPositionType(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGPositionType positionType = (YGPositionType)luaL_checkinteger(L, 2);
    YGNodeStyleSetPositionType(node, positionType);

    return 0;
}

int node_setWidth(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float width = luaL_checknumber(L, 2);
    YGNodeStyleSetWidth(node, width);

    return 0;
}

int node_setWidthAuto(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGNodeStyleSetWidthAuto(node);

    return 0;
}

int node_setWidthPercent(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    float widthPercent = luaL_checknumber(L, 2);
    YGNodeStyleSetWidthPercent(node, widthPercent);

    return 0;
}

int node_unsetMeasureFunc(lua_State* L)
{
    YGNodeRef node = isYogaNodeRef(L, 1);
    YGNodeSetMeasureFunc(node, nullptr);

    return 0;
}
