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

#include "Logger.h"

#include <stdio.h>


void log(char *str)
{
    printf("[LOG] %s... OK!\n", str);
}

void logWParams(char *str, int param1, int param2)
{
    if (param1 != NULL && param2 != NULL)
        printf("[LOG] %s %dx%d... OK!\n", str, param1, param2);
    else if (param1 != NULL && param2 == NULL)
        printf("[LOG] %s %d... OK!\n", str, param1);
    else
        printf("[LOG] %s... OK!\n", str);
}

int logError(char *str)
{
    printf("[ERROR] %s\n", str);
    return 1;
}

int logSDLError(char *str, const char *strSDL, int exit_status_1_bool)
{
    printf("[ERROR] %s: %s\n", str, strSDL);
    if (exit_status_1_bool) return 1;
}
