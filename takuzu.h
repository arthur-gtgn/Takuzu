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

void fill_grid4(int* *solution, int* *mask, int* *grid);

void request(int* *solution, int* *game_grid, int life);

void display_grid4(int* *grid);

void display_grid8(int* grid[8][8]);

int check_val(int* grid[N][N], int value, int x, int y);

int check_equal_grid4(int* grid1[N][N], int* grid2[N][N]);

int check_equal_grid8(int* grid1[8][8], int* grid2[8][8]);

void request8(int* solution[8][8], int* game_grid[8][8], int life);

int check_row(int grid[N][N], int row);

void check_rows(int* grid[N][N]);

void check_columns(int* grid[N][N]);

void solve_grid4(int* *solution, int* *mask, int* *game_grid);

#endif //TAKUZU_TAKUZU_H
