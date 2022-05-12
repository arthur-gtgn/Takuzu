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

void fill_grid(const int* solution, const int* mask, int* grid, int size);

void request(const int* solution, int* game_grid, int life, int size);

void display_grid(int* grid, int size);

int check_val(int* grid, int value, int x, int y, int size);

int check_equal_grid(const int* grid1, const int* grid2, int size);

int check_row(int grid[N][N], int row);

void check_rows(int* grid[N][N]);

void check_columns(int* grid[N][N]);

void solve_grid4(int* *solution, int* *mask, int* *game_grid);

#endif //TAKUZU_TAKUZU_H
