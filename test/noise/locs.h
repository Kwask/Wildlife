#ifndef LOCS_H
#define LOCS_H

#include <vector>

//The different types of obstacles.
enum class Obstac { TREE, ROCK, BUSH };

//Coordinates
template<class dataType>
struct Coord
{

	dataType x, y;

};



//The placeholder class for obstacles themsevles.
class Obstacle
{

	public:
		Obstacle( Obstac type, int x, int y );
		
		Obstac GetType();
		Coord<float> GetPos();

	private:
		Obstac _type;
		Coord<float> _pos;


};

Obstacle::Obstacle( Obstac type, int x, int y )
{

	_type = type;
	_pos.x = x;
	_pos.y = y;

}

Obstac Obstacle::GetType()
{

	return _type;

}

Coord<float> Obstacle::GetPos()
{

	return _pos;

}

class Map
{

	public:
		Map( int sizex, int sizey );

		int GetSize();
		Obstacle GetElement( int i );

	private:
		std::vector<Obstacle> dat;

};

int Map::GetSize()
{

	return dat.size();

}

Obstacle Map::GetElement( int i )
{

	return dat[i];

}

Map::Map( int sizex, int sizey )
{

	for( int i = 0; i < (sizex*sizey)/100.0f; i++ )
	{

		int randVal = rand()%10;
		int randx = rand()%sizex;
		int randy = rand()%sizey;

		bool isCreating = false;

		Obstac createType;

		//Go through to deicde which to place where based on the random value.
		switch( randVal )
		{

			case 0:
			{

				isCreating = true;
				createType = Obstac::TREE;
				break;

			}
			case 1:
			{

				isCreating = true;
				createType = Obstac::ROCK;
				break;

			}
			case 2:
			{

				isCreating = true;
				createType = Obstac::BUSH;
				break;

			}

		}

		if( isCreating )
		{

			dat.push_back( Obstacle( createType , randx, randy ) );

		}

	}
	
}

#endif