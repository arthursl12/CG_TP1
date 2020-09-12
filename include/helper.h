#ifndef HELPER_H
#define HELPER_H

#include "constants.h"
#include <string>

extern bool gameOver;
extern int score;

void drawText(float x, float y, std::string text);
void display_callback();
void reshape_callback(int,int);
void timer_callback(int);
void keyboard_callback(int, int, int);

#endif /* HELPER_H */