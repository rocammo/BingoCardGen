/*
 * This file is part of BingoCardGen.
 * Copyright (C) 2018 Rodrigo Casamayor.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Window.h"

#include <SDL_timer.h>

#include "../es.rocammo.bingo.utils/Logger.h"


void initWindow(void)
{
    // attempt to initialize graphics and timer system
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
        logSDLError("initializing SDL", SDL_GetError(), 1);
    log("initializing SDL");

    window = SDL_CreateWindow(WINDOW_TITLE,
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!window)
    {
        logSDLError("creating window", SDL_GetError(), 0);
        SDL_Quit();
	    return 1;
    }
    logWParams("creating window", WINDOW_WIDTH, WINDOW_HEIGHT);

    // create a renderer, which sets up the graphics hardware
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    renderer = SDL_CreateRenderer(window, -1, render_flags);
    if (!renderer)
    {
        logSDLError("creating renderer", SDL_GetError(), 0);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    log("creating renderer");
}
