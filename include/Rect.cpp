#include "Rect.h"

Rect::Rect()
{
	size.xPos = 0;
	size.yPos = 0;
}


Rect::Rect( float const xPos, float const yPos, float const width, float const height )
{
	pos.xPos = xPos;
	pos.yPos = yPos;

	size.xPos = width;
	size.yPos = height;
}

Rect::Rect( Coord const pos, Coord const bounds )
{
	this->pos = pos;
	this->size = bounds-pos; // The size is offset of the bounds from pos
}


Rect::~Rect()
{

}


Coord Rect::getPos() const
{
	return pos;
}


Coord Rect::getSize() const
{
	return size;
}


Coord Rect::getBound() const
{
	return pos+size;
}