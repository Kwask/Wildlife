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
	state_.changeState( &EngineStateMachine::start );
//	debugging( "ENGINE STATE: " + std::string( state_.getStateName() ) );
}

Engine::~Engine()
{
	delete instance_;
}

Engine* Engine::getInstance()
{
	Engine* instance = instance_;

	if( !instance_ )
	{
		instance_ = new Engine;
	}
	
	return instance;
}

void Engine::handle()
{
	state_.changeState();
}
