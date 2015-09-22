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

enum class OBS_TYPE = { TREE, BUSH, ROCK };

class Obstacle
{

	public:

		Obstacle( OBS_TYPE a, float x, float y );

		rect *getRect();

	private:
		OBS_TYPE _flag;

		rect pos;	

};

Obstacle::Obstacle( OBS_TYPE a )
{

	_flag = a;
	pos._pos.x = x;
	pos._pos.y = y;


}

#endif
