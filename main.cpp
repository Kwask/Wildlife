#include "include/Engine.h"

int main( int argc, char **argv )
{
	Engine* engine = Engine::getInstance();

	while( !engine->shouldStop() )
	{
		engine->nextState();
	}

	delete engine;
}