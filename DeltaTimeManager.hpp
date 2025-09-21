#pragma once
#include <Siv3D.hpp>

// ゲーム全体の差分時間
class DeltaTimeManager
{

private:

	DeltaTimeManager() = default; // コンストラクタ
	~DeltaTimeManager() = default; // デストラクタ

	double deltatime; // 差分時間

public:

	DeltaTimeManager(const DeltaTimeManager&) = delete; // コピーコンストラクタを削除
	DeltaTimeManager& operator = (const DeltaTimeManager&) = delete; // コピー代入演算子の削除
	DeltaTimeManager(DeltaTimeManager&&) = delete; // ムーブコンストラクタの削除
	DeltaTimeManager& operator = (DeltaTimeManager&&) = delete; // ムーブ代入演算子の削除

	// インスタンス情報の入手
	static DeltaTimeManager& getInstance()
	{
		static DeltaTimeManager inst; // プライベートなコンストラクタ
		return inst;
	}

	// 1フレーム間の差分時間の測定
	int GetDeltaTime()
	{
		deltatime = Scene::DeltaTime();

		return 0;
	}

	// 1フレーム間の差分時間参照
	double ShowDeltaTime() const
	{
		return deltatime;
	}

};
