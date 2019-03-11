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

#include "Number.h"

#include <time.h>
#include <string.h>

#include "../es.rocammo.bingo.utils/Logger.h"
#include "../es.rocammo.bingo.graphics/Window.h"
#include "../es.rocammo.bingo.graphics/Font.h"

void generate  (int matrix[3][9]);

void renderNum()
{
    srand(time(NULL));

    generate(matrix);

    /* ==== Comprobacion por consola ==== */
    printf("\n%c", 218);
    for (i = 0; i < 43; i++) {
        printf("%c", 196);
    }
    printf("%c\n", 191);
    int pos;
    for (i = 0; i < 3; i++) {
        printf("|");
        for (j = 0, pos = 1; j < 9; j++, pos++) {
            if (matrix[i][j] == 0 && j != 0) {
                printf("  %d |", matrix[i][j]);
            }
            else
                printf(" %d |", matrix[i][j]);
            if (pos == 9) printf("\n");
        }
    }
    printf("%c", 192);
    for (i = 0; i < 43; i++) {
        printf("%c", 196);
    }
    printf("%c\n", 217);
    /* ================================== */

    /* ====  Mostramos por pantalla  ==== */
    setFontSize(24);
    int fontSize = getFontSize();
    initFnt("res/font.ttf", fontSize);
    SDL_Color color = { 32, 32, 32 };

    char str[100];

    int scale = 2;
    int cellSize = 21 * scale;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (j==0)
            {
                texX = 30 + (cellSize * j);
                texY = 20 + (cellSize * i);
            }
            else
            {
                texX = 24 + (cellSize * j);
                texY = 20 + (cellSize * i);
            }
            sprintf(str,"%ld", matrix[i][j]);
            drawText(str, texX, texY, color);
        }
    }
    /* ================================== */
}

void generate(int matrix[3][9])
{
    // Rellena numeros y comprueba que no se repitan en una misma columna
    for (j = 0; j < 9; j++) {
        do {
            for (i = 0; i < 3; i++) {
                matrix[i][j] = rand() % (9 + 1 - 0) + 0;
                switch (j)
                {
                    case 1:
                        matrix[i][j] += 10;
                        break;
                    case 2:
                        matrix[i][j] += 20;
                        break;
                    case 3:
                        matrix[i][j] += 30;
                        break;
                    case 4:
                        matrix[i][j] += 40;
                        break;
                    case 5:
                        matrix[i][j] += 50;
                        break;
                    case 6:
                        matrix[i][j] += 60;
                        break;
                    case 7:
                        matrix[i][j] += 70;
                        break;
                    case 8:
                        matrix[i][j] += 80;
                        break;
                }
            }
        } while(matrix[0][j] == matrix[1][j] ||
                    matrix[1][j] == matrix[2][j] ||
                    matrix[0][j] == matrix[2][j]);
    }
}
