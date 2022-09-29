#include "Star.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

//コンストラクタ
Star::Star(GameObject* parent)
	: GameObject(parent, "Star"), hPict_(-1)
{
}

//初期化
void Star::Initialize()
{
	///////////////画像データのロード///////////////////

	//星
	hPict_ = Image::Load("SplashScene/Image/star.png");
	assert(hPict_ >= 0);


	//0.5-1.5
	transform_.position_.x = ((rand()% 25) - 5.0f) / 10.0f;
	transform_.position_.y = 1.5;


}

//更新
void Star::Update()
{
	transform_.rotate_.y += 10;
	transform_.position_.x -= 0.01;
	transform_.position_.y -= 0.01;

	if (transform_.position_.y < -1)
	{
		KillMe();
	}
}

//描画
void Star::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void Star::Release()
{
}
