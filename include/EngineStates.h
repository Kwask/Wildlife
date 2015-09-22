#ifndef ENGINESTATES_H
#define ENGINESTATES_H

#include <GLFW/glfw3.h>
#include "State.h"
#include "Debug.h"

// Starts the engine
class EngineStart : public State
{
protected:
	char const* name = "EngineStart";

public:
	~EngineStart();

	void cleanup();

	State* handle();

	char const* getName();
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

	void cleanup();

	State* handle();

	char const* getName();
};

// Starts the process series
class EnginePoll : public State
{
protected:
	char const* name = "EnginePoll";

public:
	~EnginePoll();

	void cleanup();

	State* handle();

	char const* getName();
};

// Processes events
class EngineRender : public State
{
protected:
	char const* name = "EngineRender";

public:
	int window_width = 800;
	int window_height = 600;

	GLFWwindow *window = nullptr;

	~EngineRender();

	void cleanup();

	State* handle();

	char const* getName();
};

// Stops the engine
class EngineStop : public State
{
protected:
	char const* name = "EngineStop";

public:
	~EngineStop();

	void cleanup();

	State* handle();

	char const* getName();
};

#endif