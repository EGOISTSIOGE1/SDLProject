#ifndef _REGION_MGR_H_
#define _REGION_MGR_H_

#include "region.h"

#include <SDL2/SDL.h>

#include <string>
#include <unordered_map>

class RegionMgr {
public:
    static RegionMgr* instance();

    void add(const std::string& name, Region* region);
    Region* find(const std::string& name);

    void on_update(float delta);
    void on_input(const SDL_Event& event);
    void on_render(SDL_Renderer* renderer);

private:
    RegionMgr();
    ~RegionMgr();

private:
    static RegionMgr* manager;
    std::unordered_map<std::string, Region*> region_pool;
};

#endif // !_REGION_MGR_H_