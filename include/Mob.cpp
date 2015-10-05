#include <vector>
#include <algorithm>
#include <string>
#include "Mob.h"
#include "Debug.h"

std::vector<Mob*> Mob::container_;

Mob::Mob()
{
	initiliaze();

	// Adds this object to the global mob list
	container_.push_back( this );
}

Mob::~Mob()
{
	// Uses the erase-remove idiom to remove this object from the static vector
	container_.erase( std::remove( container_.begin(), container_.end(), this ), container_.end() );
}

void Mob::deleteAll()
{
	// Deletes all instances of mobs
	for( unsigned int i = 0; i < container_.size(); i++ )
	{
		delete container_[i];		
	}
}

int Mob::mobCount()
{
	return container_.size();
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
	
	x_pos_ = 0;
	y_pos_ = 0;

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
