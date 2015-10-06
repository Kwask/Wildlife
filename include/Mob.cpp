#include <vector>
#include <algorithm>
#include <string>
#include "Engine.h"
#include "Mob.h"
#include "Debug.h"
#include "EngineStateMachine.h"
#include "Coord.h"

std::vector<Mob*> Mob::container;

Mob::Mob()
{
	initiliaze();

	// Adds this object to the global mob list
	container.push_back( this );
}

Mob::~Mob()
{
	// Uses the erase-remove idiom to remove this object from the static vector
	container.erase( std::remove( container.begin(), container.end(), this ), container.end() );
}

void Mob::deleteAll()
{
	// Deletes all instances of mobs
	for( unsigned int i = 0; i < container.size(); i++ )
	{
		delete container[i];		
	}
}

int Mob::mobCount()
{
	return container.size();
}

int Mob::xPos()
{
	return pos_.xPos;
}

int Mob::yPos()
{
	return pos_.yPos;
}

Mob* Mob::getMob()
{
	return this;
}

Mob* Mob::target()
{
	return target_;
}

void Mob::initiliaze()
{
	target_ = nullptr;
	
	pos_.xPos = Engine::getRand( EngineStateMachine::render.window_width );
	pos_.yPos = Engine::getRand( EngineStateMachine::render.window_height );

	x_vel_ = 0;
	y_vel_ = 0;
}

void Mob::xPos( int const x_pos )
{
	pos_.xPos = x_pos;
}

void Mob::yPos( int const y_pos )
{
	pos_.yPos = y_pos;
}

void Mob::target( Mob* const target )
{
	target_ = target;
}
