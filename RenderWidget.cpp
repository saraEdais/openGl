//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Zein Salah, on 26.02.2019
//


#include "RenderWidget.h"
#include <glut.h>
#include <QPainter>

RenderWidget::RenderWidget(QWidget *parent) : QOpenGLWidget(parent)
{

}


RenderWidget::~RenderWidget()
{

}


QSize RenderWidget::minimumSizeHint() const
{
    return QSize(100, 100);
}


QSize RenderWidget::sizeHint() const
{
    return QSize(800, 900);
}


void RenderWidget::initializeGL()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    //glOrtho(-2.0, 2.0, -2.0, 2.0, -100, 100);
    //gluPerspective(25.0, 1.0, 1.0, 100.0);

}


void RenderWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLineWidth(3);
    
    glBegin(GL_TRIANGLES);
      glColor3f(1.0, 0.0, 0.0);   // red
      glVertex2f(60, 40);
      glColor3f(0.0, 1.0, 0.0);   // green
      glVertex2f(200, 40);
	  glColor3f(0.0, 0.0, 1.0);   // blue
      glVertex2f(130, 200);
    glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 0.0);   // yellow
	glVertex2f(200, 200);
	glVertex2f(400, 200);
	glVertex2f(200, 400);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);   // white
	glVertex2f(350, 300);
	glColor3f(0.0, 0.0, 0.0);   // black
	glVertex2f(500, 300);
	glColor3f(1.0, 1.0, 1.0);   // white
	glVertex2f(500, 500);
	glColor3f(0.0, 0.0, 0.0);   // black
	glVertex2f(350, 500);
	glEnd();

    glFlush();
}


void RenderWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

//    glViewport(0, 0, width, height);
}


