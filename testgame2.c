// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <conio.h>
// #include <unistd.h>
// char arr[4][4] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
// int row = 3, col = 3;
// int colc = 3, rowc = 3;
// int score = 0;
// int row1, col1;

// void print() {
//     printf("Score: %d\n", score);
//     printf("___________\n");  // Top border
//     for (int i = 0; i < 4; i++) {
//         printf("| ");  // Left border
//         for (int j = 0; j < 4; j++) {
//             if (arr[i][j] == '\0') {
//                 printf("  ");
//             } else {
//                 printf("%c ", arr[i][j]);
//             }
//         }
//         printf("|\n");  // Right border
//     }
//     printf("-----------\n");  // Bottom border
// }

// void ran() {
//     srand(time(NULL));
//     do {
//         row1 = rand() % 4;
//         col1 = rand() % 4;
//     } while (arr[row1][col1] == 'o');
//     arr[row1][col1] = '*';
// }

// int main() {
//     arr[rowc][colc] = 'o';
//     ran();
//     print();

//     while (1) {
//         int dire;
//         dire = getch();
//         system("cls");  // Clear the screen

//         arr[rowc][colc] = '\0';

//         if (dire == 'a' || dire == 'A') {  // Move left
//         // need to setup infinite loop here with non blocking input and will control the speed of that loop
//         while(1)  {
//             colc--;
//             print();
//             sleep(1);
//         }

//         } else if (dire == 'd' || dire == 'D') {  // Move right
//             colc++;
//         } else if (dire == 'w' || dire == 'W') {  // Move up
//             rowc--;
//         } else if (dire == 's' || dire == 'S') {  // Move down
//             rowc++;
//         } else {
//            arr[rowc][colc] = 'o';
//             goto fap; // Ignore other keys
//         }
//         if (rowc > 3 || rowc < 0 || colc > 3 || colc < 0) {   // need to create saperate function for game over
//             printf("Game Over\n");
//             printf("Final Score: %d\n", score);
//             break;
//         }
//         arr[rowc][colc] = 'o';

//         if (rowc == row1 && colc == col1) {  // also need to creat a saperate function for this
//             // need to call that in every if else condition
//             score++;
//             ran();
//         }
//         fap :
//         print();
//     }
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>

char arr[4][4] = {'\0'};
int row = 3, col = 3;
int colc = 3, rowc = 3;
int score = 0;
int row1, col1;
int flag = 0;
char prevKey;

void print() {
    printf("Score: %d\n", score);
    printf("___________\n");
    for (int i = 0; i < 4; i++) {
        printf("| ");
        for (int j = 0; j < 4; j++) {
            printf("%c ", arr[i][j] ? arr[i][j] : ' ');
        }
        printf("|\n");
    }
    printf("-----------\n");
}

void ran() {
    srand(time(NULL));
    do {
        row1 = rand() % 4;
        col1 = rand() % 4;
    } while (arr[row1][col1] == 'o');
    arr[row1][col1] = '*';
}

void scoree() {
    if (rowc == row1 && colc == col1) {
        score++;
        ran();
    }
}

void terminator() {
    if (rowc > 3 || rowc < 0 || colc > 3 || colc < 0) {
        system("cls");
        printf("Game Over\n");
        printf("Final Score: %d\n", score);
        flag = 1;
    }
}

void update_position(char direction) {
    arr[rowc][colc] = '\0'; // Clear current position
    if (direction == 'a' || direction == 'A') colc--; // Move left
    else if (direction == 'd' || direction == 'D') colc++; // Move right
    else if (direction == 'w' || direction == 'W') rowc--; // Move up
    else if (direction == 's' || direction == 'S') rowc++; // Move down

    scoree();
    terminator();
    if (!flag) arr[rowc][colc] = 'o'; // Update position if game not over
}

int main() {
    arr[rowc][colc] = 'o';
    ran();
    print();

    char direction = '\0';

    while (!flag) {
        if (kbhit()) {
            direction = getch(); // Get user input
        }
        if (direction) {
            update_position(direction); // Update game state
        }

        system("cls"); // Clear screen
        print();
        usleep(350000); // Control speed (0.5 seconds)
    }


    return 0;
}
