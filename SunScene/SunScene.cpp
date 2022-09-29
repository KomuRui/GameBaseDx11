#include "SunScene.h"
#include "../Player.h"
#include "../Stage.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Model.h"
#include "../Engine/SceneManager.h"


//コンストラクタ
SunScene::SunScene(GameObject* parent)
	: GameObject(parent, "SunScene"), timeConter_(new Time)
{
}

//初期化
void SunScene::Initialize()
{
	//初期化
	timeConter_->Initialize();
}

//更新
void SunScene::Update()
{
	//タイム測定開始テスト
	if (Input::IsKeyDown(DIK_RETURN))
	{
		timeConter_->SetTimeflag(true);
	}
}

//描画
void SunScene::Draw()
{
	//タイム表示
	timeConter_->TimeDraw(1100, 100);
}

//開放
void SunScene::Release()
{
}
