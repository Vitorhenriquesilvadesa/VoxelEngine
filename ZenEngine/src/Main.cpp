#include <Engine.h>

using namespace Zen;

int main()
{
	Engine::Init();
	
	while (!Engine::GetFlag(ApplicationFlag::WindowClosed))
	{
		Engine::Update();
	}

	Engine::Shutdown();

	return 0;
}