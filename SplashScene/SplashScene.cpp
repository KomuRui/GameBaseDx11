#include "SplashScene.h"
#include "../Engine/Image.h"
#include "../Engine/Model.h"
#include "../Engine/Input.h"
#include "../Engine/SceneManager.h"
#include "../Star.h"

//�R���X�g���N�^
SplashScene::SplashScene(GameObject* parent)
	: GameObject(parent, "SplashScene"), status_(0), pfade_(new Fade), count_(0)
{
	for (int numCounter = 0; numCounter < MAX_SIZE; numCounter++)
	{
		hPict_[numCounter] = -1;
	}
}

//������
void SplashScene::Initialize()
{
	///////////////�摜�f�[�^�̃��[�h///////////////////

	//���k�d�q�̃��S
	hPict_[TOUHOKU] = Image::Load("SplashScene/Image/TOUTYANN.png");
	assert(hPict_[TOUHOKU] >= 0);

	//�`�[�����S
	hPict_[TEAM] = Image::Load("SplashScene/Image/Rogo.png");
	assert(hPict_[TEAM] >= 0);

	////////////////�摜�̃A���t�@��0�ɐݒ�///////////////

	Image::SetAlpha(hPict_[TOUHOKU], 0);  //���k�d�q
	Image::SetAlpha(hPict_[TEAM], 0);     //�`�[��

	
}

//�X�V
void SplashScene::Update()
{
	//Enter����������X�e�[�^�X���₷
	if (Input::IsKeyDown(DIK_RETURN))
		status_++;

	//A�{�^������������X�e�[�^�X���₷
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
		status_++;

	//�X�e�[�^�X��1�ȉ��Ȃ�,count��20�b�ȏ�Ȃ�����
	if (count_ >= 20 && status_ <= 1)
	{
		Instantiate<Star>(this); //star�\��
		count_ = 0;               //count0�ɂ���
	}

	//�X�e�[�^�X�̒l�ł�邱�ƕς���
	switch (status_)
	{
	case 1:
		pfade_->FadeIn(hPict_[TOUHOKU], FADE_TIME);
		break;
	case 2:
		pfade_->FadeOut(hPict_[TOUHOKU], FADE_TIME);
		break;
	case 3:
		pfade_->FadeIn(hPict_[TEAM], FADE_TIME);
		break;
	case 4:
		pfade_->FadeOut(hPict_[TEAM], FADE_TIME);
		break;
	case 5:
		SceneManager * pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
		break;
	}

	//�C���N�������g
	count_++;
}

//�`��
void SplashScene::Draw()
{

	if (status_ <= 2)
	{
		Image::SetTransform(hPict_[TOUHOKU], transform_);
		Image::Draw(hPict_[TOUHOKU]);
	}
	else
	{
		Image::SetTransform(hPict_[TEAM], transform_);
		Image::Draw(hPict_[TEAM]);
	}


}

//�J��
void SplashScene::Release()
{
}