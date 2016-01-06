#include "lua_cocos2dx_spritepool_auto.hpp"
#include "SpritePool.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_spritepool_SpritePool_removeName(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_spritepool_SpritePool_removeName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpritePool:removeName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_spritepool_SpritePool_removeName'", nullptr);
            return 0;
        }
        cobj->removeName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePool:removeName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_removeName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_cleanFreeObjects(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_spritepool_SpritePool_cleanFreeObjects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_spritepool_SpritePool_cleanFreeObjects'", nullptr);
            return 0;
        }
        cobj->cleanFreeObjects();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePool:cleanFreeObjects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_cleanFreeObjects'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_create(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePool*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_spritepool_SpritePool_create'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpritePool:create");

            if (!ok) { break; }
            cocos2d::Sprite* ret = cobj->create(arg0);
            object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cocos2d::Sprite* ret = cobj->create();
            object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpritePool:create");

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1, "SpritePool:create");

            if (!ok) { break; }
            cocos2d::Sprite* ret = cobj->create(arg0, arg1);
            object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "SpritePool:create",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_create'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_createWithSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_spritepool_SpritePool_createWithSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_spritepool_SpritePool_createWithSpriteFrame'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->createWithSpriteFrame(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePool:createWithSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_createWithSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_cleanAllName(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_spritepool_SpritePool_cleanAllName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_spritepool_SpritePool_cleanAllName'", nullptr);
            return 0;
        }
        cobj->cleanAllName();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePool:cleanAllName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_cleanAllName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_createWithSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_spritepool_SpritePool_createWithSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpritePool:createWithSpriteFrameName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_spritepool_SpritePool_createWithSpriteFrameName'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->createWithSpriteFrameName(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePool:createWithSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_createWithSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_addName(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_spritepool_SpritePool_addName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpritePool:addName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_spritepool_SpritePool_addName'", nullptr);
            return 0;
        }
        cobj->addName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePool:addName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_addName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_checkName(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_spritepool_SpritePool_checkName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpritePool:checkName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_spritepool_SpritePool_checkName'", nullptr);
            return 0;
        }
        bool ret = cobj->checkName(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePool:checkName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_checkName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_init(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_spritepool_SpritePool_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpritePool:init");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "SpritePool:init");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_spritepool_SpritePool_init'", nullptr);
            return 0;
        }
        cobj->init(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePool:init",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_cleanAllObjects(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_spritepool_SpritePool_cleanAllObjects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_spritepool_SpritePool_cleanAllObjects'", nullptr);
            return 0;
        }
        cobj->cleanAllObjects();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePool:cleanAllObjects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_cleanAllObjects'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_createWithTexture(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePool*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_spritepool_SpritePool_createWithTexture'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1, "SpritePool:createWithTexture");

            if (!ok) { break; }
            cocos2d::Sprite* ret = cobj->createWithTexture(arg0, arg1);
            object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1, "SpritePool:createWithTexture");

            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2, "SpritePool:createWithTexture");

            if (!ok) { break; }
            cocos2d::Sprite* ret = cobj->createWithTexture(arg0, arg1, arg2);
            object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            cocos2d::Sprite* ret = cobj->createWithTexture(arg0);
            object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "SpritePool:createWithTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_createWithTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpritePool",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_spritepool_SpritePool_getInstance'", nullptr);
            return 0;
        }
        SpritePool* ret = SpritePool::getInstance();
        object_to_luaval<SpritePool>(tolua_S, "SpritePool",(SpritePool*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpritePool:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_spritepool_SpritePool_constructor(lua_State* tolua_S)
{
    int argc = 0;
    SpritePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_spritepool_SpritePool_constructor'", nullptr);
            return 0;
        }
        cobj = new SpritePool();
        tolua_pushusertype(tolua_S,(void*)cobj,"SpritePool");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePool:SpritePool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_spritepool_SpritePool_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_spritepool_SpritePool_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SpritePool)");
    return 0;
}

int lua_register_cocos2dx_spritepool_SpritePool(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpritePool");
    tolua_cclass(tolua_S,"SpritePool","SpritePool","",nullptr);

    tolua_beginmodule(tolua_S,"SpritePool");
        tolua_function(tolua_S,"new",lua_cocos2dx_spritepool_SpritePool_constructor);
        tolua_function(tolua_S,"removeName",lua_cocos2dx_spritepool_SpritePool_removeName);
        tolua_function(tolua_S,"cleanFreeObjects",lua_cocos2dx_spritepool_SpritePool_cleanFreeObjects);
        tolua_function(tolua_S,"create",lua_cocos2dx_spritepool_SpritePool_create);
        tolua_function(tolua_S,"createWithSpriteFrame",lua_cocos2dx_spritepool_SpritePool_createWithSpriteFrame);
        tolua_function(tolua_S,"cleanAllName",lua_cocos2dx_spritepool_SpritePool_cleanAllName);
        tolua_function(tolua_S,"createWithSpriteFrameName",lua_cocos2dx_spritepool_SpritePool_createWithSpriteFrameName);
        tolua_function(tolua_S,"addName",lua_cocos2dx_spritepool_SpritePool_addName);
        tolua_function(tolua_S,"checkName",lua_cocos2dx_spritepool_SpritePool_checkName);
        tolua_function(tolua_S,"init",lua_cocos2dx_spritepool_SpritePool_init);
        tolua_function(tolua_S,"cleanAllObjects",lua_cocos2dx_spritepool_SpritePool_cleanAllObjects);
        tolua_function(tolua_S,"createWithTexture",lua_cocos2dx_spritepool_SpritePool_createWithTexture);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_spritepool_SpritePool_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SpritePool).name();
    g_luaType[typeName] = "SpritePool";
    g_typeCast["SpritePool"] = "SpritePool";
    return 1;
}
TOLUA_API int register_all_cocos2dx_spritepool(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"cc",0);
	tolua_beginmodule(tolua_S,"cc");

	lua_register_cocos2dx_spritepool_SpritePool(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

