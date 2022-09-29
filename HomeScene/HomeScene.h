#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Time.h"
#include "../Button.h"
//■■シーンを管理するクラス
class HomeScene : public GameObject
{
	int hPict_;    //画像番号

	int nowType;   //今どこのボタンを見ているか

	enum ButtonType
	{
		Solo,
		Duo,
		Tutorial,
		MAX
	};

	Button* pbutton[MAX];
public:

	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	HomeScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

