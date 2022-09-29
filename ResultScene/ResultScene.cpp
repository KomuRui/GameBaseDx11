#include "ResultScene.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Model.h"
#include "../Engine/SceneManager.h"


//コンストラクタ
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"), hPict_(-1)
{
}

//初期化
void ResultScene::Initialize()
{
	///////////////画像データのロード///////////////////

	//タイトル
	hPict_ = Image::Load("Image/BackGround.jpg");
	assert(hPict_ >= 0);
}

//更新
void ResultScene::Update()
{
}

//描画
void ResultScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void ResultScene::Release()
{
}
