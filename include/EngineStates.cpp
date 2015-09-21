#include "State.h"
#include "EngineStates.h"
#include "EngineStateMachine.h"

// EngineStart
EngineStart::~EngineStart() {}

void EngineStart::cleanup() {}

State* EngineStart::handle()
{
	debugging("ENGINE STARTING...");
	return &EngineStateMachine::process;
	debugging("ENGINE STARTED.");
}

char const* EngineStart::getName()
{
	return name;
}

// EngineProcess
EngineProcess::~EngineProcess() {}

void EngineProcess::cleanup() {}

State* EngineProcess::handle()
{
	return &EngineStateMachine::poll;
}

char const* EngineProcess::getName()
{
	return name;
}

// EnginePoll
EnginePoll::~EnginePoll() {}

void EnginePoll::cleanup() {}

State* EnginePoll::handle()
{
	return &EngineStateMachine::render;
}

char const* EnginePoll::getName()
{
	return name;
}

// EngineRender
EngineRender::~EngineRender() {}

void EngineRender::cleanup() {}

State* EngineRender::handle()
{
	return &EngineStateMachine::process;
}

char const* EngineRender::getName()
{
	return name;
}

// EngineStop
EngineStop::~EngineStop() {}

void EngineStop::cleanup() {}

State* EngineStop::handle()
{
	return &EngineStateMachine::stop;
}

char const* EngineStop::getName()
{
	return name;
}
