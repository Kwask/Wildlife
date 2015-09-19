#ifndef MOB_H
#define MOB_H

#include "FiniteStateMachine.h"

class Mob
{
private:
	static unsigned int mob_count_;
	static unsigned int mob_ID_next_;

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

	int xPos();
	int yPos();
	int mobCount();
	int mobID();
	int targetID();

	void xPos( const int x_pos_ );
	void yPos( const int y_pos_ );
	void targetID( const int target_ID_ );
	void process();
};

#endif
