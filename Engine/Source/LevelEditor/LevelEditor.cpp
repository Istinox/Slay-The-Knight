#include "LevelEditor/LevelEditor.h"

void LevelEditor::Start()
{
	for (int i = 0; i <= MAX_CELL_Y; i++)
	{
		for (int j = 0; j <= MAX_CELL_X; j++)
		{
			// le static_cast, pour éviter le warning C4244.
			const float SIZE_CELL_F = static_cast<float>(SIZE_CELL);

			std::pair<int, int> tileCoord = { j, i };
			int tileCoordX = tileCoord.first;
			int tileCoordY = tileCoord.second;

			Cell cell;
			cell.CellShape = sf::RectangleShape(sf::Vector2f(SIZE_CELL_F, SIZE_CELL_F));
			cell.cellCoord = { tileCoordX, tileCoordY };

			cell.CellShape.setPosition({ static_cast<float>(j * SIZE_CELL), static_cast<float>(i * SIZE_CELL) });
			cell.CellShape.setFillColor(sf::Color::Transparent);
			cell.CellShape.setOutlineColor(sf::Color::White);
			cell.CellShape.setOutlineThickness(2.f);

			grid.push_back(cell);
		}
	}
}

void LevelEditor::Update(float deltaTime)
{
	sf::Vector2i mousePosition = inputModule->getMousePosition(windowModule->getWindow());
	sf::RenderWindow& window = windowModule->getWindow();

	int coordTileX = static_cast<int>(std::floor(window.mapPixelToCoords(mousePosition).x / SIZE_CELL));
	int coordTileY = static_cast<int>(std::floor(window.mapPixelToCoords(mousePosition).y / SIZE_CELL));

	sf::Vector2i mousePositionTile = { coordTileX, coordTileY };

	if (inputModule->isMousePresseds(sf::Mouse::Button::Left))
	{
		GetTileByCoord(mousePositionTile);
	}
}

void LevelEditor::SaveFile(const std::string& filePath)
{
	std::ifstream fichier("Assets/Levels/Level1.txt");  //On ouvre le fichier
	fichier.seekg(0, std::ios::end);  //On se déplace à la fin du fichier

	std::streamoff taille = fichier.tellg();
	//On récupère la position qui correspond donc à la taille du fichier !

	std::cout << "Taille du fichier : " << taille << " octets." << std::endl;

	return;
}

void LevelEditor::LoadFile(const std::string& filePath)
{
	file.open(filePath);
	if (file.is_open())
	{
		// Charge le fichier en question.
	}
	else
	{
		std::cerr << "ERREUR : Fichier introuvable, le repertoire est peut-etre incorrecte.." << std::endl;
		return;
	}
}

sf::Vector2i LevelEditor::GetTileByCoord(sf::Vector2i coords)
{
	if (coords.y >= 0 && coords.x >= 0)
	{
		Cell& cell = grid[coords.y * (MAX_CELL_X + 1) + coords.x];
		cell.CellShape.setFillColor(sf::Color::Blue);

		return cell.cellCoord;
	}
}

void LevelEditor::Render(sf::RenderWindow& window)
{
	for (Cell& cell : grid)
	{
		window.draw(cell.CellShape);
	}
}
