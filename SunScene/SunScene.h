#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Time.h"

//■■シーンを管理するクラス
class SunScene : public GameObject
{
	//タイムの表示
	Time* timeConter_;

public:

	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	SunScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

