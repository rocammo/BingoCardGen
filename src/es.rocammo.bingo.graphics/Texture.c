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

#include "Texture.h"

#include <SDL_image.h>

#include "../es.rocammo.bingo.utils/Logger.h"
#include "../es.rocammo.bingo.graphics/Window.h"


void initTex() {
	if(texture) {
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
}

int loadTex(SDL_Renderer *renderer, char *path) {
	if(renderer == NULL) {
		logError("Bad SDL renderer passed!");
		return 0;
	}

	renderer = renderer;
	path     = path;

	SDL_Surface* tempSurface = IMG_Load(path);
	if(tempSurface == NULL) {
		printf("[ERROR] Unable to load image : %s : %s\n", path, IMG_GetError());
		return 0;
	}

    // Convert SDL surface to a texture
	if((texture = SDL_CreateTextureFromSurface(renderer, tempSurface)) == NULL) {
		printf("[ERROR] Unable to create SDL Texture : %s : %s\n", path, IMG_GetError());
		return 0;
	}

    // Grab dimensions
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	//printf("Texture Dimensions: %s : %d %d", path, width, height);

	SDL_FreeSurface(tempSurface);

	return 1;
}

void renderTex(int x, int y, int width, int height) {
	SDL_Rect destination = {x, y, width, height};

	SDL_RenderCopy(renderer, texture, NULL, &destination);
}


int getWidth()  { return width;  }
int getHeight() { return height; }
