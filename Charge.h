#pragma once
#include "Engine/GameObject.h"


//■■シーンを管理するクラス
class Charge : public GameObject
{
	enum ImagePicture
	{
		ChargeGage,
		ChargeMax,
		ChargeOriginal,
		SIZE_MAX_IMAGEPICTURE
	};

	//画像番号
	int hPict_[SIZE_MAX_IMAGEPICTURE];

	//画像ごとのトランスフォーム
	Transform tra_[SIZE_MAX_IMAGEPICTURE];

    //時間を計る
	int time;

	//ChargeGageの個数
	int Count;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Charge(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//チャージのカウントを返す
	int GetCount() { return Count; }

	//チャージのカウントをset
	void SetCount(int count) { Count = count; }
};