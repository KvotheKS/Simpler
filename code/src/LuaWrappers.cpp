#include "LuaWrappers.hpp"

LuaInitializer GlobalLuaWrapper;

LuaInitializer::LuaInitializer()
{
    LuaInitializer::L = luaL_newstate();
    luaL_openlibs(L);
    InsertLuaFunctions()
}

LuaInitializer::~LuaInitializer()
{}

void LuaInitializer::InsertLuaFunctions()
{
    luaL_Reg Engine[] = {
        {NULL, NULL}
    }
}