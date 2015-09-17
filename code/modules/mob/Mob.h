#ifndef MOB_H
#define MOB_H

#include "FiniteStateMachine.h"

class Mob
{
private:
	static unsigned int mob_count_ = 0;
	static unsigned int mob_ID_next_ = 0;

	FiniteStateMachine mind_;

	unsigned int mob_ID_;
	unsigned int target_ID_;

	int x_pos_;
	int y_pos_;

	float x_vel_;
	float y_vel_;

	void initiliaze();

public:
	Mob();
	~Mob();

	int x_pos();
	int y_pos();
	int mob_count();
	int mob_ID();
	int target_ID();

	void x_pos( const int x_pos_ );
	void y_pos( const int y_pos_ );
	void target_ID( const int target_ID_ );
};

Mob::Mob()
{
	initiliaze();

	mob_ID_next++;
	mob_count++;
}

Mob::~Mob()
{
	mob_count--;
}

int Mob::x_pos()
{
	return x_pos_;
}

int Mob::y_pos()
{
	return y_pos_;
}

int Mob::mob_count()
{
	return mob_count_;
}

int Mob::mob_ID()
{
	return mob_ID_;
}

int Mob::target_ID()
{
	return target_ID_;
}

void Mob::initiliaze()
{
	mob_ID_ = mob_ID_next;
	target_ID_ = 0;
	
	x_pos_ = 0;
	y_pos_ = 0;

	x_vel_ = 0;
	y_vel_ = 0;
}

void Mob::x_pos( const int x_pos_ )
{
	this->x_pos_ = x_pos_;
}

void Mob::y_pos( const int y_pos_ )
{
	this->y_pos_ = y_pos_;
}

void Mob::target_ID( const int target_ID_ )
{
	this->target_ID_ = target_ID_;
}

#endif
