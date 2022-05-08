//
// Created by Arthur Gatignol on 18/04/2022.
//

#include "takuzu.h"

void request(int* solution[4][4], int* game_grid[4][4]) {
    int g=0, h=0, val=0;
    printf("\nPlease enter the row number and the column number of the box you want to change: \n");

    printf("Row number: ");
    scanf("%d", &g);

    while (g < 1 || g > 4) {
        printf("Please enter a number between 1 and 4");
        scanf("%d", g);
    }

    printf("\nColumn number: ");
    scanf("%d", &h);

    while (h < 1 || h > 4) {
        printf("\nPlease enter a number between 1 and 4");
        scanf("%d", h);
    }


    printf("\nWhich value do you want to enter: ");
    scanf("%d", &val);

    while (val < 0 || val > 1){
        printf("\nPlease only enter 1 or 0.");
        scanf("%d", &val);
    }

    check_val(game_grid, val, g, h);

    game_grid[g-1][h-1] = val;

    printf("\n");

    display_grid(game_grid);

    if (game_grid[g-1][h-1] == solution[g-1][h-1]) {
        printf("\nYour move is correct!");
    } else {
        printf("Your move is valid.");


    }
}

void check_val(int* grid[4][4], int value, int x, int y) {
    int count0_row = 0, count1_row = 0, count0_column = 0, count1_column = 0;

    for (int i=0;i<4;i++) {
        if (grid[i][y-1] == 0) {
            count0_row++;
        } else if (grid[i][y-1] == 1) {
            count1_row++;
        }
    }

    for (int j=0; j<4; j++) {
        if (grid[x-1][j] == 0) {
            count0_column++;
        } else if (grid[x-1][j] == 1) {
            count1_column++;
        }
    }

    int new_val = value;

    if (count0_column > 2 || count0_row > 2) {
        printf("Your move is not valid.\n");
        while (new_val == value) {
            printf("Please enter a new value: ");
            scanf("%d", &new_val);
        }

    } else if (count1_row > 2 || count1_column > 2) {
        printf("Your move is not valid.\n");
        while (new_val == value) {
            printf("Please enter a new value: ");
            scanf("%d", &new_val);
        }
    }
}

void fill_grid(int* solution[4][4], int* mask[4][4], int* grid[4][4]) {

    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (mask[i][j] == 1) {
                grid[i][j] = solution[i][j];
            } else {
                grid[i][j] = -1;
            }
        }
    }
}

void display_grid(int* grid[4][4]) {
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (grid[i][j] == -1) {
                printf(". ");
            } else {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int check_equal_grid(int* grid1[4][4], int* grid2[4][4]) {
    for (int i=0; i<4; i++) {
        for (int j=0;j<4;j++) {
            if (grid1[i][j] != grid2[i][j]) {
                return 0;
            }
        }
    }
}

_Noreturn void menu()
{

    int* solution1[4][4] = {{1, 0, 0, 1},{1, 0, 1, 0},{0, 1, 1, 0},{0,1,0,1}};
    int* mask1[4][4] = {{1,0,0,0},{0,0,1,0},{1,0,1,1},{0,1,0,0}};

    int* game_grid1[4][4];


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
        printf("Here is the grid: \n\n");


        fill_grid(solution1,mask1,game_grid1);

        display_grid(game_grid1);

        while (0 == check_equal_grid(game_grid1, solution1)) {
            request(solution1, game_grid1);
        }

        printf("You have solved the grid!");


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
