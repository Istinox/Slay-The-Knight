#include "LevelCreator.h"

// Ne pas utiliser pour le moment.
void LevelCreator::OnEnter()
{
	// Le positionnement est étrange je sais, mais bon.. C'est ça ou je dois tout changer dans le CameraComponent.
	camera = CreateGameObject<Camera>("Camera", 400.f, sf::FloatRect({ 1280.f / (2.f / zoom), 720.f / (2.f / zoom) }, {1280.f, 720.f}));
	camera->getComponent<CameraComponent>()->SetZoom(zoom);

	GameObject* tile = CreateGameObject<GameObject>();
	tile->createComponent<LevelEditor>();
}
