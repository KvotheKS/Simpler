#include "../include/Sprite.hpp"
#include "../include/Game.hpp"
#include "../include/Resources.hpp"
//#include "../include/Camera.hpp"
#include <cmath>

///////////////////////////////////////////////// Game Sprites ///////////////////////////////////////////////

SpriteInfo::SpriteInfo()
{
    this->texture = nullptr;
    this->width = 0;
    this->height = 0;
    this->clipRect = {0, 0, 0, 0};
    this->scale = {1,1};
    this->angleDeg = 0.0f;
}

SpriteInfo::SpriteInfo(const std::string& file)
{
    this->texture = nullptr;
    this->width = 0;
    this->height = 0;
    this->scale = {1,1};
    this->angleDeg = 0.0f;
    Open(file);
}

SpriteInfo::~SpriteInfo()
{
    this->texture = nullptr;
}

void SpriteInfo::Open(const std::string& file, int x, int y, int w, int h)
{
    Open(file);
    
    w = w == -1 ? this->width : w;
    h = h == -1 ? this->height : h;

    SetClip(x,y,w,h);
}

void SpriteInfo::Open(const std::string& file)
{
    this->texture = Resources::GetImage(file);

    // Talvez descomentar isso;;
    // if(this->texture == nullptr)
    //     Game::ThrowException();

    SDL_QueryTexture(this->texture, nullptr, nullptr, &this->width, &this->height);
    SetClip(0,0,this->width, this->height);
}

void SpriteInfo::SetClip(int x, int y, int w, int h)
{
    this->clipRect = {
        x, y, w, h
    };
}

void SpriteInfo::Print()
{
    /*
    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
    const Vec2 cPos = Camera::pos;
    const Rect& wrp = this->associated->box;
    
    SDL_Rect dst = {
        (int)(wrp.x - cPos.x),
        (int)(wrp.y - cPos.y),
        (int)this->GetWidth(),
        (int)this->GetHeight()
    };

    SDL_RenderCopyEx(renderer, this->texture, &this->clipRect, 
    &dst, this->angleDeg, nullptr, SDL_FLIP_NONE);*/
}

void SpriteInfo::Print(float x, float y)
{
    /*SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
    
    SDL_Rect dst = {
        (int)x,
        (int)y,
        this->clipRect.w, 
        this->clipRect.h
    };

    SDL_RenderCopy(renderer, this->texture, &this->clipRect, &dst);*/
}

void SpriteInfo::SetScale(float scaleX, float scaleY) 
{ this->scale = Vec2{scaleX, scaleY};}
int SpriteInfo::GetWidth(){ return this->width*this->scale.x; }
int SpriteInfo::GetHeight(){ return this->height*this->scale.y; }
Vec2 SpriteInfo::GetScale(){ return this->scale; }
bool SpriteInfo::IsOpen(){ return this->texture != nullptr; }