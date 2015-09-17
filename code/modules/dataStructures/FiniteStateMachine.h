#ifndef FINITESTATEMACHINE_H
#define FINITESTATEMACHINE_H

#include <stack>

/*
	This is a finite state machine that utilizes a stack of function
	pointers to switch between states. To switch between states, use 
	the pushState and popState.

	Each mob has a FSM as a "mind" and so to use it, you need to define 
	the mob's different behaviors as void funcs.
*/ 

typedef void(*voidptr)(); // dear god, I hate this syntax

class FiniteStateMachine
{
private:
	std::stack <voidptr> stack_;

public:
	FiniteStateMachine();
	~FiniteStateMachine();
	
	void process();
	void pushState( voidptr state );
	void popState();
	
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
		stack_.push( state );
	}
}

void FiniteStateMachine::popState()
{
	stack_.pop();
}

voidptr FiniteStateMachine::getState()
{
	if( !stack_.empty() )
	{
		return stack_.top();
	}
	else
	{
		return nullptr;
	}
}

#endif
