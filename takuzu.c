//
// Created by Arthur Gatignol on 18/0N/2022.
//

/*
 * What is currently not working:
 *
 *      4x4:
 *          Si déjà deux 1 ou deux 0 -> on peut pas remplir valeur -> peut pas finir la grille
 *
 *      8x8:
 *          On peut mettre trois zéro à la suite
 *
 */

#include "takuzu.h"
#define N 4

void request(int* solution[N][N], int* game_grid[N][N], int life) {
    int g=0, h=0, val=0;
    printf("\nPlease enter the row number and the column number of the box you want to change: \n");

    printf("Row number: ");
    scanf("%d", &g);

    while (g < 1 || g > N) {
        printf("Please enter a number between 1 and N");
        scanf("%d", g);
    }

    printf("\nColumn number: ");
    scanf("%d", &h);

    while (h < 1 || h > N) {
        printf("\nPlease enter a number between 1 and N");
        scanf("%d", h);
    }


    printf("\nWhich value do you want to enter: ");
    scanf("%d", &val);

    while (val < 0 || val > 1){
        printf("\nPlease only enter 1 or 0.");
        scanf("%d", &val);
    }

    game_grid[g-1][h-1] = val;

    game_grid[g-1][h-1] = check_val(game_grid, val, g-1, h-1);

    printf("\n");

    display_grid4(game_grid);

    if (game_grid[g-1][h-1] == solution[g-1][h-1]) {
        printf("\nYour move is correct!");
    } else {
        printf("Your move is valid.");
        life++;

    }
}

void request8(int* solution[8][8], int* game_grid[8][8], int life) {
    int l = 0;
    int g=0, h=0, val=0;
    printf("\nPlease enter the row number and the column number of the box you want to change: \n");

    printf("Row number: ");
    scanf("%d", &g);

    while (g < 1 || g > 8) {
        printf("Please enter a number between 1 and N");
        scanf("%d", g);
    }

    printf("\nColumn number: ");
    scanf("%d", &h);

    while (h < 1 || h > 8) {
        printf("\nPlease enter a number between 1 and N");
        scanf("%d", h);
    }


    printf("\nWhich value do you want to enter: ");
    scanf("%d", &val);

    while (val < 0 || val > 1){
        printf("\nPlease only enter 1 or 0.");
        scanf("%d", &val);
    }

    game_grid[g-1][h-1] = val;

    game_grid[g-1][h-1] = check_val(game_grid, val, g-1, h-1);

    printf("\n");

    display_grid8(game_grid);

    if (game_grid[g-1][h-1] == solution[g-1][h-1]) {
        printf("\nYour move is correct!");
    } else {
        printf("Your move is valid.");
        life++;
    }
}

int check_val(int* grid[N][N], int value, int x, int y) {
    int count0_row = 0, count1_row = 0, count0_column = 0, count1_column = 0;

    for (int i=0;i<N;i++) {
        if (grid[i][y-1] == 0) {
            count0_row++;
        } else if (grid[i][y-1] == 1) {
            count1_row++;
        }
    }

    for (int j=0; j<N; j++) {
        if (grid[x-1][j] == 0) {
            count0_column++;
        } else if (grid[x-1][j] == 1) {
            count1_column++;
        }
    }

    int new_val = value;
    if (value==0) {
        if (count0_column >= 2 || count0_row >= 2) {
            printf("Your move is not valid.\n");
            printf("You can't put more than two 0 in a row.\n");
            printf("Above, below, to the left, to the right of a series of two 0's, there can only be one 1.\n");
            while (new_val == value) {
                printf("Please enter a new value: ");
                scanf("%d", &new_val);
            }
        }
    } else {
        if (count1_row >= 2 || count1_column >= 2) {
            printf("Your move is not valid.\n");
            printf("You can't put more than two 1 in a row.\n");
            printf("Above, below, to the left, to the right of a series of two 0's, there can only be one 1.\n");
            while (new_val == value) {
                printf("Please enter a new value: ");
                scanf("%d", &new_val);
            }
        }
    }
    return new_val;
}

void fill_grid4(int* solution[N][N], int* mask[N][N], int* grid[N][N]) {

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (mask[i][j] == 1) {
                grid[i][j] = solution[i][j];
            } else {
                grid[i][j] = -1;
            }
        }
    }
}

void fill_grid8(int* solution[8][8], int* mask[8][8], int* grid[8][8]) {

    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (mask[i][j] == 1) {
                grid[i][j] = solution[i][j];
            } else {
                grid[i][j] = -1;
            }
        }
    }
}

void display_grid4(int* grid[N][N]) {
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (grid[i][j] == -1) {
                printf(". ");
            } else {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

void display_grid8(int* grid[8][8]) {
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j] == -1) {
                printf(". ");
            } else {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int check_equal_grid4(int* grid1[N][N], int* grid2[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0;j<N;j++) {
            if (grid1[i][j] != grid2[i][j]) {
                return 0;
            }
        }
    }
}

int check_equal_grid8(int* grid1[8][8], int* grid2[8][8]) {
    for (int i=0; i<8; i++) {
        for (int j=0;j<8;j++) {
            if (grid1[i][j] != grid2[i][j]) {
                return 0;
            }
        }
    }
}

_Noreturn void menu()
{
    int life = 0;

    int* solution41[4][4] = {{1, 0, 0, 1},{1, 0, 1, 0},{0, 1, 1, 0},{0,1,0,1}};
    int* mask41[4][4] = {{1,0,0,0},{0,0,1,0},{1,0,1,1},{0,1,0,0}};

    int* solution82[8][8] = {{1,0,0,1,0,1,0,1},
                            {0,0,1,1,0,0,1,1},
                            {1,1,0,0,1,1,0,0},
                            {1,1,0,1,0,1,0,0},
                            {0,0,1,0,1,0,1,1},
                            {0,0,1,1,0,1,0,1},
                            {1,1,0,0,1,0,1,0},
                            {0,1,1,0,1,0,1,0}};

    int* mask82[8][8] = {{0,1,1,0,1,0,0,1},
                        {0,0,0,0,1,1,0,1},
                        {0,0,1,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {1,1,0,0,1,1,0,0},
                        {0,0,0,0,0,0,1,1},
                        {1,0,1,1,0,0,1,0},
                        {0,1,1,0,0,1,0,0}};

    int* game_grid1[N][N];

    int* game_grid82[8][8];


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

        printf("You want to solve the grid yourself\n");

        int grid_size = choose_grid();

        if (grid_size == 4) {
            fill_grid4(solution41,mask41,game_grid1);
            display_grid4(game_grid1);
            while (0== check_equal_grid4(game_grid1, solution41)) {
                request(solution41, game_grid1, life);
            }
        } else if (grid_size == 8) {
            fill_grid8(solution82,mask82,game_grid82);
            display_grid8(game_grid82);
            while (0== check_equal_grid8(game_grid82, solution82) || life == 3) {
                request8(solution82, game_grid82, life);
            }
        }

    }
    else if (mode_choice == 2)
    {
        printf("You want the AI to solve a grid.");

        int grid_size = choose_grid();

        if (grid_size == 4) {
            fill_grid4(solution41,mask41,game_grid1);
            solve_grid4(solution41, mask41, game_grid1);
        }

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

void check_rows(int* grid[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<i;j++) {
            if (grid[i] == grid[j]) {
                printf("It is invalid\n");
                printf("By comparing a row already filled with a row missing 2 values, if all values match, then we can fill the row missing two values.\n");
            }
        }
    }
    printf("It is valid");
}

void check_columns(int* grid[N][N]) {
    for (int j=0; j<N; j++) {
        for (int i=0; i<j;i++) {
            if (grid[j] == grid[i]) {
                printf("It is invalid\n");
                printf("By comparing a column already filled with a column missing 2 values, if all values match, then we can fill the column missing two values.\n");
            }
        }
    }
    printf("It is valid");
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

void solve_grid4(int* solution[4][4], int* mask[4][4], int* game_grid[4][4]) {
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (game_grid[i][j] != solution[i][j]) {
                game_grid[i][j] = solution[i][j];
                display_grid4(game_grid);
            }
            printf("\n");
        }

    }

}
