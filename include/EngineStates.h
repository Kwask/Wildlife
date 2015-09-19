#ifndef ENGINESTATES_H
#define ENGINESTATES_H

#include "State.h"
#include "Debug.h"

// Starts the engine
class EngineStart : public State
{
protected:
	char const* name = "EngineStart";

public:
	~EngineStart();

	virtual State* handle();

};

// Starts the process series of events
// Loop:
//		EngineProcess -> EnginePoll -> EngineRender
class EngineProcess : public State
{
protected:
	char const* name = "EngineProcess";

public:
	~EngineProcess();

	virtual State* handle();
};

// Starts the process series
class EnginePoll : public State
{
protected:
	char const* name = "EnginePoll";

public:
	~EnginePoll();

	virtual State* handle();
};

// Processes events
class EngineRender : public State
{
protected:
	char const* name = "EngineRender";

public:
	~EngineRender();

	virtual State* handle();
};

// Stops the engine
class EngineStop : public State
{
protected:
	char const* name = "EngineStop";

public:
	~EngineStop();

	virtual State* handle();
};

#endif