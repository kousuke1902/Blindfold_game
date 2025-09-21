#include <Siv3D.hpp> // Siv3D v0.6.16
#include "DeltaTimeManager.hpp"
#include "map_cell.hpp"

void Main()
{
	// 背景の色設定
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	DeltaTimeManager& deltatime = DeltaTimeManager::getInstance();


	while (System::Update())
	{

		deltatime.GetDeltaTime();

	
	}
}
