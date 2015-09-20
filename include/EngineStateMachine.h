#ifndef ENGINESTATEMACHINE_H
#define ENGINESTATEMACHINE_H

#include "FiniteStateMachine.h"
#include "EngineStates.h"

class EngineStateMachine : public FiniteStateMachine
{
public:
	static EngineStart start;
	static EngineProcess process;
	static EnginePoll poll;
	static EngineRender render;
	static EngineStop stop;
};

#endif