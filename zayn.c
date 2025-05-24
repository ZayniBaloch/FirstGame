#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent the snake
typedef struct {
    int x, y;
} Point;

// Structure to represent the game
typedef struct {
    Point snake[100];
    Point food;
    int length;
    int direction; // 0: right, 1: down, 2: left, 3: up
    int score;
} Game;

// Function to draw the game border
void drawBorder(HDC hdc) {
    Rectangle(hdc, 0, 0, 400, 400);
}

// Function to draw the snake
void drawSnake(HDC hdc, Game *game) {
    for (int i = 0; i < game->length; i++) {
        Rectangle(hdc, game->snake[i].x * 20, game->snake[i].y * 20, (game->snake[i].x + 1) * 20, (game->snake[i].y + 1) * 20);
    }
}

// Function to draw the food
void drawFood(HDC hdc, Game *game) {
    Rectangle(hdc, game->food.x * 20, game->food.y * 20, (game->food.x + 1) * 20, (game->food.y + 1) * 20);
}

// Function to handle the WM_PAINT message
void paint(HWND hwnd, HDC hdc) {
    Game *game = (Game *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    drawBorder(hdc);
    drawSnake(hdc, game);
    drawFood(hdc, game);
}

// Function to handle the WM_KEYDOWN message
void keyDown(HWND hwnd, int key) {
    Game *game = (Game *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    switch (key) {
        case VK_RIGHT:
            if (game->direction!= 2) game->direction = 0;
            break;
        case VK_DOWN:
            if (game->direction!= 3) game->direction = 1;
            break;
        case VK_LEFT:
            if (game->direction!= 0) game->direction = 2;
            break;
        case VK_UP:
            if (game->direction!= 1) game->direction = 3;
            break;
    }
}