#include "include/Engine.h"
#include "include/Debug.h"

#include <iostream>

int main( int argc, char **argv )
{
	debugging("ENGINE INSTANTIZING...");
	Engine* engine = Engine::getInstance();

	debugging("ENGINE DELETING...");
	Engine::resetInstance();
	debugging("ENGINE DELETED.");
}