#pragma once
#include <Siv3D.hpp>

// 各場面
enum class State
{
	Title,
	StageSelect,
	GamePlay,
	Result,

};

// 共有情報
struct GameData
{

	String stage_name;

};

using App = SceneManager<State, GameData>;
