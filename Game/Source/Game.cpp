#include "Core/Engine.h"
#include "LevelEditor/LevelEditor.h"

#include "MainMenu.h"
#include "LevelCreator.h"
#include "Level1.h"

int main()
{
	/*
	LevelEditor level;
	const std::string filePath = "Assets/Levels/Level1.txt";
	level.LoadFile(filePath);
	*/

	LevelEditor level;
	level.SaveFile("ffze");

	// TOUT fonctionne du 1er coup, je suis trop content :D
	Engine* engine = Engine::GetInstance();
	SceneManager::getSceneManager()->setScene(new MainMenu);
	engine->Run();

	return 0;
}