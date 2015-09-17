#ifndef WORLDGEN_H
#define WORLDGEN_H

struct coord
{

	float x, y;

};

struct rect
{

	coord _pos;
	float _w, _h;

};

class Obstacle
{

	public:

		Obstacle( float x, float y );

		rect *getRect();

		

};

#endif