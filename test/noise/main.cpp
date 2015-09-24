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

void DrawSquare( float x, float y )
{

	float siz = 1;

	float getcol = 1-(a->getVal( x, y )+1)/2.0f;

	glColor3f( getcol, getcol, getcol );
	
	glBegin( GL_TRIANGLE_FAN );
		glVertex2f( x+(siz*x), y+(siz*y) );
		glVertex2f( x+(siz*x)+siz, y+(siz*y) );
		glVertex2f( x+(siz*x)+siz, y+(siz*y)+siz );
		glVertex2f( x+(siz*x), y+(siz*y)+siz );
	glEnd();


}

void Draw()
{

	for( int y = 0; y < 600; y++ )
	{

		for( int x = 0; x < 800; x++ )
		{

			DrawSquare( x, y );

		}

	}
}

int main()
{

	glfwInit();
	GLFWwindow *window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "Perlin Noise", NULL, NULL );
	glfwMakeContextCurrent( window );

	Reshape( window, WINDOW_WIDTH, WINDOW_HEIGHT );

	srand(time(nullptr));
	a = new Noise( 20 );

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