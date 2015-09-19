#ifndef STATE_H
#define STATE_H

class State
{
protected:
	char const* name = nullptr; 

public:
	State();
	virtual ~State() = 0;

	virtual State* handle() = 0; // Handles all actions of the current state and transition to the next state
	char const* toString();
};

char const* State::toString()
{
	return name;
}

#endif