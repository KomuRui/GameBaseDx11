#include "SplashScene.h"
#include "../Engine/Image.h"
#include "../Engine/Model.h"
#include "../Engine/Input.h"
#include "../Engine/SceneManager.h"
#include "../Star.h"

//コンストラクタ
SplashScene::SplashScene(GameObject* parent)
	: GameObject(parent, "SplashScene"), status_(0), pfade_(new Fade), count_(0)
{
	for (int numCounter = 0; numCounter < MAX_SIZE; numCounter++)
	{
		hPict_[numCounter] = -1;
	}
}

//初期化
void SplashScene::Initialize()
{
	///////////////画像データのロード///////////////////

	//東北電子のロゴ
	hPict_[TOUHOKU] = Image::Load("SplashScene/Image/TOUTYANN.png");
	assert(hPict_[TOUHOKU] >= 0);

	//チームロゴ
	hPict_[TEAM] = Image::Load("SplashScene/Image/Rogo.png");
	assert(hPict_[TEAM] >= 0);

	////////////////画像のアルファを0に設定///////////////

	Image::SetAlpha(hPict_[TOUHOKU], 0);  //東北電子
	Image::SetAlpha(hPict_[TEAM], 0);     //チーム

	
}

//更新
void SplashScene::Update()
{
	//Enterを押したらステータス増やす
	if (Input::IsKeyDown(DIK_RETURN))
		status_++;

	//Aボタンを押したらステータス増やす
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
		status_++;

	//ステータスが1以下なら,countが20秒以上なったら
	if (count_ >= 20 && status_ <= 1)
	{
		Instantiate<Star>(this); //star表示
		count_ = 0;               //count0にする
	}

	//ステータスの値でやること変える
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

	//インクリメント
	count_++;
}

//描画
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

//開放
void SplashScene::Release()
{
}