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

//�R���X�g���N�^
EarthScene::EarthScene(GameObject* parent)
	: GameObject(parent, "EarthScene"),hModel_(-1), pSceneManager((SceneManager*)FindObject("SceneManager")), haikeiflag_(false)
{
}

//������
void EarthScene::Initialize()
{

	///////////////�摜�f�[�^�̃��[�h///////////////////

	//�^�C�g��
	hPict_[haikei] = Image::Load("EarthScene/Image/haikei.jpg");
	assert(hPict_[haikei] >= 0);

	hPict_[haikei2] = Image::Load("EarthScene/Image/haikei2.jpg");
	assert(hPict_[haikei2] >= 0);

	hPict_[Maphaikei] = Image::Load("EarthScene/Image/s.jpg");
	assert(hPict_[Maphaikei] >= 0);

	//Player�̏�����
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

	////////////////Imgui�̕\��///////////////

	Instantiate<ImGuiSet>(this);

	Direct3D::CameraSet(true);

}

//�X�V
void EarthScene::Update()
{
	//�^�C������J�n�e�X�g
	/*if (Input::IsKeyDown(DIK_RETURN))
	{
		timeConter_->SetTimeflag(true);
	}*/
}

//�`��
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

//�J��
void EarthScene::Release()
{
}
