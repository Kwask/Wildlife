#include "EngineStateMachine.h"

EngineStart EngineStateMachine::start;
EngineProcess EngineStateMachine::process;
EnginePoll EngineStateMachine::poll;
EngineRender EngineStateMachine::render;
EngineStop EngineStateMachine::stop;