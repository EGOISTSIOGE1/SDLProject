#include "sprite_bundle.h"

#include "res_mgr.h"
#include "cursor_mgr.h"

void SpriteBundle::on_cursor_up() {
    if (CursorMgr::instance()->get_picked() == Meal::Sprite) {
        CursorMgr::instance()->set_picked(Meal::None);
    }
}

void SpriteBundle::on_cursor_down() {
    if (CursorMgr::instance()->get_picked() == Meal::None) {
        CursorMgr::instance()->set_picked(Meal::Sprite);
    }
}

void SpriteBundle::on_render(SDL_Renderer* renderer) {
    static SDL_Texture* texture = ResMgr::instance()->find_texture("sprite_bundle");
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}