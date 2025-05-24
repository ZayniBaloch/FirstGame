#include <conio.h>
#include <stdio.h>

int main() {
    printf("Press 'a' for Action A, 'b' for Action B, or 'q' to quit.\n");

    while (1) {
        if (_kbhit()) {         // Detect a key press (non-blocking)
            char c = _getch();  // Capture the key press immediately

            // Execute an action based on the key pressed
            switch (c) {
                case 'a':
                    printf("Action A triggered by 'a'\n");
                    break;
                case 'b':
                    printf("Action B triggered by 'b'\n");
                    break;
                case 'q':
                    printf("Exiting program.\n");
                    return 0;   // Exit on 'q' press
                default:
                    printf("Unknown key pressed: %c\n", c);
            }

            // At this point, the program waits for the next key press.
            // Each key press only triggers the corresponding action once.
        }
        // You can add other code here to run alongside or idle.
    }

    return 0;
}
