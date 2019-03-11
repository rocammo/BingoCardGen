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

#include "Blank.h"

#include <time.h>

#include "../es.rocammo.bingo.graphics/Window.h"
#include "../es.rocammo.bingo.graphics/Texture.h"


void randomize(int *vec);

void initBlank()
{
    initTex();
    loadTex(renderer, "res/null.png");
}

void renderBlank()
{
    srand(time(NULL));

    int scale = 2;
    int width = 15 * scale, height = 15 * scale;
    int cellSize = 21 * scale;

    int x, y;

    int aux1[4], aux2[4], aux3[4];
    randomize(aux1);
    randomize(aux2);
    randomize(aux3);

    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            y = 18 + (cellSize * i);
            switch(i) {
                case 0:
                    x = 22 + (cellSize * (aux1[j]));
                    break;
                case 1:
                    x = 22 + (cellSize * (aux2[j]));
                    break;
                case 2:
                    x = 22 + (cellSize * (aux3[j]));
                    break;
            }
            renderTex(x, y, width, height);
        }
    }
}

void randomize (int *vec)
{
    int i, j;

    // Guarda 4 numeros aleatorios distintos entre 0 y 8 en un vector
    for (i = 0; i < 4; i++)
    {
        // Genera numero aleatorio
        int num = rand() % (8 + 1 - 0) + 0;

        if (i > 0)
        {
            // Verifica si no se ha generado antes
            for (j = 0; j < i; j++)
                if (num == vec[j])
                {
                    num = rand() % (8 + 1 - 0) + 0;
                    j=-1;
                }
        }
        vec[i] = num;
    }
}
