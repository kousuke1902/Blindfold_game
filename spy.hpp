#pragma once
#include "character.hpp"

// スパイ駒
class Spy : public Character
{

private:


public:

	// コンストラクタ
	Spy()
	{


	}

	// デストラクタ
	~Spy(){}

	// 判断処理
	int Action() override
	{
		// キー移動
		Move(KeyS.pressed() - KeyW.pressed(), KeyD.pressed() - KeyA.pressed());

		return 0;
	}

};
