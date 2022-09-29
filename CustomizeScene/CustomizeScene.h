#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Time.h"

//■■シーンを管理するクラス
class CustomizeScene : public GameObject
{
	enum TitleImages
	{
		BackGround = 0,
		CustTable,
		MAX
	};

	int hPict_[MAX];    //画像番号

	Transform CustTable_;	//CustTable画像のトランスフォーム

public:

	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	CustomizeScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

