#include "tb_bundle.h"

#include "res_mgr.h"
#include "cursor_mgr.h"

void TbBundle::on_cursor_up() {
    if (CursorMgr::instance()->get_picked() == Meal::TakeoutBox) {
        CursorMgr::instance()->set_picked(Meal::None);
    }
}

void TbBundle::on_cursor_down() {
    if (CursorMgr::instance()->get_picked() == Meal::None) {
        CursorMgr::instance()->set_picked(Meal::TakeoutBox);
    }
}

void TbBundle::on_render(SDL_Renderer* renderer) {
    static SDL_Texture* texture = ResMgr::instance()->find_texture("tb_bundle");
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}