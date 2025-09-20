#include <Siv3D.hpp> // Siv3D v0.6.16
#include "DeltaTimeManager.hpp"
#include "lid.hpp"

void Main()
{
	// 背景の色設定
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	DeltaTimeManager& deltatime = DeltaTimeManager::getInstance();

	Lid lid(Point(0, 0), 1);

	while (System::Update())
	{

		deltatime.GetDeltaTime();

		lid.Draw(400.0, 300.0);
		lid.Action();

	}
}
