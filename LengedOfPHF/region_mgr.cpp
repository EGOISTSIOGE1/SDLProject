#include "region_mgr.h"

RegionMgr* RegionMgr::manager = nullptr;

RegionMgr* RegionMgr::instance() {
    if (!manager) {
        manager = new RegionMgr();
    }
    return manager;
}

RegionMgr::RegionMgr() = default;

RegionMgr::~RegionMgr() = default;

void RegionMgr::add(const std::string& name, Region* region) {
    region_pool[name] = region;
}

Region* RegionMgr::find(const std::string& name) {
    return region_pool[name];
}

void RegionMgr::on_update(float delta) {
    for (auto& pair : region_pool) {
        pair.second->on_update(delta);
    }
}

void RegionMgr::on_render(SDL_Renderer* renderer) {
    for (auto& pair : region_pool) {
        pair.second->on_render(renderer);
    }
}

void RegionMgr::on_input(const SDL_Event& event) {
    switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT) {
                for (auto& pair : region_pool) {
                    SDL_Point pos_cursor = { event.motion.x, event.motion.y };
                    if (SDL_PointInRect(&pos_cursor, &pair.second->get_rect())) {
                        pair.second->on_cursor_down();
                    }
                }
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT) {
                for (auto& pair : region_pool) {
                    SDL_Point pos_cursor = { event.motion.x, event.motion.y };
                    if (SDL_PointInRect(&pos_cursor, &pair.second->get_rect())) {
                        pair.second->on_cursor_up();
                    }
                }
            }
            break;
    }
}