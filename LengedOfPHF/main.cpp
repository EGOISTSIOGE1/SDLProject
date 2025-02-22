#define SDL_MAIN_HANDLED

#include "res_mgr.h"
#include "cursor_mgr.h"
#include "region_mgr.h"

#include "delivery_driver.h"
#include "cola_bundle.h"
#include "sprite_bundle.h"
#include "tb_bundle.h"
#include "mb_box_bundle.h"
#include "bc_box_bundle.h"
#include "rcp_box_bundle.h"
#include "microwave_oven.h"
#include "takeout_box.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <chrono>
#include <thread>

#pragma comment(linker, "/subsystem::windows /entry:mainCRTStartup")

// 初始化游戏界面可交互区域
void init_regions() {
    RegionMgr::instance()->add("delivery_driver_1", new DeliveryDriver(385, 142));
    RegionMgr::instance()->add("delivery_driver_2", new DeliveryDriver(690, 142));
    RegionMgr::instance()->add("delivery_driver_3", new DeliveryDriver(995, 142));

    RegionMgr::instance()->add("cola_bundle", new ColaBundle(300, 390));
    RegionMgr::instance()->add("sprite_bundle", new SpriteBundle(425, 390));
    RegionMgr::instance()->add("tb_bundle", new TbBundle(550, 418));

    RegionMgr::instance()->add("mb_box_bundle", new MbBoxBundle(225, 520));
    RegionMgr::instance()->add("bc_box_bundle", new BcBoxBundle(395, 520));
    RegionMgr::instance()->add("rcp_box_bundle", new RcpBoxBundle(565, 520));

    RegionMgr::instance()->add("microwave_oven_1", new MicrowaveOven(740, 400));
    RegionMgr::instance()->add("microwave_oven_2", new MicrowaveOven(975, 400));

    RegionMgr::instance()->add("takeout_box_1", new TakeoutBox(830, 580));
    RegionMgr::instance()->add("takeout_box_2", new TakeoutBox(935, 580));
    RegionMgr::instance()->add("takeout_box_3", new TakeoutBox(1040, 580));
    RegionMgr::instance()->add("takeout_box_4", new TakeoutBox(1145, 580));
}

void on_update(float delta) {
    RegionMgr::instance()->on_update(delta);
}

void on_render(SDL_Renderer* renderer) {
    // 绘制背景图
    SDL_Rect rect_background = { 0, 0, 1280, 720 };
    SDL_RenderCopy(renderer, ResMgr::instance()->find_texture("background"), nullptr, &rect_background);

    RegionMgr::instance()->on_render(renderer);
    CursorMgr::instance()->on_render(renderer);
}

int main(int argc, const char** argv) {
    using namespace std::chrono;

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3);
    TTF_Init();

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    SDL_Window* window = SDL_CreateWindow(u8"《拼好饭传奇》", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_ShowCursor(SDL_DISABLE);

    ResMgr::instance()->load(renderer);

    init_regions();

    Mix_PlayChannel(-1, ResMgr::instance()->find_audio("bgm"), -1);

    SDL_Event event;
    bool is_quit = false;

    const nanoseconds frame_duration(1000000000 / 144);
    steady_clock::time_point last_tick = steady_clock::now();

    while (!is_quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:  is_quit = true;
                break;
            }
            CursorMgr::instance()->on_input(event);
            RegionMgr::instance()->on_input(event);
        }

        steady_clock::time_point frame_start = steady_clock::now();
        duration<float> delta = duration<float>(frame_start - last_tick);

        on_update(delta.count());

        SDL_RenderClear(renderer);
        on_render(renderer);
        SDL_RenderPresent(renderer);

        last_tick = frame_start;
        nanoseconds sleep_duration = frame_duration - (steady_clock::now() - frame_start);
        if (sleep_duration > nanoseconds(0)) {
            std::this_thread::sleep_for(sleep_duration);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}