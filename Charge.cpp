#include "Charge.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
//コンストラクタ
Charge::Charge(GameObject* parent)
	: GameObject(parent, "Charge"), time(0), Count(-1)
{
}

//初期化
void Charge::Initialize()
{
	///////////////画像データのロード///////////////////

	hPict_[ChargeGage] = Image::Load("Image/ChargeGage.png");
	assert(hPict_[ChargeGage] >= 0);

	hPict_[ChargeOriginal] = Image::Load("Image/ChargeOriginal.png");
	assert(hPict_[ChargeOriginal] >= 0);

	hPict_[ChargeMax] = Image::Load("Image/ChargeMax.png");
	assert(hPict_[ChargeMax] >= 0);

	tra_[ChargeOriginal].position_.x =  0.8;
	tra_[ChargeOriginal].position_.y = -0.2;
	tra_[ChargeOriginal].scale_.y    =  1.5;

	tra_[ChargeGage].position_.x = 0.8;
	tra_[ChargeGage].position_.y = -0.8;
	tra_[ChargeGage].scale_.y = 1.5;
	tra_[ChargeGage].scale_.x = 0.9;

	tra_[ChargeMax].position_.x = 0.8;
	tra_[ChargeMax].position_.y = -0.2;
	tra_[ChargeMax].scale_.y = 1.48;
	tra_[ChargeMax].scale_.x = 0.9;

}

//更新
void Charge::Update()
{
	if (time >= 180)
	{
		if(Count < 8)
		Count++;

		time = 0;
	}

	time++;
}

//描画
void Charge::Draw()
{
	if (Direct3D::GetStatus() == 0)
	{
		Image::SetTransform(hPict_[ChargeOriginal], tra_[ChargeOriginal]);
		Image::Draw(hPict_[ChargeOriginal]);

		for (int i = 0; i <= Count; i++)
		{
			tra_[ChargeGage].position_.y = -0.8 + (0.15 * i);
			Image::SetTransform(hPict_[ChargeGage], tra_[ChargeGage]);
			Image::Draw(hPict_[ChargeGage]);
		}

		if (Count >= 8)
		{
			Image::SetTransform(hPict_[ChargeMax], tra_[ChargeMax]);
			Image::Draw(hPict_[ChargeMax]);
		}
	}
}

//開放
void Charge::Release()
{
}