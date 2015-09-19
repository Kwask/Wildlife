#include "State.h"
#include "EngineStates.h"

// EngineStart
State* EngineStart::handle()
{
	debugging("ENGINE STARTING...");
	return new EngineProcess;
	delete this;
	debugging("ENGINE STARTED.");
}

// EngineProcess
State* EngineProcess::handle()
{
	return new EnginePoll;
	delete this;
}

// EnginePoll
State* EnginePoll::handle()
{
	return new EngineRender;
	delete this;
}

// EngineRender
State* EngineRender::handle()
{
	return new EngineProcess;
	delete this;
}

// EngineStop
State* EngineStop::handle()
{
	return this;
}
