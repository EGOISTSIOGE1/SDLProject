#ifndef _BC_BOX_BUNDLE_H_
#define _BC_BOX_BUNDLE_H_

#include "region.h"

class BcBoxBundle : public Region {
public:
    BcBoxBundle(int x, int y) : Region({ x, y, 160, 88 }) {}
    ~BcBoxBundle() = default;

    void on_cursor_up() override;
    void on_cursor_down() override;
    void on_render(SDL_Renderer* renderer) override;
    
};

#endif // !_BC_BOX_BUNDLE_H_