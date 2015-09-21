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
	debugging("FiniteStateMachine::cleanup() called");

	if( state_ )
	{
		state_->cleanup();
		state_ = nullptr;
		debugging("state_.cleanup() and assigned to nullptr");
	}
	else
	{
		debugging("state_ already nullptr");	
	}
}

void FiniteStateMachine::changeState()
{
	debugging("FiniteStateMachine::changestate() called");

	if( state_ ) // problem point
	{
		debugging("state_ is not nullptr");
		//state_ = state_->handle();
	}
	else
	{
		debugging("state_ is nullptr");
	}
}

void FiniteStateMachine::forceState( State* const state )
{
	debugging("FiniteStateMachine::forcestate() called with forced state");
	cleanup();
	state_ = state;

	if( state_ )
	{
		debugging("state_ given a state");
	}
	else
	{
		debugging("state_ is still nullptr");
	}
}

char const* FiniteStateMachine::getStateName()
{
	debugging("FiniteStateMachine::getStateName() called");
	return state_->getName();
}
