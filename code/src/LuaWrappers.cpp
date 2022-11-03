#include "LuaWrappers.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

LuaInitializer GlobalLuaWrapper;
lua_State* LuaInitializer::L;

LuaInitializer::LuaInitializer()
{
    LuaInitializer::L = luaL_newstate();
    luaL_openlibs(L);
    InsertLuaFiles();
    InsertLuaFunctions();
}

LuaInitializer::~LuaInitializer()
{}

void LuaInitializer::InsertLuaFiles()
{
    // luaL_dofile(LuaInitializer::L, "./src/ObjectArray.lua");
    // luaL_dofile(LuaInitializer::L, "./src/Sprite.lua");
    // luaL_dofile(LuaInitializer::L, "./src/Vec2.lua");
    // luaL_dofile(LuaInitializer::L, "./src/GameObject.lua");
    for(auto& p : fs::directory_iterator("./src"))
    {
        auto path = p.path().relative_path().u8string();
        if(path.substr(path.size()-3, 3) == "lua")
            luaL_dofile(LuaInitializer::L, (char*)path.c_str());
    }
    // std::cout << "fuck up hater\n";
    // std::cout << "bitch\n";
}

void LuaInitializer::InsertLuaFunctions()
{
    luaL_Reg Engine[] = {
        {NULL, NULL}
    };
}