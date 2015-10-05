#include <iostream>
#include <GL/glfw3.h>

#include "locs.h"

#include <fstream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void Reshape( GLFWwindow *wind, float width, float height )
{

	glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0, width, 0, height, 1.0f, 100.0f );
	glMatrixMode( GL_MODELVIEW );

}

void DrawSquare( float x, float y, float w )
{

	glBegin( GL_TRIANGLE_FAN );
		glVertex2f( x, y );
		glVertex2f( x+w, y );
		glVertex2f( x+w, y+w );
		glVertex2f( x, y+w );
	glEnd();

}

void Draw( Map dat )
{

	for( int i = 0; i < dat.GetSize(); i++ )
	{
		
		Coord<float> pos = dat.GetElement( i ).GetPos();

		if( dat.GetElement( i ).GetType() == Obstac::TREE )
		{

			glColor3f( 0.2f, 0.9f, 0.2f );
			DrawSquare( pos.x, pos.y, 10 );

		}else if( dat.GetElement( i ).GetType() == Obstac::BUSH )
		{

			glColor3f( 0.4f, 0.8f, 0.4f );
			DrawSquare( pos.x, pos.y, 5 );

		}else if( dat.GetElement( i ).GetType() == Obstac::ROCK )
		{

			glColor3f( 0.4f, 0.4f, 0.4f );
			DrawSquare( pos.x, pos.y, 3 );

		}

	}

}

int main()
{

	glfwInit();
	GLFWwindow *window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "Generation", NULL, NULL );
	glfwMakeContextCurrent( window );

	Reshape( window, WINDOW_WIDTH, WINDOW_HEIGHT );

	srand(time(nullptr));

	glClearColor( 0.1f, 0.6f, 0.1f, 1.0f );
	Map gameMap( 800, 600 );

	std::ofstream output;
	output.open( "map.txt" );

	output << "TREE:\n";
	for( int i = 0; i < gameMap.GetSize(); i++ )
	{

		if( gameMap.GetElement(i).GetType() == Obstac::TREE )
		{

			output << gameMap.GetElement(i).GetPos().x << "," << gameMap.GetElement(i).GetPos().y << "\n";

		}

	}

	output << "ROCK:\n";
	for( int i = 0; i < gameMap.GetSize(); i++ )
	{

		if( gameMap.GetElement(i).GetType() == Obstac::ROCK )
		{

			output << gameMap.GetElement(i).GetPos().x << "," << gameMap.GetElement(i).GetPos().y << "\n";

		}

	}

	output << "BUSH:\n";
	for( int i = 0; i < gameMap.GetSize(); i++ )
	{

		if( gameMap.GetElement(i).GetType() == Obstac::BUSH )
		{

			output << gameMap.GetElement(i).GetPos().x << "," << gameMap.GetElement(i).GetPos().y << "\n";

		}

	}

	while( !glfwWindowShouldClose( window ) )
	{

		glClear( GL_COLOR_BUFFER_BIT );
		glLoadIdentity();
		glTranslatef( 0.0f, 0.0f, -1.0f );

		Draw( gameMap );

		glfwSwapBuffers( window );
		glfwPollEvents();

	}

}