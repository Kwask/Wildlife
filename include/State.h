#ifndef STATE_H
#define STATE_H

class State
{
protected:
	char const* name = ""; 

public:
	virtual State* handle() = 0; // Handles all actions of the current state and transition to the next state
	char const* toString();
};

#endif