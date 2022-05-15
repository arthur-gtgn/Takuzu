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

_Noreturn void menu(int life)
{


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

    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            game_grid4[4*i + j] = -1;
        }
    }

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
            int mask_choice = choose_mask();
            if (mask_choice == 1) {
                for(int i=0;i<grid_size;i++) {
                    for (int j=0;j<grid_size;j++) {
                        mask41[i][j] = 0;
                    }
                }
                printf("Here is the mask right now: \n");
                display_grid(mask41, 4);

                int boxes=0;
                printf("How many boxes do you want to change?");
                scanf("%d", &boxes);
                while (boxes > (grid_size*grid_size)/2) {
                    printf("You cannot change more that %d boxes.\n", (grid_size* grid_size)/2);
                    printf("Please enter a new value:");
                    scanf("%d", &boxes);
                }

                printf("You will now be asked the address of the boxes.\n");
                printf("Please enter the box's row and column.");
                int x=0,y=0;
                for (int i=0;i<boxes;i++) {
                    printf("Please enter the row and column of box %d\n", i+1);

                    printf("Row:");
                    scanf("%d", &x);
                    while(x > grid_size) {
                        printf("There are only %d rows!\n", grid_size);
                        printf("Please enter a new value: ");
                        scanf("%d", &x);
                    }

                    printf("Column:");
                    scanf("%d", &y);
                    while(y > grid_size) {
                        printf("There are only %d columns!\n", grid_size);
                        printf("Please enter a new value: ");
                        scanf("%d", &y);
                    }
                    mask41[x-1][y-1] = 1;
                }

                fill_grid(solution41, &mask41, game_grid4, grid_size);
                display_grid(game_grid4, 4);
            } else if (mask_choice == 2) {
                fill_grid(solution41,&mask41,game_grid4, grid_size);
                display_grid(*mask41, grid_size);
                printf("\n");
                display_grid(game_grid4, grid_size);
            } else if (mask_choice == 3) {
                fill_grid(solution41,&mask41,game_grid4, grid_size);
                display_grid(game_grid4, grid_size);
            }

            while ( 0 == check_equal_grid(game_grid4, solution41, grid_size) && life!=0) {
                life = request(solution41, game_grid4, life, grid_size);
            }
            if (life == 0) {
                printf("You ran out of lives.");
            }
        } else if (grid_size == 8) {

            int mask_choice = choose_mask();
            if (mask_choice == 1) {
                for(int i=0;i<grid_size;i++) {
                    for (int j=0;j<grid_size;j++) {
                        mask8[i][j] = 0;
                    }
                }
                printf("Here is the mask right now: \n");
                display_grid(mask8, grid_size);

                int boxes=0;
                printf("How many boxes do you want to change?");
                scanf("%d", &boxes);
                while (boxes > (grid_size*grid_size)/2) {
                    printf("You cannot change more that %d boxes.\n", (grid_size* grid_size)/2);
                    printf("Please enter a new value:");
                    scanf("%d", &boxes);
                }

                printf("You will now be asked the address of the boxes.\n");
                printf("Please enter the box's row and column.");
                int x=0,y=0;
                for (int i=0;i<boxes;i++) {
                    printf("Please enter the row and column of box %d\n", i+1);

                    printf("Row:");
                    scanf("%d", &x);
                    while(x > grid_size) {
                        printf("There are only %d rows!\n", grid_size);
                        printf("Please enter a new value: ");
                        scanf("%d", &x);
                    }

                    printf("Column:");
                    scanf("%d", &y);
                    while(y > grid_size) {
                        printf("There are only %d columns!\n", grid_size);
                        printf("Please enter a new value: ");
                        scanf("%d", &y);
                    }
                    mask8[x-1][y-1] = 1;
                }

                fill_grid(solution8, &mask8, game_grid8, grid_size);
                display_grid(game_grid8, grid_size);
            } else if (mask_choice == 2) {
                fill_grid(solution8,&mask8,game_grid8, grid_size);
                display_grid(*mask8, grid_size);
                printf("\n");
                display_grid(game_grid8, grid_size);
            } else if (mask_choice == 3) {
                fill_grid(solution8,&mask8,game_grid8, grid_size);
                display_grid(game_grid8, grid_size);
            }
            while (0== check_equal_grid(&game_grid8, &solution8, grid_size) && life!=0) {
                life = request(solution8, game_grid8, life, grid_size);
            }
            if (life==0) {
                printf("You ran out of lives.");
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

int request(const int* solution, int* game_grid, int life, int size) {
    int g=0, h=0, val=0;
    printf("\nPlease enter the row number and the column number of the box you want to change: \n");

    printf("Row number: ");
    scanf("%d", &g);

    while (g < 1 || g > size) {
        printf("Please enter a number between 1 and %d", size);
        scanf("%d", g);
    }

    printf("\nColumn number: ");
    scanf("%d", &h);

    while (h < 1 || h > size) {
        printf("\nPlease enter a number between 1 and %d", size);
        scanf("%d", h);
    }


    printf("\nWhich value do you want to enter: ");
    scanf("%d", &val);

    while (val < 0 || val > 1){
        printf("\nPlease only enter 1 or 0.");
        scanf("%d", &val);
    }

    game_grid[size*(g-1)+(h-1)] = val;

    printf("\n");
    display_grid(game_grid, size);

    if (game_grid[size*(g-1)+(h-1)] == solution[size*(g-1)+(h-1)]) {
        printf("\nYour move is correct!");
    } else {
        if (size == 4) {
            while (check_val_4(game_grid) == 0 && life != 0) {
                life-=1;
                printf("Please enter a new value");
                scanf("%d", &val);
                game_grid[size*(g-1)+(h-1)] = val;
                printf("life: %d", life);
            }
        } else {
            while (check_val_8(game_grid) == 0 && life != 0) {
                life--;
                printf("Please enter a new value");
                scanf("%d", &val);
                game_grid[size*(g-1)+(h-1)] = val;
            }
        }
        if (life == 0) {
            printf("");
        } else {
            display_grid(game_grid, size);
        }

    }
    return life;
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

int choose_mask() {
    int choice = 0;
    printf("Please enter the mask that you want on your grid:\n");
    printf("1. Enter your own mask\n");
    printf("2. Use the default mask\n");
    printf("3. Play\n");

    printf("Please enter your choice: ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 3) {
        printf("Your choice is invalid. Please make a new one:");
        scanf("%d", &choice);
    }

    return choice;
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

int check_val_4(int* grid) {
    int i = 0, j = 0, counter_row = 0, counter_col = 0, counter_row0 = 0, counter_col0 = 0;
    int correct = 1;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (grid[4 * i + j] == 1) {
                counter_row += 1;
            } else if (grid[4 * i + j] == 0) {
                counter_row0 += 1;

            }
            if (grid[4 * j + i] == 1) {
                counter_col += 1;
            } else if (grid[4 * j + i] == 0) {
                counter_col0 += 1;
            }

        }


        if ((counter_col > 2) || (counter_col0 > 2)) {
            printf(" the moove is not valid!\n "
                   "there are as many 1s as 0s in a row , you need to change something.\n");
            correct = 0;
            printf("returned 0");
            return 0;
        }
        if ((counter_row > 2) || (counter_row0 > 2)) {
            printf(" the moove is not valid!\n "
                   "there are as many 1s as 0s in a column, you need to change something. \n");
            correct = 0;
            return 0;
        }
        counter_col = 0;
        counter_row = 0;
        counter_col0 = 0;
        counter_row0 = 0;

    }
    if (correct == 1) {
        printf("the moove is correct\n");

    }
}

int check_val_8(int* grid) {
    int i = 0, j = 0, counter_row = 0, counter_col = 0, counter_row0 = 0, counter_col0 = 0;
    int correct = 1;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (grid[8 * i + j] == 1) {
                counter_row += 1;
            } else if (grid[8 * i + j] == 0) {
                counter_row0 += 1;

            }
            if (grid[8 * j + i] == 1) {
                counter_col += 1;
            } else if (grid[8 * j + i] == 0) {
                counter_col0 += 1;
            }

        }


        if ((counter_col >= 4) || (counter_col0 >= 4)) {
            printf(" the moove is not valid!\n "
                   "there are not as many 1s as 0s in a row , you need to change something.\n");
            correct = 0;
            printf("returned 0");
            return 0;
        }
        if ((counter_row >= 4) || (counter_row0 >= 4)) {
            printf(" the moove is not valid!\n "
                   "there are not as many 1s as 0s in a column, you need to change something. \n");
            correct = 0;
            return 0;
        }
        /*
        if (check_sides(grid) == 0) {
            printf("There are too many %d", grid[8 * i + j]);
            return 0;
        }
         */
        counter_col = 0;
        counter_row = 0;
        counter_col0 = 0;
        counter_row0 = 0;

    }
    if (correct == 1) {
        printf("the moove is correct\n");

    }
}

int check_sides(int* grid) {
    for (int i=0;i<8;i++) {

        for (int j=0;j<8;j++) {
            if (j == 0) {
                if (grid[8 * i + j] == grid[8 * i + (j+1)] && grid[8 * i + j] == grid[8 * i + (j+2)]) {
                    return 0;
                }
            }
        }
    }
}
