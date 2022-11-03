#pragma once

#define _USE_MATH_DEFINES

#include "LuaWrappers.hpp"
#include "../include/State.hpp"
#include "../include/InputManager.hpp"


#include <memory>

//////////////////////////////////////////////// Game State Functions /////////////////////////////////////////////////

State::State() 
{
    this->started = false;
    this->quitRequested = false;
    
}

State::~State()
{
    lua_State* L = LuaInitializer::L;
    lua_getglobal(L, "ClearState");
    lua_getglobal(L, this->name);
    lua_pcall(L, 1, 0, 0);
}

void State::Start()
{
    luaL_dofile(LuaInitializer::L, "./src/main.lua");
}

void State::LoadAssets(){}

void State::Update(float dt)
{
    InputManager& controller = InputManager::GetInstance();
    lua_State* L = LuaInitializer::L;
    if(SDL_QuitRequested() || controller.QuitRequested())
    {
        this->quitRequested = true;
        return;
    }
    
    lua_getglobal(L, this->name);
    // lua_getfield(L, -1, "DeadGameObjects");
    // lua_pushvalue(L, -2);
    // lua_pcall(L, 1, 0, 0);

    lua_getfield(L, -1, "UpdateGameObjects");
    lua_pushvalue(L, -2);
    lua_pushnumber(L, dt);
    lua_pcall(L, 2, 0, 0);
    lua_pop(L,-1);
}

void State::Render()
{
    lua_State* L = LuaInitializer::L;
    lua_getglobal(L, this->name);
    lua_getfield(L, -1, "RenderGameObjects");
    lua_pushvalue(L, -2);
    lua_pcall(L, 1, 0, 0);
    lua_pop(L,-1);
}

bool State::QuitRequested() { return this->quitRequested; }