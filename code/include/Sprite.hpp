#pragma once 

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
//#define INCLUDE_SDL_TTF
#include "SDL_include.h"

extern "C"
{
    #include "../include/lua/include/lauxlib.h"
    #include "../include/lua/include/lualib.h"
    #include "../include/lua/include/lua.h"
}

#include "./decl.hpp"
#include "./Vec2.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

class SpriteInfo
{
private:
    SDL_Texture* texture;
    int width, height;
    SDL_Rect clipRect;
    Vec2 scale;
public:
    double angleDeg;

public:
    SpriteInfo();

    SpriteInfo(const std::string& file);

    ~SpriteInfo();

public:
    void Open(const std::string& file, int x, int y, int w=-1, int h=-1);

    void Open(const std::string& file);
    static void Open(lua_State* L)
    { ((SpriteInfo*)lua_touserdata(L,-1))->Open(lua_tostring(L,-2)); }

    void SetClip(int x, int y, int w, int h);
    
    static void SetClip(lua_State *L)
    { ((SpriteInfo*)lua_touserdata(L,-1))->SetClip(lua_tonumber(L,-2), lua_tonumber(L,-3) ,lua_tonumber(L,-4), lua_tonumber(L,-5)); }
    
    static void ClipInfo(lua_State *L)
    { 
        // eh pra isso aq que a gnt faz OAC.
        int* arr = &((SpriteInfo*)lua_touserdata(L,-1))->clipRect.x;  
        lua_pushnumber(L, arr[((int)lua_tonumber(L,-2)) - 1]);
    }

public:
    void Print();
    void Print(float x, float y);

public:
    void SetScale(float scaleX, float scaleY);
    static void SetScale(lua_State* L)
    { ((SpriteInfo*)lua_touserdata(L,-1))->SetScale(lua_tonumber(L,-2), lua_tonumber(L,-3));}
public:
    int GetWidth();
    static void GetWidth(lua_State* L)
    { lua_pushnumber(L, ((SpriteInfo*)lua_touserdata(L,-1))->GetWidth()); }
    
    int GetHeight();
    static void GetHeight(lua_State* L)
    { lua_pushnumber(L, ((SpriteInfo*)lua_touserdata(L,-1))->GetHeight()); }
    
    Vec2 GetScale();

    bool IsOpen();
    static void IsOpen(lua_State* L)
    { lua_pushboolean(L, ((SpriteInfo*)lua_touserdata(L,-1))->IsOpen());}
    
    static void SetLuaTable(lua_State* L)
    {
        
    }
};