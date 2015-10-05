#include <stdlib.h>
#include <time.h>
#include <string>
#include "Debug.h"
#include "Engine.h"
#include "FiniteStateMachine.h"
#include "State.h"
#include "EngineStates.h"


Engine* Engine::instance_ = nullptr;

Engine::Engine()
{
	srand( time(nullptr));

	debugging( "ENGINE INSTANTIZED" );
	debugging( "ENGINE STARTING..." );
	state_.forceState( &EngineStateMachine::start );
	debugging( "ENGINE STARTED." );
}

Engine::~Engine()
{
	instance_ = nullptr;
}

Engine* Engine::getInstance()
{
	if( !instance_ )
	{
		instance_ = new Engine;
	}
	
	return instance_;
}

void Engine::resetInstance()
{
	delete instance_;
	instance_ = nullptr;
}

unsigned int Engine::getRand( unsigned int mod )
{
	if( !mod )
	{
		return rand();
	}
	else
	{
		return rand()%mod;
	}
}

void Engine::handle()
{
	while( !shouldStop() )
	{
		state_.changeState();
	}
}

bool Engine::shouldStop()
{
	if( state_.currentState() == nullptr )
	{
		return true;
	}

	return false;
}
