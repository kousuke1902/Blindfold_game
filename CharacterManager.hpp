#pragma once
#include "IngameCharacter.hpp"


// 全てのキャラクターの管理クラス
class CharacterManager
{
private:

	CharacterManager() = default; // コンストラクタ
	~CharacterManager() = default; // デストラクタ

	Array<Character*> characters;

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

	// キャラクター追加
	int AddCharacter(Character* add_character)
	{
		characters << add_character;

		return 0;
	}

	// 随時処理
	int Update()
	{
		// 機能している全てのキャラクター
		for (auto it = characters.begin(); it != characters.end();)
		{
			Character* character = *it;

			// 生存状態の確認
			if (character->ShowLiveFlag() == -1)
			{
				// 削除処理
				delete character;
				it = characters.erase(it);

			}

			else
			{
				// 生存していれば活動
				character->Update();

			}

			++it;

		}

	}

	// 描画
	int Draw(Vec2 origin)
	{
		// 機能している全てのキャラクター
		for (auto it = characters.begin(); it != characters.end();)
		{
			Character* character = *it;

			character->Draw(origin);

			++it;

		}

	}


};
