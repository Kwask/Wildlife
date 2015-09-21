#include "Mob.h"

unsigned int Mob::mob_count_ = 0;

Mob::Mob()
{
	initiliaze();

	mob_count_++;
}

Mob::~Mob()
{
	mob_count_--;
}

int Mob::xPos()
{
	return x_pos_;
}

int Mob::yPos()
{
	return y_pos_;
}

int Mob::mobCount()
{
	return mob_count_;
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
