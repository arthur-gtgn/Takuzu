//
// Created by Arthur Gatignol on 18/04/2022.
//

#include "takuzu.h"

void game(int life)
{
    /*
     * Below we are defining the different grids with their respective masks
     */
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

    int solution412[4][4] = {
            {0,1,1,0},
            {1,0,0,1},
            {0,0,1,1},
            {1,1,0,0},
    };

    int mask412[4][4] = {
            {0,1,0,1},
            {0,0,1,0},
            {0,1,0,0},
            {1,1,0,1}
    };

    int solution81[8][8] = {
             {1,0,0,1,0,1,0,1},
             {0,0,1,1,0,0,1,1},
             {1,1,0,0,1,1,0,0},
             {1,1,0,1,0,1,0,0},
             {0,0,1,0,1,0,1,1},
             {0,0,1,1,0,1,0,1},
             {1,1,0,0,1,0,1,0},
             {0,1,1,0,1,0,1,0}
    };

    int mask81[8][8] = {
            {0,1,1,0,1,0,0,1},
             {0,0,0,0,1,1,0,1},
             {0,0,1,0,0,0,0,0},
             {0,0,0,0,0,0,0,0},
             {1,1,0,0,1,1,0,0},
             {0,0,0,0,0,0,1,1},
             {1,0,1,1,0,0,1,0},
             {0,1,1,0,0,1,0,0}
    };

    int solution82[8][8] = {
            {0,0,1,0,1,0,1,1},
            {1,0,0,1,0,1,0,1},
            {0,1,0,1,1,0,1,0},
            {0,1,1,0,0,1,1,0},
            {1,0,1,0,0,1,0,1},
            {1,0,0,1,1,0,0,1},
            {0,1,1,0,1,0,1,0},
            {1,1,0,1,0,1,0,0}
    };

    int mask82[8][8] = {
            {1,1,1,1,1,1,0,0},
            {1,0,1,0,1,0,0,0},
            {1,1,1,0,0,0,1,0},
            {1,0,0,0,1,0,1,0},
            {1,0,0,0,0,1,0,0},
            {0,1,1,1,1,1,1,0},
            {0,0,0,0,0,0,0,1},
            {0,0,1,0,0,0,1,1}
    };

    int* game_grid4 = (int*) malloc(16 * sizeof(int));

    int* game_grid42 = (int*) malloc(16 * sizeof(int));

    int* game_grid8 = (int*) malloc(64 * sizeof(int));

    int* game_grid82 = (int*) malloc(64 * sizeof(int));


    /*
     * This is where the main game starts, asking the user what game mode they want to play.
     */

    int mode_choice=0;

    printf("Welcome to the game of Takuzu\n");
    printf("You can choose between three options: \n");
    printf("1. Solve a grid yourself\n");
    printf("2. Let the AI solve a Takuzu grid\n");
    printf("3. Generate a Takuzu grid\n");

    printf("Which option are you choosing?\n");
    scanf("%d", &mode_choice);

    // Here we are checking if the input is valid or not
    while (mode_choice < 1 || mode_choice > 3)
    {
        printf("Your choice is invalid, please enter a number between 1 and 3\n");
        scanf("%d", &mode_choice);
    }

    /*
     * Here the main game mode where the user has to solve the grid starts
     */
    if (mode_choice == 1)
    {

        printf("You want to solve the grid yourself\n");

        // Here the grid size is determined using the choose_grid() function
        int grid_size = choose_grid();

        /*
         * Here we are asking what kind of mask the user wants
         */
        if (grid_size == 4) {
            int mask_choice = choose_mask();
            if (mask_choice == 1) {

                // Here the original mask is modified to have all its values = 0
                for(int i=0;i<grid_size;i++) {
                    for (int j=0;j<grid_size;j++) {
                        mask41[i][j] = 0;
                    }
                }

                // Displaying the mask to the user
                printf("Here is the mask right now: \n");
                display_grid(*mask41, 4);

                // Asking the user how many boxes he wants to change
                int boxes=0;
                printf("How many boxes do you want to change?");
                scanf("%d", &boxes);

                // Making sure that the user doesn't reveal too many boxes
                while (boxes > (grid_size*grid_size)/2) {
                    printf("You cannot change more that %d boxes.\n", (grid_size* grid_size)/2);
                    printf("Please enter a new value:");
                    scanf("%d", &boxes);
                }

                // Now asking the user to modify the boxes he wants to
                printf("You will now be asked the address of the boxes.\n");
                printf("Please enter the box's row and column.");
                int x=0,y=0;
                for (int i=0;i<boxes;i++) {
                    printf("Please enter the row and column of box %d\n", i+1);

                    printf("Row:");
                    scanf("%d", &x);

                    // Making sure the value entered by the user is withing the range
                    while(x > grid_size) {
                        printf("There are only %d rows!\n", grid_size);
                        printf("Please enter a new value: ");
                        scanf("%d", &x);
                    }

                    // Making sure the value entered by the user is withing the range
                    printf("Column:");
                    scanf("%d", &y);
                    while(y > grid_size) {
                        printf("There are only %d columns!\n", grid_size);
                        printf("Please enter a new value: ");
                        scanf("%d", &y);
                    }
                    mask41[x-1][y-1] = 1;
                }

                // We are then combining the new mask with the original solution grid to make the game_grid
                fill_grid(*solution41, *mask41, game_grid4, grid_size);
                display_grid(game_grid4, 4);

            } else if (mask_choice == 2) {

                // Here the user only wants to see the original mask with the game_grid
                fill_grid(*solution41,*mask41,game_grid4, grid_size);
                display_grid(*mask41, grid_size);
                printf("\n");
                display_grid(game_grid4, grid_size);

            } else if (mask_choice == 3) {

                // Here the user just wants to play
                fill_grid(*solution41,*mask41,game_grid4, grid_size);
                display_grid(game_grid4, grid_size);
            }

            while ( 0 == check_equal_grid(game_grid4, *solution41, grid_size) && life!=0) {
                // Here is the main loop running. The request function will return the life count every time
                // to make sure that the player doesn't force brute the grid
                life = request(*solution41, game_grid4, life, grid_size);
            }
            if (life == 0) {

                // If the life counter arrived to 0 the user is told so
                printf("You ran out of lives.");
            }

        // Here the user has chosen to play and 8x8 grid
        } else if (grid_size == 8) {

            // The same mask modification goes again
            // Look at the 4x4 section to have a better understanding of how it works
            int mask_choice = choose_mask();
            if (mask_choice == 1) {
                for(int i=0;i<grid_size;i++) {
                    for (int j=0;j<grid_size;j++) {
                        mask81[i][j] = 0;
                    }
                }
                printf("Here is the mask right now: \n");
                display_grid(*mask81, grid_size);

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
                    mask81[x-1][y-1] = 1;
                }

                fill_grid(*solution81, *mask81, game_grid8, grid_size);
                display_grid(game_grid8, grid_size);

            } else if (mask_choice == 2) {

                fill_grid(*solution81,*mask81,game_grid8, grid_size);
                display_grid(*mask81, grid_size);
                printf("\n");
                display_grid(game_grid8, grid_size);

            } else if (mask_choice == 3) {

                fill_grid(*solution81,*mask81,game_grid8, grid_size);
                display_grid(game_grid8, grid_size);

            }

            // Here the main loop is running
            while (0== check_equal_grid(game_grid8, *solution81, grid_size) && life!=0) {

                // Look at the 4x4 part to understand why request is an int function
                life = request(*solution81, game_grid8, life, grid_size);

            }

            if (life==0) {
                printf("You ran out of lives.");
            }

        }

    }

    // Here the user has chosen to let the computer solve the grid
    else if (mode_choice == 2)
    {
        printf("You want the AI to solve a grid.");

        // Again, he can choose between a 4x4 grid or a 8x8 grid
        int grid_size = choose_grid();

        if (grid_size == 4) {

            fill_grid(*solution41,*mask41,game_grid4,grid_size);
            solve_grid(*solution41,game_grid4,grid_size);

        } else {

            fill_grid(*solution81,*mask81,game_grid8,grid_size);
            solve_grid(*solution81, game_grid8, grid_size);

        }

    }
    else
    {

        //
        // Part III
        // It hasn't been completed due to the lack of time
        // It also took too much time to develop Part I
        //

        printf("You want to generate a grid.");

    }
}

//
// Here is the main function that the user will use most of the time.
// It allows him to solve a grid himself
//
int request(const int* solution, int* game_grid, int life, int size) {

    // Some variables are declared here
    // g and h are the indices of the rows and columns respectively
    // val is the value that the user will input
    int g=0, h=0, val=0;
    printf("\nPlease enter the row number and the column number of the box you want to change: \n");

    // Asking the user to input the row number
    printf("Row number: ");
    scanf("%d", &g);

    // Checking that values are within the boundaries
    while (g < 1 || g > size) {
        printf("Please enter a number between 1 and %d", size);
        scanf("%d", g);
    }

    // Asking the user to input the column number
    printf("\nColumn number: ");
    scanf("%d", &h);

    // Checking that values are within the boundaries
    while (h < 1 || h > size) {
        printf("\nPlease enter a number between 1 and %d", size);
        scanf("%d", h);
    }

    // Asking the user to input the value (0 and 1)
    printf("\nWhich value do you want to enter: ");
    scanf("%d", &val);

    // Checking that the value is within the bounds
    while (val < 0 || val > 1){
        printf("\nPlease only enter 1 or 0.");
        scanf("%d", &val);
    }

    // The value is added to the grid and will be checked further on
    game_grid[size*(g-1)+(h-1)] = val;

    printf("\n");
    display_grid(game_grid, size);

    // Here we are comparing directly with the solution to see if it is correct
    if (game_grid[size*(g-1)+(h-1)] == solution[size*(g-1)+(h-1)]) {

        printf("\nYour move is correct!");

    } else {

        // Otherwise we are checking the size
        if (size == 4) {

            // Here we are checking the validity of the move
            while (check_val_4(game_grid) == 0 && life != 0) {

                // As the move is not valid, we take away a life
                life--;

                // Asking the user to input a new value
                printf("Please enter a new value");
                scanf("%d", &val);
                game_grid[size*(g-1)+(h-1)] = val;

            }

        // Here the grid is 8x8
        } else {

            // Same steps as in the 4x4 are followed
            while (check_val_8(game_grid, size) == 0 && life != 0) {

                life--;

                printf("Please enter a new value");
                scanf("%d", &val);
                game_grid[size*(g-1)+(h-1)] = val;

            }
        }

        // Here we are checking what happened during the game
        if (life == 0) {
            printf("");
        } else {

            // The final grid is displayed.
            display_grid(game_grid, size);
        }

    }
    return life;
}

//
// The choose_grid function allows the user to choose a size of grid
//
int choose_grid() {
    int grid_size_choice = 0;
    int grid_size=0;

    // Here is the text shown to the user
    printf("What kind of grid do you want to solve?\n");
    printf("1. 4x4 grid\n");
    printf("2. 8x8 grid\n");
    printf("Please enter 1 or 2.");

    scanf("%d", &grid_size_choice);

    // Checking if the value is within the boundaries
    while (grid_size_choice < 1 || grid_size_choice > 2) {
        printf("Your choice is invalid, please enter a number between 1 and 2\n");
        scanf("%d", &grid_size_choice);
    }

    // The grid_size is determined here
    if (grid_size_choice == 1)
    {
        grid_size = 4;
    }
    else
    {
        grid_size = 8;
    }

    // It is then returned to be used later on in the game
    return grid_size;
}


//
// The choose_mask function allows the user to choose the kind of mask they want
//
int choose_mask() {

    // Here the choose_mask function is only asking the user for their choice
    int choice = 0;
    printf("Please enter the mask that you want on your grid:\n");
    printf("1. Enter your own mask\n");
    printf("2. Use the default mask\n");
    printf("3. Play\n");

    printf("Please enter your choice: ");
    scanf("%d", &choice);

    // Checking if the values are withing the bonds
    while (choice < 1 || choice > 3) {
        printf("Your choice is invalid. Please make a new one:");
        scanf("%d", &choice);
    }

    return choice;
}

//
// The fill_grid function mixes the mask and solution grids to make up the game_grid
//
void fill_grid(const int* solution, const int* mask, int* grid, int size) {

    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {

            // If the mask wants to show a value it takes it directly from the solution
            // onto the game_grid
            if (mask[size*i+j] == 1) {

                grid[size*i+j] = solution[size*i+j];

            } else {

                // Otherwise, it replaces the 0s by -1s
                grid[size*i+j] = -1;

            }
        }
    }
}

//
// The display_grid function helps in displaying a grid that is readable by a human
//
void display_grid(int* grid, int size) {

    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {

            // All the -1s are replaced by '.'
            if (grid[size*i+j] == -1) {
                printf(". ");
            } else {

                // Otherwise they are displayed on screen
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


//
// This is the main checking algorithm
//
int check_val_4(int* grid) {

    // Setting the counters to 0
    int counter_row = 0, counter_col = 0, counter_row0 = 0, counter_col0 = 0;

    int correct = 1;

    // The counters count the number of values (0s or 1s) in each row and each column
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

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

        // If there are too many 0s or 1s, then the move is invalid.
        if ((counter_col > 2) || (counter_col0 > 2)) {
            printf("Your move is not valid!\n ");
            printf("There are as many 1s as 0s in a row , you need to change something.\n");
            correct = 0;
            printf("returned 0");
            return 0;
        }
        if ((counter_row > 2) || (counter_row0 > 2)) {
            printf("Your move is not valid!\n");
            printf("There are as many 1s as 0s in a column, you need to change something. \n");
            correct = 0;
            return 0;
        }

        // Resetting the values
        counter_col = 0;
        counter_row = 0;
        counter_col0 = 0;
        counter_row0 = 0;

    }

}

//
// The same concept is then applied here for the 8x8 grids
//
int check_val_8(int* grid, int size) {

    int counter_row = 0, counter_col = 0, counter_row0 = 0, counter_col0 = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
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


        if ((counter_col > 4) || (counter_col0 > 4)) {
            printf("Your move is invalid!\n");
            printf("There are not as many 1s as 0s in a row , you need to change something.\n");

            return 0;
        }
        if ((counter_row > 4) || (counter_row0 > 4)) {
            printf("Your move is invalid!\n");
            printf("There are not as many 1s as 0s in a column, you need to change something. \n");

            return 0;
        }

        counter_col = 0;
        counter_row = 0;
        counter_col0 = 0;
        counter_row0 = 0;
    }
}

//
// This is the second game mode available to the user
//
void solve_grid(int* solution, int* grid, int size) {

    printf("You will see the grid solving itself: \n");

    // The grid is displayed a first time to the user so that he can see what it looks like at first
    display_grid(grid, size);
    printf("\n");

    // We are then looping through the grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            // Checking that we are not changing the values of the mask
            if (grid[size * i + j] == -1) {

                // A random value (0 or 1) is the generated and assigned in the grid
                grid[size * i + j] = rand() % 2;
                printf("\n");

                // It is then displayed to the user
                display_grid(grid, size);
                printf("Checking...\n");

                // We are now checking if is a correct or invalid move

                // If the move is valid then it is displayed and told to the user
                if (grid[size * i + j] != solution[size * i + j]) {

                    printf("The move is not right!\n");

                    // The value is then changed in the game_grid to the correct one
                    grid[size * i + j] = solution[size * i + j];
                    display_grid(grid, size);

                    // The user can see the grid and is told that the value was changed
                    printf("Now it has been corrected.\n");

                    // Otherwise, the user is directly told that the move was correct.
                } else {
                    printf("The move is correct!\n");
                }

                // There is a sleeping time so that the screen is not bloated with grids.
                sleep(3);
            }
        }
    }
    printf("The grid is solved!");

}