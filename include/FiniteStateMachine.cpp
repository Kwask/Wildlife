#include "Debug.h"
#include "FiniteStateMachine.h"
#include "State.h"

FiniteStateMachine::FiniteStateMachine()
{
	state_ = nullptr;
}

FiniteStateMachine::FiniteStateMachine( State* const state )
{
	state_ = state;
}

FiniteStateMachine::~FiniteStateMachine()
{
	cleanup();
}

void FiniteStateMachine::cleanup()
{
	if( state_ )
	{
		state_->cleanup();
		state_ = nullptr;
	}
}

void FiniteStateMachine::changeState()
{
	if( state_ ) // problem point
	{
		state_ = state_->handle();
	}
}

void FiniteStateMachine::forceState( State* const state )
{
	cleanup();
	state_ = state;
}

char const* FiniteStateMachine::getStateName()
{
	return state_->getName();
}
