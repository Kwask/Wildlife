#include "include/Engine.h"
#include "include/Debug.h"

int main( int argc, char **argv )
{
	debugging("ENGINE INSTANTIZING...");
	Engine* engine = Engine::getInstance();

	while( !engine->shouldStop() )
	{
		engine->handle();
	}

	delete engine;
}