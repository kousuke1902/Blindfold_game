#pragma once
#include <Siv3D.hpp>
#include "DeltaTimeManager.hpp"

// ゲーム内キャラクターの基本クラス
class Character
{

protected:

	Point pos; // 盤上座標
	int direction; // 向き
	int health; // 体力
	int deffence; // 防御力
	double move_interval; // 移動間隔
	double move_timer; // 移動時間測定
	double attack_interval; // 攻撃間隔
	double attack_timer; // 攻撃時間測定
	int live_flag; // 生存フラグ
	String id; // ID
	Array<String> tags; // タグ
	Texture texture; // キャラクター画像

public:



	// 描画
	int Draw(Vec2 origin)
	{
		// 実際の描画は盤上の位置によってでずれる
		texture.drawAt(origin + pos).rotate90(direction);

		return 0;
	}

	// 移動
	int Move(int x, int y)
	{
		// 移動が可能な場合のみ
		if (move_timer <= 0)
		{
			pos.moveBy(x, y);
			move_timer = move_interval;
		}

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

	// 攻撃
	virtual int Attack()
	{

		return 0;
	}

	// 体力計算
	int Damage(int x)
	{
		// 防御力の分，ダメージは減る
		int damage = deffence - x;

		// ダメージが0未満になることはない
		if (damage < 0)damage = 0;

		health -= damage;

		// 体力が0以下になると活動できない
		if (health <= 0)live_flag = 0;

		return 0;
	}


	// 随時処理
	int Update()
	{
		double deltatime = DeltaTimeManager::getInstance().ShowDeltaTime();

		if (move_timer > 0) move_timer -= deltatime;
		if (attack_timer > 0) attack_timer -= deltatime;

		return 0;
	}

};
