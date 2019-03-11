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

#ifndef _IMAGE_H_
#define _IMAGE_H_

/* Includes */
#include <SDL.h>

/* SDL Callbacks */
SDL_Surface* surface;
SDL_Texture* tex;
SDL_Rect dest; // struct to hold the position and size of the sprite

/* Variables */
float x_pos;
float y_pos;

/* Functions */
void renderImage(char *path);

#endif // _IMAGE_H_
