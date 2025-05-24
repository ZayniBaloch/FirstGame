#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h> // Replace unistd.h with windows.h for Windows compatibility

char arr[5][5] = {'\0'};
int row = 4, col = 4;
int colc = 4, rowc = 4;
int score = 0;
int row1, col1;
int flag = 0;

void print() {
    printf("Score: %d\n", score);
    printf("#############\n");  // Top border
    for (int i = 0; i < 5; i++) {
        printf("| ");  // Left border
        for (int j = 0; j < 5; j++) {
            if (arr[i][j] == '\0') {
                printf("  "); 
            } else {
                printf("%c ", arr[i][j]);  
            }
        }
        printf("|\n");  // Right border
    }
    printf("#############\n");  // Bottom border
}

void ran() {
    // Only seed the random number generator once at game start, not every call
    static int initialized = 0;
    if (!initialized) {
        srand((unsigned int)time(NULL));
        initialized = 1;
    }
    
    do {
        row1 = rand() % 5;
        col1 = rand() % 5;
    } while (arr[row1][col1] == 'o');  
    arr[row1][col1] = '*';
}

void scoree(){
 if (rowc == row1 && colc == col1) {  // also need to creat a saperate function for this 
            // need to call that in every if else condition
            score++;
            ran();  
        }
}

void terminator(){
    if (rowc > 4 || rowc < 0 || colc > 4 || colc < 0) { 
        system("cls");  // Clear screen
        printf("\n\n");
        printf("Game Over\n");
        printf("Final Score: %d\n", score);
        flag = 1;
    }
}

void directione(char d){
    arr[rowc][colc] = '\0';
    if (d == 'a' || d == 'A') colc--;
    else if (d == 'd' || d == 'D') colc++;
    else if (d == 'w' || d == 'W') rowc--;
    else if (d == 's' || d == 'S') rowc++;
    scoree();
    terminator();
    if(!flag) arr[rowc][colc] = 'o';
}

int main() {
    // Initialize the game
    arr[rowc][colc] = 'o';  
    ran();   
    print();
    char direction = '\0';
    char prev = 'n';
    
    while (!flag) {
        // Process input without blocking
        if (kbhit()) {
            direction = getch();
            // Validate input
            if(direction != 'a' && direction != 'A' && 
               direction != 'd' && direction != 'D' && 
               direction != 'w' && direction != 'W' && 
               direction != 's' && direction != 'S') {
                direction = prev;
            } else {
                prev = direction;
            }
            
            // Process movement immediately after valid input
            if(direction) {
                directione(direction);
            }
        }

        // Clear screen properly for Windows
        system("cls");
        
        // Redraw the game state
        print();
        
        // Use Windows Sleep function instead of usleep
        Sleep(300); // 300ms delay (more responsive than 500ms)
    }
    
    // Make sure the game over message stays visible
    if(flag) {
        printf("Press any key to exit...\n");
        getch();
    }
    
    return 0;
}

