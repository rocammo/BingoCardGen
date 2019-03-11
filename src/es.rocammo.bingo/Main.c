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

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string.h>

#include "../es.rocammo.bingo.utils/Logger.h"
#include "../es.rocammo.bingo.graphics/Window.h"
#include "../es.rocammo.bingo.graphics/Image.h"
#include "../es.rocammo.bingo.graphics/Font.h"

#include "../es.rocammo.bingo.entities/Blank.h"
#include "../es.rocammo.bingo.entities/Number.h"


void init();
void render();
void update();
void screenshot();
void cleanup();

int main(int argc, char *argv[])
{
    init();
    render();
    update();
}

void init()
{
    initWindow();

    renderImage("res/carton_de_bingo.png");
    initBlank();
}

void update()
{
    // set to 1 when window close button is pressed
    int close_requested = 0;

    // animation loop
    while (!close_requested)
    {
        // process events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                close_requested = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_SPACE:
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_SPACE:
                    render();
                    screenshot();
                    log("Updating");
                    break;
                }
                break;
            }
        }

        // UPDATE METHOD (IF NEEDED)


        // wait 1/60th of a second
        SDL_Delay(1000/60);
    }

    // clean up resources before exiting
    cleanup();
}

void render()
{
    // clear the window
    SDL_RenderClear(renderer);

    // draw to the window
    SDL_RenderCopy(renderer, tex, NULL, &dest);
    renderNum();
    renderBlank();

    SDL_RenderPresent(renderer);
}

void screenshot() {
    static int count = 0;
    char name[50], num[3], ext[]=".png";

    SDL_Surface *sshot = SDL_CreateRGBSurface(0, WINDOW_WIDTH, WINDOW_HEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);

    strcpy(name, "bingo-card_");
    sprintf(num,"%ld", count);
    strcat(name, num);
    strcat(name, ext);

    IMG_SavePNG(sshot, name);
    SDL_FreeSurface(sshot);
    logWParams("Captura guardada", WINDOW_WIDTH, WINDOW_HEIGHT);

    count++;
}

void cleanup()
{
    cleanFnt();
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
