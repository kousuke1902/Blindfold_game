#pragma once
#include <Siv3D.hpp>

// マップを構成する最小単位1マスの基本クラス
class MapCell
{

protected:

	bool passage; // 通行フラグ
	String id; // ID

public:

	// コンストラクタ
	MapCell(bool set_passage, String set_id)
	{
		passage = set_passage;
		id = set_id;
	}


	// 描画
	virtual int Draw(Vec2 origin)
	{
		RectF{origin, 50 }.drawFrame();

		return 0;
	}

	// 描画
	virtual int Draw(double x, double y)
	{
		RectF{ x, y, 50 }.drawFrame();

		return 0;
	}

	// マスに居続けた際の処理
	virtual int TurnAction()
	{

		return 0;
	}

	// マスに止まった際の処理
	virtual int StopAction()
	{

		return 0;
	}

};
