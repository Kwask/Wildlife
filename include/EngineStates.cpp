#include "EngineStates.h"

// EngineStart
void EngineStart::State* handle()
{
	debugging("ENGINE STARTING...");
	return new EngineProcess;
	delete this;
	debugging("ENGINE STARTED.");
}

// EngineProcess
void EngineProcess::State* handle()
{
	return new EnginePoll;
	delete this;
}

// EnginePoll
void EnginePoll::State* handle()
{
	return new EngineRender;
	delete this;
}

// EngineRender
void EngineRender::State* handle()
{
	return new EngineProcess;
	delete this;
}

// EngineStop
void EngineStop::State* handle()
{

}
