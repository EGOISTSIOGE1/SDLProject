#ifndef _RCP_BOX_BUNDLE_H_
#define _RCP_BOX_BUNDLE_H_

#include "region.h"

class RcpBoxBundle : public Region {
public:
    RcpBoxBundle(int x, int y) : Region({ x, y, 160, 88 }) {}
    ~RcpBoxBundle() = default;

    void on_cursor_up() override;
    void on_cursor_down() override;
    void on_render(SDL_Renderer* renderer) override;
    
};

#endif // !_RCP_BOX_BUNDLE_H_