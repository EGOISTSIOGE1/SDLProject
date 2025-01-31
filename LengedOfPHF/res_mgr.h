#ifndef _RESOURCES_MGR_H_
#define _RESOURCES_MGR_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <string>
#include <unordered_map>

class ResMgr {
public:
    static ResMgr* instance();

    void load(SDL_Renderer* renderer);
    Mix_Chunk* find_audio(const std::string& name);
    SDL_Texture* find_texture(const std::string& name);

private:
    ResMgr();
    ~ResMgr();

private:
    static ResMgr* manager;
    std::unordered_map<std::string, Mix_Chunk*> audio_pool;
    std::unordered_map<std::string, SDL_Texture*> texture_pool;
};

#endif // !_RESOURCES_MGR_H_