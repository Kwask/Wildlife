#ifndef MOB_H
#define MOB_H

#include "FiniteStateMachine.h"

class Mob
{
private:
	static unsigned int mob_count_;

	FiniteStateMachine mind_;

	Mob* target_;

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
	
	Mob* getMob();
	Mob* target();

	void xPos( int const x_pos );
	void yPos( int const y_pos );
	void target( Mob* const target );
	void process();
};

#endif
