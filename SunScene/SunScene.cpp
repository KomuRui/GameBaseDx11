#include "SunScene.h"
#include "../Player.h"
#include "../Stage.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Model.h"
#include "../Engine/SceneManager.h"


//�R���X�g���N�^
SunScene::SunScene(GameObject* parent)
	: GameObject(parent, "SunScene"), timeConter_(new Time)
{
}

//������
void SunScene::Initialize()
{
	//������
	timeConter_->Initialize();
}

//�X�V
void SunScene::Update()
{
	//�^�C������J�n�e�X�g
	if (Input::IsKeyDown(DIK_RETURN))
	{
		timeConter_->SetTimeflag(true);
	}
}

//�`��
void SunScene::Draw()
{
	//�^�C���\��
	timeConter_->TimeDraw(1100, 100);
}

//�J��
void SunScene::Release()
{
}
