#pragma once
#include <Siv3D.hpp>
#include "DeltaTimeManager.hpp"

// ゲーム内キャラクターの基本クラス
class Character
{

protected:

	Vec2 pos; // 座標
	int direction; // 向き
	double speed; // 移動速度
	int health; // 体力
	int deffence; // 防御力
	double attack_interval; // 攻撃間隔
	double attack_timer; // 経過攻撃間隔
	int live_flag; // 生存フラグ
	bool open_flag; // 名前開示フラグ
	String name; // 名前
	String id; // ID
	Texture texture; // キャラクター画像
	Array<String> tags; // タグ
	Array<RectF> hitbox; // 当たり判定
	double deltatime = DeltaTimeManager::getInstance().ShowDeltaTime(); // 差分時間

	// 移動
	int Move(double x, double y)
	{
		pos.moveBy(x * speed * deltatime, y * speed * deltatime);

		return 0;
	}

	// 移動
	int Move(Vec2 vector)
	{
		pos.moveBy(vector * speed * deltatime);

		return 0;
	}

	// 右回転
	int RotateRight()
	{
		if (direction < 3)	direction++;
		else if (direction == 3) direction = 0;
		return 0;
	}

	// 左回転
	int RotateLeft()
	{
		if (direction > 0)	direction--;
		else if (direction == 0) direction = 3;

		return 0;
	}

	// 攻撃
	virtual int Attack()
	{

		return 0;
	}

	// 時間処理
	int TimeProcessing()
	{
		if (attack_timer > 0) attack_timer -= deltatime;

		return 0;
	}

	// 判断処理
	virtual int Action()
	{

		return 0;
	}


public:

	// コンストラクタ
	Character()
	{
		pos = Vec2 (0.0, 0.0);
		speed = 100.0;
		direction = 0;
		health = 10;
		deffence = 1;
		attack_interval = 1.0;
		attack_timer = 0.0;
		live_flag = 1;
		open_flag = false;
		name = U"TEST";
		id = U"test";
		tags << U"test";
		texture = Texture(U"img/test.png");


	}

	// 描画
	int Draw(Vec2 origin)
	{
		// 描画はステージ位置と合わせる
	//	texture.rotated(direction * 90_deg).drawAt(origin + pos);
	//	texture.rotated(direction * 90_deg).drawAt(pos);
		

		return 0;
	}

	// 描画
	int Draw(double x, double y)
	{
		// 描画はステージ位置と合わせる
	//	texture.rotated(direction * 90_deg).drawAt(x + pos.x, y + pos.y);
	//	texture.rotated(direction * 90_deg).drawAt(pos);


		return 0;
	}

	// 随時処理
	int Update()
	{
		TimeProcessing();
		Action();

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

	// 座標確認
	Vec2 ShowPos() const
	{
		return pos;
	}

	// 向き確認(数字)
	int ShowDirection() const
	{
		return direction;
	}

	// 移動速度確認
	double ShowSpeed() const
	{
		return speed;
	}

	// 体力確認
	int ShowHealth() const
	{
		return health;
	}

	// 防御確認
	int ShowDeffence() const
	{
		return deffence;
	}

	// 攻撃間隔確認
	double ShowAttackInterval() const
	{
		return attack_interval;
	}

	// 経過攻撃間隔確認
	double ShowAttackTimer() const
	{
		return attack_timer;
	}

	// 生存フラグ確認
	int ShowLiveFlag() const
	{
		return live_flag;
	}

	// 名前開示フラグ確認
	bool ShowOpenFlag() const
	{
		return open_flag;
	}

	// ID確認
	String ShowID() const
	{
		return id;
	}

	// タグ確認
	Array<String> ShowTags() const
	{
		return tags;
	}

};
