#pragma once
#include <Siv3D.hpp>

class CharacterManager
{
private:

	CharacterManager() = default; // コンストラクタ
	~CharacterManager() = default; // デストラクタ

public:

	CharacterManager(const CharacterManager&) = delete; // コピーコンストラクタを削除
	CharacterManager& operator = (const CharacterManager&) = delete; // コピー代入演算子の削除
	CharacterManager(CharacterManager&&) = delete; // ムーブコンストラクタの削除
	CharacterManager& operator = (CharacterManager&&) = delete; // ムーブ代入演算子の削除

	// インスタンス情報の入手
	static CharacterManager& getInstance()
	{
		static CharacterManager inst; // プライベートなコンストラクタ
		return inst;
	}

};
