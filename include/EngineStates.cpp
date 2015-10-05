#include <GLFW/glfw3.h>
#include "State.h"
#include "EngineStates.h"
#include "EngineStateMachine.h"
#include "GLFWFuncs.h"
#include "Mob.h"

// EngineStart
EngineStart::~EngineStart() {}

void EngineStart::cleanup() {}

State* EngineStart::handle()
{	
	//Do all initialization.
	glfwInit();
	debugging("GLFW INITIALIZED.");
	
	EngineStateMachine::render.window = glfwCreateWindow( EngineStateMachine::render.window_width, EngineStateMachine::render.window_height, "Wildlife", nullptr, nullptr );
	glfwMakeContextCurrent( EngineStateMachine::render.window );
	
	glfwSetWindowSizeCallback( EngineStateMachine::render.window, GLFWResize );
	GLFWResize( EngineStateMachine::render.window, EngineStateMachine::render.window_width, EngineStateMachine::render.window_height );

	glfwSwapInterval( 1 );

	// Just creates 100 mobs, all stored in Mob::container_
	for( int i = 0; i < 100; i++ )
	{
		new Mob;
	}

	return &EngineStateMachine::process;
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
	glfwPollEvents();

	// If the window exit button was pressed, tansition to stop
	if( glfwWindowShouldClose( EngineStateMachine::render.window ))
	{
		debugging("WINDOW CLOSING.");
		return &EngineStateMachine::stop;
	}

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
	glfwSwapBuffers( window );

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
	debugging("ENGINE STOPPING...");

	// Deletes all instances of Mob that were created
	Mob::deleteAll();

	// If there's a window, destroy it and terminate GLFW
	if( EngineStateMachine::render.window )
	{
		glfwDestroyWindow( EngineStateMachine::render.window );
		glfwTerminate();
		debugging("GLFW TERMINATED.");
	}

	debugging("ENGINE STOPPED.");
	return nullptr;
}

char const* EngineStop::getName()
{
	return name;
}
