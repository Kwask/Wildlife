#include "State.h"
#include "EngineStates.h"
#include "EngineStateMachine.h"

// EngineStart
EngineStart::~EngineStart() {}

void EngineStart::cleanup()
{

}

State* EngineStart::handle()
{
	debugging("ENGINE STARTING...");
	return &EngineStateMachine::process;
	debugging("ENGINE STARTED.");
}

// EngineProcess
EngineProcess::~EngineProcess() {}

void EngineProcess::cleanup()
{
	
}

State* EngineProcess::handle()
{
	return &EngineStateMachine::poll;
}

// EnginePoll
EnginePoll::~EnginePoll() {}

void EnginePoll::cleanup()
{
	
}

State* EnginePoll::handle()
{
	return &EngineStateMachine::render;
}

// EngineRender
EngineRender::~EngineRender() {}

void EngineRender::cleanup()
{
	
}

State* EngineRender::handle()
{
	return &EngineStateMachine::process;
}

// EngineStop
EngineStop::~EngineStop() {}

void EngineStop::cleanup()
{
	
}

State* EngineStop::handle()
{
	return &EngineStateMachine::stop;
}
