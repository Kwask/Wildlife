#include "State.h"
#include "EngineStates.h"
#include "EngineStateMachine.h"

// EngineStart
EngineStart::~EngineStart() {}

State* EngineStart::handle()
{
	debugging("ENGINE STARTING...");
	return &EngineStateMachine::process;
	debugging("ENGINE STARTED.");
}

// EngineProcess
EngineProcess::~EngineProcess() {}

State* EngineProcess::handle()
{
	return &EngineStateMachine::poll;
}

// EnginePoll
EnginePoll::~EnginePoll() {}

State* EnginePoll::handle()
{
	return &EngineStateMachine::render;
}

// EngineRender
EngineRender::~EngineRender() {}

State* EngineRender::handle()
{
	return &EngineStateMachine::process;
}

// EngineStop
EngineStop::~EngineStop() {}

State* EngineStop::handle()
{
	return &EngineStateMachine::stop;
}
