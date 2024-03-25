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