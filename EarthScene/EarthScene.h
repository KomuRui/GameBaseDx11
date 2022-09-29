#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Time.h"
#include "../Engine/SceneManager.h"

//■■シーンを管理するクラス
class EarthScene : public GameObject
{
	enum ImagePicture
	{
		haikei,
		haikei2,
		Maphaikei,
		SIZE_MAX_IMAGEPICTURE
	};

	SceneManager* pSceneManager;

	//モデル番号
	int hModel_;

	//画像番号
	int hPict_[SIZE_MAX_IMAGEPICTURE];

	//背景flag
	bool haikeiflag_;

public:

	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	EarthScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//セット背景
	void Sethaikei() { haikeiflag_ = !haikeiflag_; }
};

