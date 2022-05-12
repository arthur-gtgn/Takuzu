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

_Noreturn void menu()
{
    int life = 0;

    int solution41[4][4] = {
            {1, 0, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0,1,0,1}
    };


    int mask41[4][4] = {
            {1,0,0,0},
            {0,0,1,0},
            {1,0,1,1},
            {0,1,0,0}
    };

    int solution8[8][8] = {{1,0,0,1,0,1,0,1},
                             {0,0,1,1,0,0,1,1},
                             {1,1,0,0,1,1,0,0},
                             {1,1,0,1,0,1,0,0},
                             {0,0,1,0,1,0,1,1},
                             {0,0,1,1,0,1,0,1},
                             {1,1,0,0,1,0,1,0},
                             {0,1,1,0,1,0,1,0}};

    int mask8[8][8] = {{0,1,1,0,1,0,0,1},
                         {0,0,0,0,1,1,0,1},
                         {0,0,1,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0},
                         {1,1,0,0,1,1,0,0},
                         {0,0,0,0,0,0,1,1},
                         {1,0,1,1,0,0,1,0},
                         {0,1,1,0,0,1,0,0}};



    int* game_grid4 = (int*) malloc(16 * sizeof(int));
    printf("%d", sizeof(*game_grid4));

    int* game_grid8 = (int*) malloc(8 * 8 * sizeof(int));


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
            fill_grid(solution41,&mask41,game_grid4, grid_size);
            display_grid(game_grid4, grid_size);

            while (0== check_equal_grid(game_grid4, solution41, grid_size)) {
                request(solution41, game_grid4, life, grid_size);
            }

            request(solution41, game_grid4, life, grid_size);
        } else if (grid_size == 8) {
            fill_grid(solution8,&mask8,&game_grid8, grid_size);
            display_grid(&game_grid8, grid_size);
            while (0== check_equal_grid(&game_grid8, &solution8, grid_size) || life == 3) {
                request(&solution8, &game_grid8, life, grid_size);
            }
        }

    }
    else if (mode_choice == 2)
    {
        printf("You want the AI to solve a grid.");

        int grid_size = choose_grid();

        if (grid_size == 4) {
            fill_grid(solution41,mask41,game_grid4, grid_size);
            solve_grid4(solution41, mask41, game_grid4);
        }

    }
    else
    {
        printf("You want to generate a grid.");

        int grid_size = choose_grid();
    }
}

void request(const int* solution, int* game_grid, int life, int size) {
    int g=0, h=0, val=0;
    printf("\nPlease enter the row number and the column number of the box you want to change: \n");

    printf("Row number: ");
    scanf("%d", &g);

    while (g < 1 || g > size) {
        printf("Please enter a number between 1 and N");
        scanf("%d", g);
    }

    printf("\nColumn number: ");
    scanf("%d", &h);

    while (h < 1 || h > size) {
        printf("\nPlease enter a number between 1 and N");
        scanf("%d", h);
    }


    printf("\nWhich value do you want to enter: ");
    scanf("%d", &val);

    while (val < 0 || val > 1){
        printf("\nPlease only enter 1 or 0.");
        scanf("%d", &val);
    }

    game_grid[size*(g-1)+(h-1)] = val;

    game_grid[size*(g-1)+(h-1)] = check_val(game_grid, val, g-1, h-1, size);

    printf("\n");
    display_grid(game_grid, size);

    if (game_grid[size*(g-1)*(h-1)] == solution[size*(g-1)*(h-1)]) {
        printf("\nYour move is correct!");
    } else {
        printf("Your move is valid.");
        life++;

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

int check_val(int* grid, int value, int x, int y, int size) {
    int count0_row = 0, count1_row = 0, count0_column = 0, count1_column = 0;

    for (int i=0;i<size;i++) {
        if (grid[size*i+(y-1)] == 0) {
            count0_row++;
        } else if (grid[size*i+(y-1)] == 1) {
            count1_row++;
        }
    }

    for (int j=0; j<size; j++) {
        if (grid[size*(x-1)+j] == 0) {
            count0_column++;
        } else if (grid[size*(x-1)+j] == 1) {
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
    printf("%d\n", new_val);
    return new_val;
}

void fill_grid(const int* solution, const int* mask, int* grid, int size) {
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            if (mask[size*i+j] == 1) {
                grid[size*i+j] = solution[size*i+j];
            } else {
                grid[size*i+j] = -1;
            }
        }
    }
}

void display_grid(int* grid, int size) {
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            if (grid[size*i+j] == -1) {
                printf(". ");
            } else {
                printf("%d ", grid[size*i+j]);
            }
        }
        printf("\n");
    }
}

int check_equal_grid(const int* grid1, const int* grid2, int size) {
    for (int i=0; i<size; i++) {
        for (int j=0;j<size;j++) {
            if (grid1[size*i+j] != grid2[size*i+j]) {
                return 0;
            }
        }
    }
}

void check_rows(int* grid[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<i;j++) {
            if (grid[i] == grid[j]) {
                printf("It is invalid\n");
                printf("By comparing a row already filled with a row missing 2 values,"
                       " if all values match, then we can fill the row missing two values.\n");
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
                printf("By comparing a column already filled with a column missing 2 values, if all values match, "
                       "then we can fill the column missing two values.\n");
            }
        }
    }
    printf("It is valid");
}

void solve_grid4(int* *solution, int* *mask, int* *game_grid) {
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (game_grid[i][j] != solution[i][j]) {
                game_grid[i][j] = solution[i][j];
                int x =4;
                display_grid(game_grid, x);
            }
            printf("\n");
        }

    }

}
