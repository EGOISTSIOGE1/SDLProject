cmake_minimum_required(VERSION 3.31.0)
project(REchicken)

set(CMAKE_CXX_STANDARD 11)

set(SDL_H /opt/homebrew/Cellar/sdl2/2.30.9/include) # 这个SDL开发包的路径，可以通过brew info sdl2查出来
include_directories(${SDL_H}) # 添加SDL头文件搜索路径
set(SDL_LIB /opt/homebrew/Cellar/sdl2/2.30.9/lib/libSDL2-2.0.0.dylib)
link_libraries(${SDL_LIB}) # 增加SDL链接库目录

set(SDL_IMAGE_H /opt/homebrew/Cellar/sdl2_image/2.8.2_2/include) # 这个SDL开发包的路径，可以通过brew info sdl2查出来
include_directories(${SDL_IMAGE_H}) # 添加SDL头文件搜索路径
set(SDL_IMAGE_LIB /opt/homebrew/Cellar/sdl2_image/2.8.2_2/lib/libSDL2_image-2.0.0.dylib)
link_libraries(${SDL_IMAGE_LIB}) # 增加SDL链接库目录

set(SDL_MIXER_H /opt/homebrew/Cellar/sdl2_mixer/2.8.0/include) # 这个SDL开发包的路径，可以通过brew info sdl2查出来
include_directories(${SDL_MIXER_H}) # 添加SDL头文件搜索路径
set(SDL_MIXER_LIB /opt/homebrew/Cellar/sdl2_mixer/2.8.0/lib/libSDL2_mixer-2.0.0.dylib)
link_libraries(${SDL_MIXER_LIB}) # 增加SDL链接库目录

set(SDL_TTF_H /opt/homebrew/Cellar/sdl2_ttf/2.22.0/include) # 这个SDL开发包的路径，可以通过brew info sdl2查出来
include_directories(${SDL_TTF_H}) # 添加SDL头文件搜索路径
set(SDL_TTF_LIB /opt/homebrew/Cellar/sdl2_ttf/2.22.0/lib/libSDL2_ttf-2.0.0.dylib)
link_libraries(${SDL_TTF_LIB}) # 增加SDL链接库目录

# set(SDL_GFX_H /opt/homebrew/Cellar/sdl2_gfx/1.0.4/include) # 这个SDL开发包的路径，可以通过brew info sdl2查出来
# include_directories(${SDL_GFX_H}) # 添加SDL头文件搜索路径
# set(SDL_GFX_LIB /opt/homebrew/Cellar/sdl2_gfx/1.0.4/lib/libSDL2_gfx-2.0.0.dylib)
# link_libraries(${SDL_GFX_LIB}) # 增加SDL链接库目录

add_executable(REchicken main.cpp atlas.h vector2.h timer.h camera.h animation.h bullet.h chicken.h chicken_fast.h chicken_medium.h chicken_slow.h)
