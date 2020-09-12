#ifndef GAME_H
#define GAME_H

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#define MAX 60

extern bool gameOver;
extern int score;

void initGrid(int x, int y);
void drawGrid();
void unit(int x, int y);
void drawSnake();
void drawFood();
void random(int &x, int &y);

#endif


