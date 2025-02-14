#ifndef _MICROWAVE_OVEN_H_
#define _MICROWAVE_OVEN_H_

#include "meal.h"
#include "timer.h"
#include "region.h"

class MicrowaveOven : public Region {
public:
    MicrowaveOven(int x, int y);
    ~MicrowaveOven() = default;

    void on_cursor_up() override;
    void on_cursor_down() override;
    void on_update(float delta) override;
    void on_render(SDL_Renderer* renderer) override;

private:
    Timer timer;                    // 工作定时器
    bool is_working = false;        // 当前是否正在工作
    Meal meal_target = Meal::None;  // 加工出的目标餐品

private:
    bool can_place(Meal target);

};

#endif // !_MICROWAVE_OVEN_H_