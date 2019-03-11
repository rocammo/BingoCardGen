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

#ifndef _FONT_H_
#define _FONT_H_

/* Includes */
#include <SDL.h>
#include <SDL_ttf.h>

/* SDL Callbacks */
TTF_Font* font;
SDL_Surface* message;
SDL_Texture* text;

/* Variables */
int fontSize;
int texX, texY;
int texW, texH;

/* Functions */
void initFnt(char *path, int size);
void cleanFnt();
void drawText(char *str, float x, float y, SDL_Color color);

void setFontSize(int value);
int getFontSize();

#endif // _FONT_H_
