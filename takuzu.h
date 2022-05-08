//
// Created by Arthur Gatignol on 18/04/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

_Noreturn void menu();
int choose_grid();

int* gen_grid(const int *grid_size);

void check_grid(const int* *grid, const int *grid_size);

void fill_grid(int* solution[4][4], int* mask[4][4], int* grid[4][4]);

void request(int* solution[4][4], int* game_grid[4][4]);

void display_grid(int* grid[4][4]);

void check_val(int* grid[4][4], int value, int x, int y);

int check_equal_grid(int* grid1[4][4], int* grid2[4][4]);


#endif //TAKUZU_TAKUZU_H
