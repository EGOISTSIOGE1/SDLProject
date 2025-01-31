#ifndef _CURSOR_MGR_H_
#define _CURSOR_MGR_H_

#include "meal.h"

#include <SDL2/SDL.h>

class CursorMgr {
public:
    static CursorMgr* instance();

    void on_input(const SDL_Event& event);
    void on_render(SDL_Renderer* renderer);

    void set_picked(Meal meal);
    Meal get_picked();

private:
    CursorMgr();
    ~CursorMgr();

private:
    static CursorMgr* manager;

    Meal meal_picked = Meal::None;      // 当前抓取的餐品
    SDL_Point pos_cursor = { 0 };       // 光标位置
    bool is_mouse_lbtn_down = false;    // 鼠标左键是否按下
};

#endif // !_CURSOR_MGR_H_