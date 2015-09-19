#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine()
{

}

FiniteStateMachine::FiniteStateMachine( State* state );
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
		delete state_;
		state_ = nullptr;
	}
}

void FiniteStateMachine::changeState()
{
	state_ = state_.handle();
}

void FiniteStateMachien::changeState( State* state );
{
	cleanup();
	state_ = state;
}

char* FiniteStateMachine::getStateName()
{
	return state_.toString();
}
