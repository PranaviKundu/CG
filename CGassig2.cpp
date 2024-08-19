#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>

using namespace std;

int pntx1, pnty1, r;

void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x + pntx1, y + pnty1);
    glEnd();
}

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void midPointCircleAlgo() {
    int x = 0;
    int y = r;
    float decision = 5.0 / 4 - r;

    // Plot the initial points
    plot(x, y);
    plot(y, x);
    plot(-x, y);
    plot(-y, x);
    plot(x, -y);
    plot(y, -x);
    plot(-x, -y);
    plot(-y, -x);

    while (y > x) {
        if (decision < 0) {
            decision += 2 * x + 1;
        } else {
            y--;
            decision += 2 * (x - y) + 1;
        }
        x++;

        // Plot the new points after updating x and y
        plot(x, y);
        plot(y, x);
        plot(-x, y);
        plot(-y, x);
        plot(x, -y);
        plot(y, -x);
        plot(-x, -y);
        plot(-y, -x);
    }
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0); // Make sure this matches the point size set in myInit
    midPointCircleAlgo();
    glFlush();
}

int main(int argc, char** argv) {
    cout << "Enter the coordinates of the centre: \n" << endl;
    cout << "X - Coordinates : ";
    cin >> pntx1;
    cout << "\n Y - Coordinates : ";
    cin >> pnty1;
    cout << "\n Enter Radius : ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle Algorithm");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}