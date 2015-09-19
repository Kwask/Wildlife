#include "include/Engine.h"
#include "include/Debug.h"

int main( int argc, char **argv )
{
	debugging("ENGINE INSTANTIZING...");
	Engine* engine = Engine::getInstance();

	while( true )
	{
		engine->handle();
	}

	delete engine;
}