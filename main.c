/* 
 * File:   main.c
 * Author: vasquez
 *
 * Created on March 25, 2024, 12:02 AM
 */

/*
 * Added in Linker: -lGL -lglut -lGLU
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include "./algorithm1.h"

/*
 * This algorithm consists of drawing my carnet (VG21009)
 * using the general straight line equation algorithm
 * specifically the point-slope equation with OpenGL
 */

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(375, 55);
    glutInitWindowSize(700, 700);
    glutCreateWindow("AGR135 - Algorithm 1 - VG21009"); // Added Carnet
    glClearColor(1, 1, 1, 1); // White color
    initialize();
    glutDisplayFunc(draw);
    glutMainLoop();
    return (EXIT_SUCCESS);
}

/*   Code made by Carlos Oswaldo Vásquez Girón   */