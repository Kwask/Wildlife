#include "Coord.h"

Coord::Coord()
{
	this->xPos = 0;
	this->yPos = 0;
}

Coord::Coord( float const xPos, float const yPos )
{
	this->xPos = xPos;
	this->yPos = yPos; 
}

Coord::~Coord()
{

}

bool Coord::operator==( Coord const b ) const
{
	if( this->xPos != b.xPos )
	{
		return false;
	}
	else if ( this->yPos != b.yPos )
	{
		return false;
	}

	return true;
}

Coord Coord::operator+( Coord const b ) const
{
	Coord a;
	a.xPos = this->xPos + b.xPos;
	a.yPos = this->yPos + b.yPos;
	return a;
}

Coord Coord::operator-( Coord const b ) const
{
	Coord a;
	a.xPos = this->xPos - b.xPos;
	a.yPos = this->yPos - b.yPos;
	return a;
}

Coord Coord::operator=( Coord const b ) const
{
	Coord a;
	a.xPos = b.xPos;
	a.yPos = b.yPos;
	return a;
}
