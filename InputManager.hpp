#pragma once
#include <Siv3D.hpp>

// プレイヤーからの入力を制御するクラス
class InputManager
{
private:

	InputManager() = default; // コンストラクタ
	~InputManager() = default; // デストラクタ


public:

	InputManager(const InputManager&) = delete; // コピーコンストラクタを削除
	InputManager& operator = (const InputManager&) = delete; // コピー代入演算子の削除
	InputManager(InputManager&&) = delete; // ムーブコンストラクタの削除
	InputManager& operator = (InputManager&&) = delete; // ムーブ代入演算子の削除

	// インスタンス情報の入手
	static InputManager& getInstance()
	{
		static InputManager inst; // プライベートなコンストラクタ
		return inst;
	}

	// 移動入力
	Vec2 VectorInput()
	{
		// XInputコントローラーの情報
		auto controller = XInput(0);

		// コントローラー入力
		Vec2 GamePadThumbInput(controller.leftThumbX, -controller.leftThumbY);
		Vec2 GamePadPovInput(controller.buttonRight.pressed() - controller.buttonLeft.pressed(), controller.buttonDown.pressed() - controller.buttonUp.pressed());

		//スティックの個体差やわずかなブレで動くのを塞ぐ為に小さい値をカットする
		//切り捨てる以上であればゲームパッドのインプットを優先する
		if (GamePadThumbInput.length() >= 0.05)return GamePadThumbInput;
		else if (GamePadPovInput.length() > 0.0) return GamePadPovInput.setLength(1.0);
		else return Vec2(KeyD.pressed() - KeyA.pressed(), KeyS.pressed() - KeyW.pressed()).setLength(1.0);

	}

};
