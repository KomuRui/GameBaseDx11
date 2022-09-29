#include "Star.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Star::Star(GameObject* parent)
	: GameObject(parent, "Star"), hPict_(-1)
{
}

//������
void Star::Initialize()
{
	///////////////�摜�f�[�^�̃��[�h///////////////////

	//��
	hPict_ = Image::Load("SplashScene/Image/star.png");
	assert(hPict_ >= 0);


	//0.5-1.5
	transform_.position_.x = ((rand()% 25) - 5.0f) / 10.0f;
	transform_.position_.y = 1.5;


}

//�X�V
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

//�`��
void Star::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Star::Release()
{
}
