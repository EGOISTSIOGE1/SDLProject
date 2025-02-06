#include "cola_bundle.h"

#include "res_mgr.h"
#include "cursor_mgr.h"

void ColaBundle::on_cursor_up() {
    if (CursorMgr::instance()->get_picked() == Meal::Cola) {
        CursorMgr::instance()->set_picked(Meal::None);
    }
}

void ColaBundle::on_cursor_down() {
    if (CursorMgr::instance()->get_picked() == Meal::None) {
        CursorMgr::instance()->set_picked(Meal::Cola);
    }
}

void ColaBundle::on_render(SDL_Renderer* renderer) {
    static SDL_Texture* texture = ResMgr::instance()->find_texture("cola_bundle");
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}