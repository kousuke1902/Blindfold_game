#pragma once
#include <Siv3D.hpp>

class BulletManager
{

private:

	BulletManager() = default; // コンストラクタ
	~BulletManager() = default; // デストラクタ

public:

	BulletManager(const BulletManager&) = delete; // コピーコンストラクタを削除
	BulletManager& operator = (const BulletManager&) = delete; // コピー代入演算子の削除
	BulletManager(BulletManager&&) = delete; // ムーブコンストラクタの削除
	BulletManager& operator = (BulletManager&&) = delete; // ムーブ代入演算子の削除

	// インスタンス情報の入手
	static BulletManager& getInstance()
	{
		static BulletManager inst; // プライベートなコンストラクタ
		return inst;
	}

};
