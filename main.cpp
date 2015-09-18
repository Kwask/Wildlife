#include "Engine.h"

int main( int argc, char **argv )
{
	Enigne* engine = Engine::getInstance();

	while( !engine.shouldStop() )
	{
		engine->nextState();
	}

	delete *engine;
}