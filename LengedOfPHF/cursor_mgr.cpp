#include "res_mgr.h"
#include "cursor_mgr.h"

CursorMgr* CursorMgr::manager = nullptr;

CursorMgr* CursorMgr::instance() {
    if (!manager) {
        manager = new CursorMgr();
    }
    return manager;
}

CursorMgr::CursorMgr() = default;

CursorMgr::~CursorMgr() = default;

void CursorMgr::on_input(const SDL_Event& event) {
    switch (event.type) {
        case SDL_MOUSEMOTION: {
            pos_cursor.x = event.motion.x;
            pos_cursor.y = event.motion.y;
        }
        break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT) {
                is_mouse_lbtn_down = true;
                switch (rand() % 3) {
                    case 0: Mix_PlayChannel(-1, ResMgr::instance()->find_audio("click_1"), 0); break;
                    case 1: Mix_PlayChannel(-1, ResMgr::instance()->find_audio("click_2"), 0); break;
                    case 2: Mix_PlayChannel(-1, ResMgr::instance()->find_audio("click_3"), 0); break;
                }
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT) {
                is_mouse_lbtn_down = false;
            }
            break;
    }
}

void CursorMgr::on_render(SDL_Renderer* renderer) {
    // 根据当前抓取的餐品不同选择不同的餐品纹理进行绘制
    SDL_Texture* texture_picked = nullptr;
    switch (meal_picked) {
        case Meal::None:                break;
        case Meal::Cola:                texture_picked = ResMgr::instance()->find_texture("cola");              break;
        case Meal::Sprite:              texture_picked = ResMgr::instance()->find_texture("sprite");            break;
        case Meal::BraisedChicken_Hot:  texture_picked = ResMgr::instance()->find_texture("bc_hot_picked");     break;
        case Meal::BraisedChicken_Cold: texture_picked = ResMgr::instance()->find_texture("bc_cold_picked");    break;
        case Meal::MeatBall_Hot:        texture_picked = ResMgr::instance()->find_texture("mb_hot_picked");     break;
        case Meal::MeatBall_Cold:       texture_picked = ResMgr::instance()->find_texture("mb_cold_picked");    break;
        case Meal::RedCookedPork_Hot:   texture_picked = ResMgr::instance()->find_texture("rcp_hot_picked");    break;
        case Meal::RedCookedPork_Cold:  texture_picked = ResMgr::instance()->find_texture("rcp_cold_picked");   break;
        case Meal::BraisedChicken_Box:  texture_picked = ResMgr::instance()->find_texture("bc_box");            break;
        case Meal::MeatBall_Box:        texture_picked = ResMgr::instance()->find_texture("mb_box");            break;
        case Meal::RedCookedPork_Box:   texture_picked = ResMgr::instance()->find_texture("rcp_box");           break;
        case Meal::TakeoutBox:          texture_picked = ResMgr::instance()->find_texture("tb_picked");         break;
    }
    if (texture_picked) {
        SDL_Rect rect_picked = { pos_cursor.x, pos_cursor.y, 0, 0 };
        SDL_QueryTexture(texture_picked, nullptr, nullptr, &rect_picked.w, &rect_picked.h);
        SDL_RenderCopy(renderer, texture_picked, nullptr, &rect_picked);
    }

    // 根据当前鼠标左键状态选择不同的光标纹理进行绘制
    SDL_Rect rect_cursor = { pos_cursor.x, pos_cursor.y, 64, 64 };
    SDL_Texture* texture_cursor = ResMgr::instance()->find_texture(is_mouse_lbtn_down ? "cursor_down" : "cursor_idle");
    SDL_RenderCopy(renderer, texture_cursor, nullptr, &rect_cursor);
}

void CursorMgr::set_picked(Meal meal) {
    meal_picked = meal;
}

Meal CursorMgr::get_picked() {
    return meal_picked;
}