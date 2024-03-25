#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include "./algorithm1.h"

// Set the background color and matrix mode
void initialize(void){
    glClearColor(1, 1, 1, 1); // White color
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 700, 0, 700); // 700x700
}

// Main function
void draw(void){
    glClear(GL_COLOR_BUFFER_BIT);
        carnet();
    glFlush();
}

// Function to draw my carnet
void algorithm1(float x1, float y1, float x2, float y2){
    float m, b;
    m = (y2 - y1) / (x2 - x1);
    b = y1 - (m * x1);
    // If the line is vertical:
    if (x1 == x2) {
        // Draw a vertical line
        int startY = (y1 < y2) ? y1 : y2;
        int endY = (y1 > y2) ? y1 : y2;
        for (int j = startY; j <= endY; j++) {
            glBegin(GL_POINTS);
            glVertex2f(x1, j);
            glEnd();
        }
    } 
    /* If the point goes 
     * from left to right and from down to up
     * or from left to right and from up to down:
     */
    else {
        if ((x2 > x1 && y2 > y1) || (x2 > x1 && y2 < y1)) {
            for (int i = x1; i <= x2; i++) {
                float y = (m * i) + b;
                glBegin(GL_POINTS);
                glVertex2f(i, y);
                glEnd();
            }
        } 
        // If not:
        else {
            for (int i = x1; i >= x2; i--) {
                float y = (m * i) + b;
                glBegin(GL_POINTS);
                glVertex2f(i, y);
                glEnd();
            }
        }
    }
    // And if it is neither of the cases:
    for (int i = x1; i <= x2; i++){
            float y = (m * i) + b;
            glBegin(GL_POINTS);
            glVertex2f(i, y);
            glEnd();
        }
}

void carnet(){
    glColor3i(0, 0, 0); // Black color
    
    // Coordinates to draw my carnet
    
        // Letter V
        algorithm1(20, 440, 80, 260);
        algorithm1(80, 260, 140, 440);

        // Letter G
        algorithm1(260, 440, 160, 440);
        algorithm1(160, 440, 160, 260);
        algorithm1(160, 260, 260, 260);
        algorithm1(260, 260, 260, 350);
        algorithm1(260, 350, 210, 350);
        algorithm1(210, 350, 210, 320);

        // Number 2
        algorithm1(280, 420, 280, 440);
        algorithm1(280, 440, 360, 440);
        algorithm1(360, 440, 360, 350);
        algorithm1(360, 350, 280, 350);
        algorithm1(280, 350, 280, 260);
        algorithm1(280, 260, 360, 260);
        algorithm1(360, 260, 360, 280);

        // Number 1
        algorithm1(380, 380, 430, 440);
        algorithm1(430, 440, 430, 260);

        // Number 0
        algorithm1(510, 440, 450, 440);
        algorithm1(450, 440, 450, 260);
        algorithm1(450, 260, 510, 260);
        algorithm1(510, 260, 510, 440);

        // Number 0
        algorithm1(590, 440, 530, 440);
        algorithm1(530, 440, 530, 260);
        algorithm1(530, 260, 590, 260);
        algorithm1(590, 260, 590, 440);

        // Number 9
        algorithm1(680, 260, 680, 440);
        algorithm1(680, 440, 610, 440);
        algorithm1(610, 440, 610, 360);
        algorithm1(610, 360, 680, 360);
}