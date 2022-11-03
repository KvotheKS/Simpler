#pragma once 

#include <cstdio>
#include <tuple>

extern "C"
{
    #include "./lua/include/lauxlib.h"
    #include "./lua/include/lualib.h"
    #include "./lua/include/lua.h"
}

class LuaInitializer
{
public:
    static lua_State* L;
public:
    LuaInitializer();
    ~LuaInitializer();
    static void InsertLuaFunctions();
    static void InsertLuaFiles();
};