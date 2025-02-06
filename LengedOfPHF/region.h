#ifndef _REGION_H_
#define _REGION_H_

#include <SDL2/SDL.h>

class Region {
public:
    Region() = default;
    Region(const SDL_Rect& rect) : rect(rect) {}

    ~Region() = default;

    virtual void on_update(float delta) {}
    virtual void on_render(SDL_Renderer* renderer) {}
    virtual void on_cursor_down() {}
    virtual void on_cursor_up() {}

    void set_rect(const SDL_Rect& rect) {
        this->rect = rect;
    }

    const SDL_Rect& get_rect() const {
        return rect;
    }

protected:
    SDL_Rect rect;
};

#endif // !_REGION_H_