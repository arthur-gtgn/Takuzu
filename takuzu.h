//
// Created by Arthur Gatignol on 18/0N/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define N 4

_Noreturn void menu();
int choose_grid();

int* gen_grid(const int *grid_size);

void check_grid(const int* *grid, const int *grid_size);

void fill_grid4(int* solution[N][N], int* mask[N][N], int* grid[N][N]);

void fill_grid8(int* solution[8][8], int* mask[8][8], int* grid[8][8]);

void request(int* solution[N][N], int* game_grid[N][N]);

void display_grid4(int* grid[N][N]);

void display_grid8(int* grid[8][8]);

int check_val(int* grid[N][N], int value, int x, int y);

int check_equal_grid4(int* grid1[N][N], int* grid2[N][N]);

int check_equal_grid8(int* grid1[8][8], int* grid2[8][8]);

void request8(int* solution[8][8], int* game_grid[8][8]);

int check_row(int grid[N][N], int row);

void check_rows(int* grid[N][N]);


#endif //TAKUZU_TAKUZU_H
