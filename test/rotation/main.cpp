#include <GL/glfw3.h>
#include <iostream>

#include <vector>
#include <cmath>

const float pi = 3.14159;

void Resize( GLFWwindow *window, int width, int height )
{

	glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
	glMatrixMode( GL_PROJECTION );
	
	glLoadIdentity();
	
	glOrtho( 0, width, 0, height, 1.0f, 100.0f );
	glMatrixMode( GL_MODELVIEW );

}

struct coord
{

	public:
		coord();
		float x, y;

};

coord::coord()
{

	x = 0.0f;
	y = 0.0f;

}

float i;

float getinclin( float refx, float refy, float posx, float posy )
{

    int delx = posx-refx, dely = posy-refy;
    float ret = 0.0f;

<<<<<<< HEAD:test/main.cpp
    if( delx==0 )
=======
    if( delx == 0 )
>>>>>>> 1f8182218d7b29106bdea057ca181a8a239a7935:test/rotation/main.cpp
    {
        if( dely < 0.0f )
        {

			ret = 270.0f;

        }    
        else
        {
         
            ret = 90.0f;
       	
       	}
    }

<<<<<<< HEAD:test/main.cpp
    if( dely==0 )
=======
    if( dely == 0 )
>>>>>>> 1f8182218d7b29106bdea057ca181a8a239a7935:test/rotation/main.cpp
    {

        if( delx < 0.0f )
        {

        	ret = 90.0f;

        }    
        else
        {

        	ret = 0.0f;

        }

    }

    if( delx!=0 && dely!=0 )
    {

		ret = atan( dely/delx )*57.2957795;

    }

    if( delx < 0 )
    {
		ret = ret+180;
    }

    return ret*0.0174532925;

}

coord rotateVector( coord in, float rotationangle )
{

	coord temp;

	float inclin = getinclin( 0, 0, in.x, in.y );
	float mag = sqrt(pow(in.x,2)+pow(in.y,2));

	inclin+=rotationangle;

	temp.x = cos( inclin )*mag;
	temp.y = sin( inclin )*mag;

	return temp;

}

coord makecoord( float x, float y )
{

	coord temp;
	temp.x = x;
	temp.y = y;

	return temp;

}

class Square
{

	private:
		std::vector<coord> verts;
		coord pos;

		float w, h;

		float ang;

	public:
		Square( float x, float y );

		void draw();
		void rotate( float ang );

};

Square::Square( float x, float y )
{

	w = 50.0f;
	h = 50.0f;

	pos = makecoord( x, y );

	for( int i = 0; i < 4; i++ )
	{

		verts.push_back( coord() );

	}

	verts[0] = makecoord( -w, -h );
	verts[1] = makecoord( w, -h );
	verts[2] = makecoord( w, h );
	verts[3] = makecoord( -w, h );

}

void Square::rotate( float ang )
{

	this->ang = ang;

}

void Square::draw()
{

	//Run the rotation function for each corner of the square.
	coord a = rotateVector( makecoord( verts[0].x, verts[0].y ), this->ang );
	coord b = rotateVector( makecoord( verts[1].x, verts[1].y ), this->ang );
	coord c = rotateVector( makecoord( verts[2].x, verts[2].y ), this->ang );
	coord d = rotateVector( makecoord( verts[3].x, verts[3].y ), this->ang );

	float verts[] = 
	{

		a.x+pos.x, a.y+pos.y,
		b.x+pos.x, b.y+pos.y,
		c.x+pos.x, c.y+pos.y,
		d.x+pos.x, d.y+pos.y

	};

	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 2, GL_FLOAT, 0, verts );
	glDrawArrays( GL_TRIANGLE_FAN, 0, 4 );
	glDisableClientState( GL_VERTEX_ARRAY );

}

int main( int argc, char **argv )
{

	//Declare the height and width of the window.
	static int WINDOW_WIDTH = 800;
	static int WINDOW_HEIGHT = 600;

	//Do all initialization.
	glfwInit();
	GLFWwindow *window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "Hello", nullptr, nullptr );
	glfwMakeContextCurrent( window );
	glfwSetWindowSizeCallback( window, Resize );
	Resize( window, WINDOW_WIDTH, WINDOW_HEIGHT );

	glfwSwapInterval( 1 );

	//Creating the square.
	Square test( 300, 300 );

	while( !glfwWindowShouldClose( window ) )
	{

		//Clearing the color buffer bit.
		glClear( GL_COLOR_BUFFER_BIT );
		glLoadIdentity();

		//Pushing all the objects back a z level so they don't hit the clippig pane.
		glTranslatef( 0.0f, 0.0f, -1.0f );
		test.rotate( i );
		test.draw();

<<<<<<< HEAD:test/main.cpp
		//i+=0.01f;
=======
		i+=0.01f;
		if( i >= pi*2 )
		{

			i = 0.0f;

		}
>>>>>>> 1f8182218d7b29106bdea057ca181a8a239a7935:test/rotation/main.cpp

		glfwPollEvents();
		glfwSwapBuffers( window );

	}

	glfwDestroyWindow( window );
	glfwTerminate();

}