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

#include "Font.h"

#include <SDL_ttf.h>

#include "../es.rocammo.bingo.utils/Logger.h"
#include "../es.rocammo.bingo.graphics/Window.h"


void initFnt(char *path, int size)
{
    if(text) {
		SDL_DestroyTexture(text);
		text = NULL;
	}

	size = fontSize;

    TTF_Init();
    if (TTF_Init()==-1)
        logSDLError("TTF_Init", TTF_GetError(), 0);
    font = TTF_OpenFont(path, size);
    if (font == NULL)
        logSDLError("TTF_OpenFont", TTF_GetError(), 0);
}

void drawText(char *str, float x, float y, SDL_Color color)
{
    message = TTF_RenderText_Solid(font, str, color);

    text = SDL_CreateTextureFromSurface(renderer, message);

    SDL_QueryTexture(text, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { (int) x, (int) y, texW, texH };

    SDL_RenderCopy(renderer, text, NULL, &dstrect);
    SDL_RenderPresent(renderer);

    SDL_FreeSurface(message);
}

void cleanFnt()
{
    TTF_CloseFont(font);
    TTF_Quit();
}

void setFontSize(int value) { fontSize = value; }
int getFontSize(){ return fontSize; }
