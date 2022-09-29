#include "MonthScene.h"
#include "../Player.h"
#include "../Stage.h"
#include "../CreateMeteorite.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Model.h"
#include "../Engine/SceneManager.h"


//コンストラクタ
MonthScene::MonthScene(GameObject* parent)
	: GameObject(parent, "MonthScene"), timeConter_(new Time)
{
}

//初期化
void MonthScene::Initialize()
{
	//初期化
	timeConter_->Initialize();

}

//更新
void MonthScene::Update()
{
	//タイム測定開始テスト
	if (Input::IsKeyDown(DIK_RETURN))
	{
		timeConter_->SetTimeflag(true);
	}
}

//描画
void MonthScene::Draw()
{
	//タイム表示
	timeConter_->TimeDraw(1100, 100);
}

//開放
void MonthScene::Release()
{
}
