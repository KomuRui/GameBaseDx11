#include "CustomizeScene.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Model.h"
#include "../Engine/SceneManager.h"
#include "BackButton.h"

//コンストラクタ
CustomizeScene::CustomizeScene(GameObject* parent)
	: GameObject(parent, "CustomizeScene")
{
	for (int numCounter = 0; numCounter < MAX; numCounter++)
	{
		hPict_[numCounter] = -1;
	}
}

//初期化
void CustomizeScene::Initialize()
{
	Instantiate<BackButton>(this);

	///////////////画像データのロード///////////////////

	hPict_[BackGround] = Image::Load("Image/BackGround.jpg");
	assert(hPict_ >= 0);

	hPict_[CustTable]  = Image::Load("Image/CustmizeTable.png");
	assert(hPict_ >= 0);

	//transform
	CustTable_.position_.y = -0.5;
	CustTable_.scale_.y *= 0.5;
}

//更新
void CustomizeScene::Update()
{
}

//描画
void CustomizeScene::Draw()
{
	for (int numCounter = 0; numCounter < MAX; numCounter++)
	{
		if (numCounter == CustTable)
		{
			Image::SetTransform(hPict_[numCounter], CustTable_);
			Image::Draw(hPict_[numCounter]);
		}
		else
		{
			Image::SetTransform(hPict_[numCounter], transform_);
			Image::Draw(hPict_[numCounter]);
		}
	}
}

//開放
void CustomizeScene::Release()
{
}
