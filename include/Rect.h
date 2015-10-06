#ifndef RECT_H
#define RECT_H

#include "Coord.h"

struct Rect
{
	Coord pos;
	Coord size;

	Rect();
	Rect( float const xPos, float const yPos, float const width, float const height );
	Rect( Coord const pos, Coord const bounds );
	~Rect();

	Coord getPos() const; // Returns the bottom left corner
	Coord getSize() const; // Returns the size coords
	Coord getBound() const; // Returns the pos + size, effectively the top right corner
};

#endif