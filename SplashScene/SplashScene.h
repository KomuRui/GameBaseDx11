#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Fade.h"


//■■シーンを管理するクラス
class SplashScene : public GameObject
{
	//SplashSceneに表示する画像
	enum Images
	{
		TOUHOKU = 0,
		TEAM,
		MAX_SIZE
	};

	int hPict_[MAX_SIZE];			 //画像番号
	int status_;					 //ステータス
	int count_;						 //星が出る速さ
	const float FADE_TIME = 3.0f;	 //スプラッシュのフェードする時間

	Fade* pfade_;					 //フェードするのに必要なクラス

public:

	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	SplashScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

