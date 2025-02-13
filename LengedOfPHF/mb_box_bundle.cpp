#include "mb_box_bundle.h"

#include "res_mgr.h"
#include "cursor_mgr.h"

void MbBoxBundle::on_cursor_up() {
    if (CursorMgr::instance()->get_picked() == Meal::MeatBall_Box) {
        CursorMgr::instance()->set_picked(Meal::None);
    }
}

void MbBoxBundle::on_cursor_down() {
    if (CursorMgr::instance()->get_picked() == Meal::None) {
        CursorMgr::instance()->set_picked(Meal::MeatBall_Box);
    }
}

void MbBoxBundle::on_render(SDL_Renderer* renderer) {
    static SDL_Texture* texture = ResMgr::instance()->find_texture("mb_box_bundle");
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}