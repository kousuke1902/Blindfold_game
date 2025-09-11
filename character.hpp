#pragma once
#include <Siv3D.hpp>
#include "DeltaTimeManager.hpp"

// ゲーム内キャラクターの基本クラス
class Character
{

protected:

	Vec2 graph; // 座標
	int direction; // 向き
	int helth; // 体力
	int deffence; // 防御力
	double move_interval; // 移動間隔
	double attack_interval; // 攻撃間隔
	int live_flag; // 生存フラグ
	String id; // ID
	Array<String> tags; // タグ
	Texture texture; // キャラクター画像

public:



	// 描画
	int Draw()
	{
		texture.drawAt(graph).rotate90(direction);

		return 0;
	}

	// 移動
	int Move(double x, double y)
	{
		graph.moveBy(x, y);

		return 0;
	}

	// 右回転
	int RotateRight()
	{
		if (direction < 4) direction++;
		else if (direction == 4) direction = 0;

		return 0;
	}

	// 左回転
	int RotateLeft()
	{
		if (direction > 0) direction--;
		else if (direction == 0) direction = 4;

		return 0;
	}

	// 

	// 随時処理
	int Update()
	{
		double deltatime = DeltaTimeManager::getInstance().ShowDeltaTime();

		if (move_interval > 0) move_interval -= deltatime;
		if (attack_interval > 0) attack_interval -= deltatime;

		return 0;
	}

};
