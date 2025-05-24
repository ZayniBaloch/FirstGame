#include "C:\\path\\to\\pdcurses\\include\\curses.h"
#include <curses.h> // or <curses.h> if using PDCurses
#include <unistd.h>  // for usleep function

int main() {
    initscr();            // Initialize ncurses or PDCurses screen
    nodelay(stdscr, TRUE); // Set non-blocking input on standard screen
    cbreak();              // Disable line buffering
    noecho();              // Do not print input characters to the screen

    int ch;
    printw("Press 'q' to quit\n");

    while (1) {
        ch = getch();  // Non-blocking getch; returns ERR if no input

        if (ch != ERR) {  // If a key was pressed
            if (ch == 'q') break;  // Exit loop if 'q' is pressed
            printw("Key pressed: %c\n", ch);
            refresh();
        }

        // Perform other tasks here without blocking
        printw("Doing other work...\n");
        refresh();

        usleep(500000);  // Sleep for 500 milliseconds to slow down the loop
    }

    endwin();  // End ncurses or PDCurses mode
    return 0;
}
