#ifndef ENGINE_H
#define ENGINE_H

#include "FiniteStateMachine.h"

class Engine
{
private:
	Engine();

	void start();
	void process();
	void stop();
	void render();
	void poll();

	static void simStart();
	static void simProcess();
	static void simStop();
	static void simRender();
	static void simPoll();

	FiniteStateMachine state;
	static Engine* instance;

public:
	static Engine* getInstance();
	virtual ~Engine();

	void nextState();
	
	bool shouldStop();
};

Engine* Engine::instance = nullptr;

Engine::Engine()
{
	state.pushState( start );
}

Engine::~Engine()
{

}

Engine* Engine::getInstance()
{
	if( !instance )
	{
		instance =  new Engine;
	}

	return instance;
}

void Engine::start()
{
	state.pushState( simProcess );
}

void Engine::process()
{
	poll();
	render();
}

void Engine::stop()
{

}

void Engine::render()
{

}

void Engine::poll()
{

}

void Engine::nextState()
{
	state.process();
}

bool Engine::shouldStop()
{
	if( state.getState() == nullptr )
	{
		return true;
	}

	return false;
}

#endif
