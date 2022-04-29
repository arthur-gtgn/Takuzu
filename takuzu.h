//
// Created by Arthur Gatignol on 18/04/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void menu();
int choose_grid();

int* gen_grid(const int *grid_size);

void check_grid(const int* *grid, const int *grid_size);


#endif //TAKUZU_TAKUZU_H
