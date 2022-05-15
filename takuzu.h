//
// Created by Arthur Gatignol on 18/04/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

void game(int life);

int choose_grid();

void fill_grid(const int* solution, const int* mask, int* grid, int size);

int request(const int* solution, int* game_grid, int life, int size);

void display_grid(int* grid, int size);

int check_equal_grid(const int* grid1, const int* grid2, int size);

int check_val_4(int* grid);

int check_val_8(int* grid,int size);

int choose_mask();

void solve_grid(int* solution, int* grid, int size);

#endif //TAKUZU_TAKUZU_H
