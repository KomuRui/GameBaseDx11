#include "EarthScene.h"
#include "../Player.h"
#include "../Stage.h"
#include "../CreateMeteorite.h"
#include "../SunScene/CreateFirePillar.h"
#include "../MonthScene/CreateMoonStone.h"
#include"../CreateBill.h"
#include"../CreateHole.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Model.h"
#include "../Engine/ImGuiSet.h"
#include "../Charge.h"

//コンストラクタ
EarthScene::EarthScene(GameObject* parent)
	: GameObject(parent, "EarthScene"),hModel_(-1), pSceneManager((SceneManager*)FindObject("SceneManager")), haikeiflag_(false)
{
}

//初期化
void EarthScene::Initialize()
{

	///////////////画像データのロード///////////////////

	//タイトル
	hPict_[haikei] = Image::Load("EarthScene/Image/haikei.jpg");
	assert(hPict_[haikei] >= 0);

	hPict_[haikei2] = Image::Load("EarthScene/Image/haikei2.jpg");
	assert(hPict_[haikei2] >= 0);

	hPict_[Maphaikei] = Image::Load("EarthScene/Image/s.jpg");
	assert(hPict_[Maphaikei] >= 0);

	//Playerの初期化
	Instantiate<Player>(this);
	Instantiate<CreateMeteorite>(this);
	Instantiate<CreateBill>(this);
	Instantiate<CreateHole>(this);
	Instantiate<Stage>(this);
	Instantiate<Charge>(this);
	


	//Instantiate<CreateMoonStone>(this);
	//Instantiate<CreateFirePillar>(this);

	if (pSceneManager->GetPlayVideo())
	{
		Player* pPlayer = (Player*)FindObject("Player");
		pPlayer->SetStatus(1);
	}

	////////////////Imguiの表示///////////////

	Instantiate<ImGuiSet>(this);

	Direct3D::CameraSet(true);

}

//更新
void EarthScene::Update()
{
	//タイム測定開始テスト
	/*if (Input::IsKeyDown(DIK_RETURN))
	{
		timeConter_->SetTimeflag(true);
	}*/
}

//描画
void EarthScene::Draw()
{
	if (Direct3D::GetStatus() == 0)
	{
		if (!haikeiflag_)
		{
			/*Image::SetTransform(hPict_[haikei], transform_);
			Image::Draw(hPict_[haikei]);*/
		}
		else
		{
			Image::SetTransform(hPict_[haikei2], transform_);
			Image::Draw(hPict_[haikei2]);
		}
	}
	else if (Direct3D::GetStatus() == 1)
	{
		Image::SetTransform(hPict_[Maphaikei], transform_);
		Image::Draw(hPict_[Maphaikei]);
	}
}

//開放
void EarthScene::Release()
{
}
