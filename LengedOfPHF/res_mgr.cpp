#include "res_mgr.h"

#include <SDL2/SDL_image.h>
#include <filesystem>

ResMgr* ResMgr::manager = nullptr;

ResMgr* ResMgr::instance() {
    if (!manager) {
        manager = new ResMgr();
    }
    return manager;
}

Mix_Chunk* ResMgr::find_audio(const std::string& name) {
    return audio_pool[name];
}

SDL_Texture* ResMgr::find_texture(const std::string& name) {
    return texture_pool[name];
}

ResMgr::ResMgr() = default;

ResMgr::~ResMgr() = default;

void ResMgr::load(SDL_Renderer* renderer) {
    using namespace std::filesystem;

    for (const auto& entry : directory_iterator("resources")) {
        if (entry.is_regular_file()) {
            const path& path = entry.path();
            if (path.extension() == ".png") {
                SDL_Texture* texture = IMG_LoadTexture(renderer, path.u8string().c_str());
                texture_pool[path.stem().u8string()] = texture;
            } else if (path.extension() == ".mp3") {
                Mix_Chunk* audio = Mix_LoadWAV(path.u8string().c_str());
                audio_pool[path.stem().u8string()] = audio;
            }
        }
    }
}