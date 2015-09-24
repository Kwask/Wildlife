#include <iostream>
#include <GL/glfw3.h>

#include "perlinnoise.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
Noise *a;

void Reshape( GLFWwindow *wind, float width, float height )
{

	glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0, width, 0, height, 1.0f, 100.0f );
	glMatrixMode( GL_MODELVIEW );

}

void Draw()
{

	glBegin( GL_LINE_STRIP );
	for( int i = 1; i < 8000; i++ )
	{

		glVertex2f( i*(WINDOW_WIDTH/8000.0f), (a->getVal( i/10.0f, 1 ))+100 );

	}
	glEnd();
}

int main()
{

	glfwInit();
	GLFWwindow *window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "Perlin Noise", NULL, NULL );
	glfwMakeContextCurrent( window );

	Reshape( window, WINDOW_WIDTH, WINDOW_HEIGHT );

	srand(time(nullptr));
	a = new Noise( 100, 8000 );

	while( !glfwWindowShouldClose( window ) )
	{

		glClear( GL_COLOR_BUFFER_BIT );
		glLoadIdentity();
		glTranslatef( 0.0f, 0.0f, -1.0f );

		Draw();

		glfwSwapBuffers( window );
		glfwPollEvents();

	}

}