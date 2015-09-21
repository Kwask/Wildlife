#include <string>
#include "Debug.h"
#include "Engine.h"
#include "FiniteStateMachine.h"
#include "State.h"
#include "EngineStates.h"

Engine* Engine::instance_ = nullptr;

Engine::Engine()
{
	debugging( "ENGINE INSTANTIZED" );
	debugging( "ENGINE STARTING..." );
	state_.forceState( &EngineStateMachine::start );
	debugging( "ENGINE STARTED." );
	debugging( "ENGINE STATE: " + std::string( state_.getStateName() ) );
}

Engine::~Engine()
{
	delete instance_;
}

Engine* Engine::getInstance()
{
	if( !instance_ )
	{
		instance_ = new Engine;
	}
	
	return instance_;
}

void Engine::handle()
{
	state_.changeState();
}
