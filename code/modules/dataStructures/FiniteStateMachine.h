#ifndef FINITESTATEMACHINE_H
#define FINITESTATEMACHINE_H

#include <stack>

typedef void(*voidptr)(); // dear god, I hate this syntax

class FiniteStateMachine
{
private:
	std:stack <voidptr> stack;

public:
	FiniteStateMachine();
	~FiniteStateMachine();
	
	void process();
	void pushState( voidptr state );

	voidptr popState();
	voidptr getState();
};

FiniteStateMachine::FiniteStateMachine()
{

}

FiniteStateMachine::~FiniteStateMachine()
{

}

void FiniteStateMachine::process()
{
	voidptr state = getState();

	if( state != nullptr )
	{
		state();
	}
}

void FiniteStateMachine::pushState( voidptr state )
{
	if( state != getState() )
	{
		stack.push( state );
	}
}

voidptr FiniteStateMachine::popState()
{
	if( stack.size() > 0 )
	{
		return stack.pop();
	}
	else
	{
		return nullptr;
	}
}

voidptr FiniteStateMachine::getState()
{
	if( stack.size() > 0 )
	{
		return stack.top();
	}
	else
	{
		return nullptr;
	}
}

#endif