#include "Core/Engine.h"
#include "LevelEditor/LevelEditor.h"

#include "MainMenu.h"
#include "LevelCreator.h"
#include "Level1.h"

int main()
{
	Engine* engine = Engine::GetInstance();
	SceneManager::getSceneManager()->setScene(new MainMenu);
	engine->Run();

	return 0;
}