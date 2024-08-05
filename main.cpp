#include <GLUT/glut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <maths.h>

int le[500], re[500], flag=0, m;

void init()
{
    if (y1<y0)
    {
    swap(y1,y0);
    swap(x1,x0);
    }
    
        int x=x0;
        m = (y1-y0)/ (x1-x0);
        for(int i=y0; i<y1; i++)
        {
            if (x<le[i])
                le[i]=x;
            if (x>re[i])
                re[i]=x;
            x+=(1/m);
        }
}
void display(){
    glClearColor(1,1,1,1);
    glClear(GL_cCOLOR_BUFFER_BIT);
    glColor3f(0,0,1);
}
