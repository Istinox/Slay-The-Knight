#include "Core/Engine.h"
#include "LevelEditor/LevelEditor.h"

#include "Levels/MainMenu.h"
#include "Levels/LevelCreator.h"
#include "Levels/Level1.h"

int main()
{
	Engine* engine = Engine::GetInstance();
	SceneManager::getSceneManager()->setScene(new MainMenu);
	engine->Run();

	return 0;
}