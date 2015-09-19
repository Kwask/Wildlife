#include "Mob.h"

unsigned int Mob::mob_count_ = 0;
unsigned int Mob::mob_ID_next_ = 0;

Mob::Mob()
{
	initiliaze();

	mob_ID_next_++;
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

int Mob::mobID()
{
	return mob_ID_;
}

int Mob::targetID()
{
	return target_ID_;
}

void Mob::initiliaze()
{
	mob_ID_ = mob_ID_next_;
	target_ID_ = 0;
	
	x_pos_ = 0;
	y_pos_ = 0;

	x_vel_ = 0;
	y_vel_ = 0;
}

void Mob::xPos( const int x_pos_ )
{
	this->x_pos_ = x_pos_;
}

void Mob::yPos( const int y_pos_ )
{
	this->y_pos_ = y_pos_;
}

void Mob::targetID( const int target_ID_ )
{
	this->target_ID_ = target_ID_;
}
