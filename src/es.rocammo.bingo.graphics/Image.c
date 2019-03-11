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

#include "Image.h"

#include <SDL_image.h>

#include "../es.rocammo.bingo.graphics/Window.h"
#include "../es.rocammo.bingo.utils/Logger.h"


void renderImage(char *path)
{
    surface = IMG_Load(path);
    if (!surface)
    {
        logSDLError("creating surface", SDL_GetError(), 0);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // load the image data into the graphics hardware's memory
    tex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!tex)
    {
        logSDLError("creating texture", SDL_GetError(), 0);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // get and scale the dimensions of texture
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    dest.w *= 2;
    dest.h *= 2;

    // start sprite in center of screen
    x_pos = (WINDOW_WIDTH - dest.w) / 2;
    y_pos = (WINDOW_HEIGHT - dest.h) / 2;

    // set the positions in the struct
    dest.x = (int) x_pos;
    dest.y = (int) y_pos;
}
