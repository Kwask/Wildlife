#include "Debug.h"
#include "FiniteStateMachine.h"
#include "State.h"

FiniteStateMachine::FiniteStateMachine()
{
	state_ = nullptr;
}

FiniteStateMachine::FiniteStateMachine( State* state )
{
	state_ = state;
}

FiniteStateMachine::~FiniteStateMachine()
{
	cleanup();
}

void FiniteStateMachine::cleanup()
{
	debugging("FiniteStateMachine::cleanup() called");

	if( state_ != nullptr )
	{
		delete state_;
		state_ = nullptr;
	}
}

void FiniteStateMachine::changeState()
{
	debugging("FiniteStateMachine::changestate() called");
	if( state_ != nullptr )
	{
		state_ = state_->handle();
	}
}

void FiniteStateMachine::changeState( State* state )
{
	debugging("FiniteStateMachine::changestate() called with forced state");
	cleanup();
	state_ = state;
}

char const* FiniteStateMachine::getStateName()
{
	debugging("FiniteStateMachine::getStateName() called");
	return state_->toString();
}
