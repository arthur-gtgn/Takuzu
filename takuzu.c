//
// Created by Arthur Gatignol on 18/04/2022.
//

#include "takuzu.h"


int* gen_grid(const int *grid_size)
{
    int n = *grid_size;
    int* T = (int*) malloc(n * n * sizeof(int));

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            *(T + i*n + j) = 0;
        }
    }

    return T;
}

void check_grid(const int* *grid, const int *grid_size)
{
    int n = *grid_size;
    printf("The elements in the array are: \n");
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ", *(*grid + i*n + j));
        }
        printf("\n");
    }
}

void menu()
{

    int mode_choice=0;

    printf("Welcome to the game of Takuzu\n");
    printf("You can choose between three options: \n");
    printf("1. Solve a grid yourself\n");
    printf("2. Let the AI solve a Takuzu grid\n");
    printf("3. Generate a Takuzu grid\n");

    printf("Which option are you choosing?\n");
    scanf("%d", &mode_choice);

    while (mode_choice < 1 || mode_choice > 3)
    {
        printf("Your choice is invalid, please enter a number between 1 and 3\n");
        scanf("%d", &mode_choice);
    }

    if (mode_choice == 1)
    {
        printf("You have chosen to solve a grid yourself.\n");

        choose_grid();

    }
    else if (mode_choice == 2)
    {
        printf("You want the AI to solve a grid.");

        choose_grid();
    }
    else
    {
        printf("You want to generate a grid.");

        int grid_size = choose_grid();

        int* T = gen_grid(&grid_size);

        check_grid((const int **) &T, &grid_size);
    }
}

int choose_grid() {
    int grid_size_choice = 0;
    int grid_size=0;

    printf("What kind of grid do you want to solve?\n");
    printf("1. 4x4 grid\n");
    printf("2. 8x8 grid\n");
    printf("Please enter 1 or 2.");

    scanf("%d", &grid_size_choice);

    while (grid_size_choice < 1 || grid_size_choice > 2) {
        printf("Your choice is invalid, please enter a number between 1 and 2\n");
        scanf("%d", &grid_size_choice);
    }

    if (grid_size_choice == 1)
    {
        grid_size = 4;
    }
    else
    {
        grid_size = 8;
    }

    return grid_size;
}
