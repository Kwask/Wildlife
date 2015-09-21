 #ifndef FINITESTATEMACHINE_H
#define FINITESTATEMACHINE_H

#include "State.h"

/*
	This is a finite state machine that utilizes a stack of function
	pointers to switch between states. To switch between states, use 
	the pushState and popState.

	Each mob has a FSM as a "mind" and so to use it, you need to define 
	the mob's different behaviors as void funcs.
*/

class FiniteStateMachine
{
protected:
	void cleanup();

	State* state_;

public:
	FiniteStateMachine();
	FiniteStateMachine( State* const state );
	~FiniteStateMachine();

	void changeState();
	void forceState( State* const state );
	char const* getStateName();

};

#endif
