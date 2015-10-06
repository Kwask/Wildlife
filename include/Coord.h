#ifndef COORD_H
#define COORD_H

struct Coord
{
	Coord();
	Coord( float const xPos, float const yPos );
	~Coord();

	float xPos;
	float yPos;

	bool operator==( Coord const b ) const;

	Coord operator+( Coord const b ) const;
	Coord operator-( Coord const b ) const;
	Coord operator=( Coord const b ) const;
};

#endif