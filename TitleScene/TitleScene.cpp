#include "TitleScene.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/SceneManager.h"
#include "../Player.h"
#include "../EarthScene/EarthScene.h"

//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"),pfade_(new Fade),time_(0)
{
	for (int numCounter = 0; numCounter < MAX_SIZE_TITLEIMAGE; numCounter++)
	{
		hPict_[numCounter] = -1;
	}
}

//初期化
void TitleScene::Initialize()
{

	///////////////画像データのロード///////////////////

	//タイトル
	hPict_[TITLE] = Image::Load("TitleScene/Image/Title.png");
	assert(hPict_ >= 0);

	//スタート
	hPict_[START] = Image::Load("TitleScene/Image/start.png");
	assert(hPict_ >= 0);

	///////////////transform///////////////////

	//position
	start_.position_.y -= 0.1;

	//scale
	start_.scale_.x *= 2.0f;
	start_.scale_.y *= 2.0f;
}

//更新
void TitleScene::Update()
{
	static bool flag = false;

	//フェードインとフェードアウトを繰り返す
	pfade_->FadeInOut(hPict_[START], FADE_TIME);

	//Aボタンを押したらPlayシーンへ移行
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_EARTH);
	}

	//Padがないときに移行する用
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

//描画
void TitleScene::Draw()
{
	//IMAGE画像の分描画する
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

//開放
void TitleScene::Release()
{
}
