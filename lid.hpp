#pragma once
#include "character.hpp"

class Lid : public Character
{

private:

	int Attack() override
	{


		return 0;
	}

public:

	// コンストラクタ
	Lid(Point set_pos, int set_direction)
	{
		pos = set_pos;
		direction = set_direction;
		health = 10;
		deffence = 1;
		move_interval = 0.5;
		move_timer = 0.0;
		attack_interval = 1.0;
		attack_timer = 0.0;
		live_flag = 1;
		id = U"Lid";
		tags << U"Player";
		texture = Texture(U"img/test.png");

	}

	// 判断処理
	int Action() override
	{
		Update();

		if (KeyE.down()) RotateRight();
		else if (KeyQ.down()) RotateLeft();

		if (KeyW.down()) Move(0, -1);
		else if (KeyS.down()) Move(0, 1);
		else if (KeyA.down()) Move(-1, 0);
		else if (KeyD.down()) Move(1, 0);

		return 0;
	}

};
