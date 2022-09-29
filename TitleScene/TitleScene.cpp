#include "TitleScene.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/SceneManager.h"
#include "../Player.h"
#include "../EarthScene/EarthScene.h"

//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"),pfade_(new Fade),time_(0)
{
	for (int numCounter = 0; numCounter < MAX_SIZE_TITLEIMAGE; numCounter++)
	{
		hPict_[numCounter] = -1;
	}
}

//������
void TitleScene::Initialize()
{

	///////////////�摜�f�[�^�̃��[�h///////////////////

	//�^�C�g��
	hPict_[TITLE] = Image::Load("TitleScene/Image/Title.png");
	assert(hPict_ >= 0);

	//�X�^�[�g
	hPict_[START] = Image::Load("TitleScene/Image/start.png");
	assert(hPict_ >= 0);

	///////////////transform///////////////////

	//position
	start_.position_.y -= 0.1;

	//scale
	start_.scale_.x *= 2.0f;
	start_.scale_.y *= 2.0f;
}

//�X�V
void TitleScene::Update()
{
	static bool flag = false;

	//�t�F�[�h�C���ƃt�F�[�h�A�E�g���J��Ԃ�
	pfade_->FadeInOut(hPict_[START], FADE_TIME);

	//A�{�^������������Play�V�[���ֈڍs
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_EARTH);
	}

	//Pad���Ȃ��Ƃ��Ɉڍs����p
	if (Input::IsKeyDown(DIK_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		//pSceneManager->ChangeScene(SCENE_ID_EARTH);
		pSceneManager->ChangeScene(SCENE_ID_HOME);
	}

	if (time_ >= 6000)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_EARTH);
		pSceneManager->SetPlayVideo(true);

		flag = true;
		time_ = 0;
	}

	if(!flag)
	time_++;
}

//�`��
void TitleScene::Draw()
{
	//IMAGE�摜�̕��`�悷��
	for (int numCounter = 0; numCounter < MAX_SIZE_TITLEIMAGE; numCounter++)
	{
		if (numCounter == START)
		{
			Image::SetTransform(hPict_[numCounter], start_);
			Image::Draw(hPict_[numCounter]);
		}
		else
		{
			Image::SetTransform(hPict_[numCounter], transform_);
			Image::Draw(hPict_[numCounter]);
		}
	}
}

//�J��
void TitleScene::Release()
{
}
