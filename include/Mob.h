#ifndef MOB_H
#define MOB_H

#include <vector>
#include "FiniteStateMachine.h"

class Mob
{
private:
	static std::vector<Mob*> container_;

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

	static void deleteAll();

	static int mobCount();

	int xPos();
	int yPos();
	
	Mob* getMob();
	Mob* target();

	void xPos( int const x_pos );
	void yPos( int const y_pos );
	void target( Mob* const target );
	void process();
};

#endif
