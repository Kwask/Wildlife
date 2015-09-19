#include "Engine.h"

Engine* Engine::instance_ = nullptr;

Engine::Engine()
{
	debugging( "ENGINE INSTANTIZED" );
	FiniteStateMachine state_( new EngineStart );
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
	FiniteStateMachine.handle();
}

bool Engine::shouldStop()
{
	if( state_.getState() == nullptr )
	{
		return true;
	}

	return false;
}
