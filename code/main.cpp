#include <GL/glfw3.h>
#include <iostream>

void Resize( GLFWwindow *window, int width, int height )
{

	glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
	glMatrixMode( GL_PROJECTION );
	
	glLoadIdentity();
	
	glOrtho( 0, width, 0, height, 1.0f, 100.0f );
	glMatrixMode( GL_MODELVIEW );

}

int main( int argc, char **argv )
{

	static int WINDOW_WIDTH = 800;
	static int WINDOW_HEIGHT = 600;

	glfwInit();
	GLFWwindow *window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "Hello", nullptr, nullptr );
	glfwMakeContextCurrent( window );
	glfwSetWindowSizeCallback( window, Resize );
	Resize( window, WINDOW_WIDTH, WINDOW_HEIGHT );

	glfwSwapInterval( 1 );

	while( !glfwWindowShouldClose( window ) )
	{

		glClear( GL_COLOR_BUFFER_BIT );
		glLoadIdentity();

		glTranslatef( 0.0f, 0.0f, -1.0f );
		Draw();

		glfwPollEvents();
		glfwSwapBuffers( window );

	}

	glfwDestroyWindow( window );
	glfwTerminate();

}