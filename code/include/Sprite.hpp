#pragma once 

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
//#define INCLUDE_SDL_TTF
#include "SDL_include.h"

#include "./decl.hpp"
#include "./GameObject.hpp"
#include "./Vec2.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

class Sprite
{
private:
    SDL_Texture* texture;
    int width, height;
    SDL_Rect clipRect;
    Vec2 scale;
public:
    double angleDeg;

public:
    Sprite();

    Sprite(const std::string& file);

    Sprite(GameObject& associated);

    Sprite(GameObject& associated, const std::string& file);

    ~Sprite();

public:
    void Open(const std::string& file, int x, int y, int w=-1, int h=-1);

    void Open(const std::string& file);
    static void Open(lua_State* L)
    { ((Sprite*)lua_touserdata(L,-1))->Open(lua_tostring(L,-2)); }

    void SetClip(int x, int y, int w, int h);
    static void SetClip(lua_State *L)
    { ((Sprite*)lua_touserdata(L,-1))->SetClip(lua_tonumber(L,-2), lua_tonumber(L,-3) ,lua_tonumber(L,-4), lua_tonumber(L,-5)); }

public:
    void print();
    void print(float x, float y);

public:
    void SetScale(float scaleX, float scaleY);
    static void SetScale
public:
    int GetWidth();
    int GetHeight();
    Vec2 GetScale(); 
    bool IsOpen();

public:
    bool Is(const std::string& type);
};