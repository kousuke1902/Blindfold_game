#pragma once
#include <Siv3D.hpp>

class MapManager
{
private:

	MapManager() = default; // コンストラクタ
	~MapManager() = default; // デストラクタ

public:

	MapManager(const MapManager&) = delete; // コピーコンストラクタを削除
	MapManager& operator = (const MapManager&) = delete; // コピー代入演算子の削除
	MapManager(MapManager&&) = delete; // ムーブコンストラクタの削除
	MapManager& operator = (MapManager&&) = delete; // ムーブ代入演算子の削除

	// インスタンス情報の入手
	static MapManager& getInstance()
	{
		static MapManager inst; // プライベートなコンストラクタ
		return inst;
	}

};
