#ifndef _MEAL_H_
#define _MEAL_H_

enum class Meal {
    None,               // 无
    Cola,               // 可乐
    Sprite,             // 雷碧
    BraisedChicken_Hot, // 黄焖鸡（热）
    BraisedChicken_Cold,// 黄焖鸡（冷）
    MeatBall_Hot,       // 肉丸（热）
    MeatBall_Cold,      // 肉丸（冷）
    RedCookedPork_Hot,  // 红烧肉（热）
    RedCookedPork_Cold, // 红烧肉（冷）

    BraisedChicken_Box, // 黄焖鸡（餐品盒）
    MeatBall_Box,       // 肉丸（餐品盒）
    RedCookedPork_Box,  // 红烧肉（餐品盒）

    TakeoutBox,         // 外卖盒
};

#endif // !_MEAL_H_