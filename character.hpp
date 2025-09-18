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
	double move_timer; // 経過移動間隔
	double attack_interval; // 攻撃間隔
	double attack_timer; // 経過攻撃間隔
	int live_flag; // 生存フラグ
	String id; // ID
	Array<String> tags; // タグ
	Texture texture; // キャラクター画像

public:


	Character()
	{
		pos = Point(0, 0);
		direction = 0;
		health = 10;
		deffence = 1;
		move_interval = 0.5;
		move_timer = 0.0;
		attack_interval = 1.0;
		attack_timer = 0.0;
		live_flag = 1;
		id = U"test";
		tags << U"test";


	}


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

	// 座標確認
	Point ShowPos()
	{
		return pos;
	}

	// 向き確認(数字)
	int ShowDirection()
	{
		return direction;
	}

	// 体力確認
	int ShowHealth()
	{
		return health;
	}

	// 防御確認
	int ShowDeffence()
	{
		return deffence;
	}

	// 移動間隔確認
	double ShowMoveInterval()
	{
		return move_interval;
	}

	// 経過移動間隔確認
	double ShowMoveTimer()
	{
		return move_timer;
	}

	// 攻撃間隔確認
	double ShowAttackInterval()
	{
		return attack_interval;
	}

	// 経過攻撃間隔確認
	double ShowAttackTimer()
	{
		return attack_timer;
	}

	// 生存フラグ確認
	int ShowLiveFlag()
	{
		return live_flag;
	}

	// ID確認
	String ShowID()
	{
		return id;
	}

	// タグ確認
	Array<String> ShowTags()
	{
		return tags;
	}

};
