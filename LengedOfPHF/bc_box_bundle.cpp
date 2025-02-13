#include "bc_box_bundle.h"

#include "res_mgr.h"
#include "cursor_mgr.h"

void BcBoxBundle::on_cursor_up() {
    if (CursorMgr::instance()->get_picked() == Meal::BraisedChicken_Box) {
        CursorMgr::instance()->set_picked(Meal::None);
    }
}

void BcBoxBundle::on_cursor_down() {
    if (CursorMgr::instance()->get_picked() == Meal::None) {
        CursorMgr::instance()->set_picked(Meal::BraisedChicken_Box);
    }
}

void BcBoxBundle::on_render(SDL_Renderer* renderer) {
    static SDL_Texture* texture = ResMgr::instance()->find_texture("bc_box_bundle");
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}