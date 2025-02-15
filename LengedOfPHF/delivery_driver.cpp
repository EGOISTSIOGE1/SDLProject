#include "delivery_driver.h"

#include "res_mgr.h"
#include "cursor_mgr.h"

#include <algorithm>

DeliveryDriver::DeliveryDriver(int x, int y) : Region({ x, y, 192, 272 }) {
    timer_refresh.set_one_shot(true);
    timer_refresh.set_on_timeout([&]() {
        is_waiting = true;
    });
    refresh();
}

void DeliveryDriver::on_cursor_up() {
    if (!is_waiting) return ;

    Meal meal_held = CursorMgr::instance()->get_picked();
    if (meal_held != Meal::None && check_and_place(meal_held)) {
        CursorMgr::instance()->set_picked(Meal::None);
        Mix_PlayChannel(-1, ResMgr::instance()->find_audio("complete"), 0);
    }
}

void DeliveryDriver::on_update(float delta) {
    // 如果还没有在等待，就更新刷新定时器
    if (!is_waiting) {
        timer_refresh.on_update(delta);
        return ;
    }

    // 累加等待时间检查是否超时
    time_waited += delta;
    if (time_waited >= time_waited_limit) {
        refresh();
        return ;
    }

    // 检查餐品是否完整
    if (std::count(status_list.begin(), status_list.end(), Status::Waiting) == 0) {
        refresh();
    }
}

void DeliveryDriver::on_render(SDL_Renderer* renderer) {
    if (!is_waiting) return ;

    // 绘制外卖员
    SDL_Texture* texture = ResMgr::instance()->find_texture(is_meituan ? "meituan" : "eleme");
    SDL_RenderCopy(renderer, texture, nullptr, &rect);

    // 绘制耐心条
    SDL_Rect rect_border = { rect.x - 35, rect.y + 15, 40, 160 };
    SDL_RenderCopy(renderer, ResMgr::instance()->find_texture("patience_border"), nullptr, &rect_border);
    SDL_Rect rect_content_src = { 0, 0, rect_border.w, 0 };
    SDL_Rect rect_content_dst = { rect_border.x, 0, rect_border.w, 0 };
    rect_content_dst.h = (int)(rect_border.h * (time_waited / time_waited_limit));
    rect_content_dst.y = rect_border.y + rect_border.h - rect_content_dst.h;        // 边框与内容物图片底部对齐
    rect_content_src.h = rect_content_dst.h;
    rect_content_src.y = rect_border.h - rect_content_src.h;                        // 从底部开始裁剪内容物图片
    SDL_RenderCopy(renderer, ResMgr::instance()->find_texture("patience_content"), &rect_content_src, &rect_content_dst);

    // 绘制餐品清单
    SDL_Rect rect_bubble = { rect.x + 175, rect.y + 55, 76, 139 };
    SDL_RenderCopy(renderer, ResMgr::instance()->find_texture("bubble"), nullptr, &rect_bubble);
    for (int i = 0; i < num_dish; i++) {    // 绘制菜品
        SDL_Texture* texture_meal = nullptr;
        switch (meal_list[i]) {
            case Meal::BraisedChicken_Hot:  texture_meal = ResMgr::instance()->find_texture("bc_icon"); break;
            case Meal::MeatBall_Hot:        texture_meal = ResMgr::instance()->find_texture("mb_icon"); break;
            case Meal::RedCookedPork_Hot:   texture_meal = ResMgr::instance()->find_texture("rcp_icon"); break;
        }
        SDL_Rect rect_meal = { rect_bubble.x + 18, rect_bubble.y + 32 * i + 5, 45, 25 };
        SDL_SetTextureAlphaMod(texture_meal, (Uint8)((status_list[i] == Status::Waiting ? 1.0f : 0.35f) * 255));
        SDL_RenderCopy(renderer, texture_meal, nullptr, &rect_meal);
    }
    for (int i = num_dish; i < meal_list.size(); i++) {     // 绘制饮料
        SDL_Texture* texture_drink = nullptr;
        switch (meal_list[i]) {
            case Meal::Cola:    texture_drink = ResMgr::instance()->find_texture("cola_icon"); break;
            case Meal::Sprite:  texture_drink = ResMgr::instance()->find_texture("sprite_icon"); break;
        }
        SDL_Rect rect_drink = { rect_bubble.x + 18, 0, 20, 26 };
        bool is_left_side = ((i - num_dish) % 2 == 0);
        if (!is_left_side) rect_drink.x += 32;  // 饮料可以并排放置
        rect_drink.y = rect_bubble.y + 32 * num_dish + 10 + ((i - num_dish) / 2) * 28;
        SDL_SetTextureAlphaMod(texture_drink, (Uint8)((status_list[i] == Status::Waiting ? 1.0f : 0.35f) * 255));
        SDL_RenderCopy(renderer, texture_drink, nullptr, &rect_drink);
    }
}

void DeliveryDriver::refresh() {
    // 重制状态
    time_waited = 0;
    is_waiting = false;
    meal_list.clear();
    status_list.clear();
    num_drink = 0, num_dish = 0;

    // 随机刷新时间
    timer_refresh.set_wait_time(rand() % 10 + 10.0f);
    timer_refresh.restart();

    // 随机外卖员形象
    is_meituan = (rand() % 2 == 0);

    // 随机餐品内容
    num_drink = (rand() % 8);                           // 随机饮料数 0～7
    int num_line = (int)std::ceil(num_drink / 2.0f);    // 计算饮料所占的行数
    num_dish = 4 - num_line;                            // 计算剩余的菜品个数
    for (int i = 0; i < num_dish; i++) {                // 随机菜品
        switch (rand() % 3) {
            case 0: meal_list.push_back(Meal::BraisedChicken_Hot);  break;
            case 1: meal_list.push_back(Meal::MeatBall_Hot);        break;
            case 2: meal_list.push_back(Meal::RedCookedPork_Hot);   break;
        }
    }
    for (int i = 0; i < num_drink; i++) {               // 随机饮料
        switch (rand() % 2) {
            case 0: meal_list.push_back(Meal::Cola);    break;
            case 1: meal_list.push_back(Meal::Sprite);  break;
        }
    }

    // 更新餐品状态
    status_list.assign(meal_list.size(), Status::Waiting);
}

bool DeliveryDriver::check_and_place(Meal target) {
    if (!is_waiting) return false;

    for (int i = 0; i < meal_list.size(); i++) {
        if (status_list[i] == Status::Waiting && meal_list[i] == target) {
            status_list[i] = Status::Completed;
            return true;
        }
    }

    return false;
}