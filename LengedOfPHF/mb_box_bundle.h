#ifndef _MB_BOX_BUNDLE_H_
#define _MB_BOX_BUNDLE_H_

#include "region.h"

class MbBoxBundle : public Region {
public:
    MbBoxBundle(int x, int y) : Region({ x, y, 160, 88 }) {}
    ~MbBoxBundle() = default;

    void on_cursor_up() override;
    void on_cursor_down() override;
    void on_render(SDL_Renderer* renderer) override;
    
};

#endif // !_MB_BOX_BUNDLE_H_