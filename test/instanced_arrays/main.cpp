#include <GL/glew.h>
#include <GL/glfw3.h>
#include <vector>

#include <iostream>

std::vector<float> verts;

void Reshape( GLFWwindow *wind, int width, int height )
{

	glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0, width, 0, height, 1.0f, 10.0f );
	glMatrixMode( GL_MODELVIEW );

}

void AddSquare( float x, float y, float w )
{

	const int CORD_COUNT = 12;

	float coords[] = 
	{

		x, y,
		x+w, y,
		x, y+w,

		x+w, y,
		x, y+w,
		x+w, y+w

	};

	for( int i = 0; i < CORD_COUNT; i++ )
	{

		verts.push_back( coords[i] );

	}

}

void Draw()
{

	const int CORDS_PER_PRIM = 6;

	glEnableClientState( GL_VERTEX_ARRAY );

	glVertexPointer( 2, GL_FLOAT, 0, verts.data() );
	glDrawArrays( GL_TRIANGLES, 0, verts.size()/2 );

	glDisableClientState( GL_VERTEX_ARRAY );

	verts.clear();

}

int main()
{

	glfwInit();

	GLFWwindow *window = glfwCreateWindow( 800, 600, "Instanced Arrays", nullptr, nullptr );
	glfwSetWindowSizeCallback( window, Reshape );
	glfwMakeContextCurrent( window );

	Reshape( window, 800, 600 );

	while( !glfwWindowShouldClose( window ) )
	{

		glClear( GL_COLOR_BUFFER_BIT );
		glLoadIdentity();

		for( int i = 0; i < 100; i++ )
		{

			AddSquare( rand()%800, rand()%600, 20 );

		}

		glTranslatef( 0.0f, 0.0f, -1.0f );
		Draw();

		glfwPollEvents();
		glfwSwapBuffers( window );

	}

	glfwTerminate();

}