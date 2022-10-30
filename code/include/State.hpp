#pragma once

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
//#define INCLUDE_SDL_TTF
#include <memory>
#include <vector>
#include <iostream>
#include "SDL_include.h"
#include "./decl.hpp"
#include "./Game.hpp"

class State
{
protected:
    const char* name = "ObjectArray";
    bool quitRequested, started;

public:
    State();
    ~State();

public:
    bool QuitRequested();

public:
    virtual void Start();
    virtual void LoadAssets();
    
public:
    virtual void Update(float dt);
    virtual void Render();

public: //pq void pointer? pq eh uma table de lua
    std::weak_ptr<void> AddObject(void* go);
    std::weak_ptr<void> GetObjectPtr(void* go);
};
