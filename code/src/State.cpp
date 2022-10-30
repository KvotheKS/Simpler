#pragma once

#define _USE_MATH_DEFINES

#include "../include/State.hpp"
#include "../include/GameObject.hpp"
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
    lua_pop(L,1); lua_pop(L,1);
}

void State::Update(float dt)
{
    InputManager& controller = InputManager::GetInstance();
    lua_State* L = LuaInitializer::L;
    if(SDL_QuitRequested() || controller.QuitRequested())
    {
        this->quitRequested = true;
        return;
    }

    lua_getglobal(L, "DeadGameObjects");
    lua_pcall(L, 0, 0, 0);

    lua_getglobal(L, "UpdateGameObjects");
    lua_pushnumber(L, dt);
    lua_pcall(L, 1, 0, 0);
}

bool State::QuitRequested() { return this->quitRequested; }