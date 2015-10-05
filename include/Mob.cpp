#include <vector>
#include <algorithm>
#include <string>
#include "Engine.h"
#include "Mob.h"
#include "Debug.h"
#include "EngineStateMachine.h"

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
	return x_pos_;
}

int Mob::yPos()
{
	return y_pos_;
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
	
	x_pos_ = Engine::getRand( EngineStateMachine::render.window_width );
	y_pos_ = Engine::getRand( EngineStateMachine::render.window_height );

	x_vel_ = 0;
	y_vel_ = 0;
}

void Mob::xPos( int const x_pos )
{
	x_pos_ = x_pos;
}

void Mob::yPos( int const y_pos )
{
	y_pos_ = y_pos;
}

void Mob::target( Mob* const target )
{
	target_ = target;
}
