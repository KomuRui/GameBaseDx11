#include "MonthScene.h"
#include "../Player.h"
#include "../Stage.h"
#include "../CreateMeteorite.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Model.h"
#include "../Engine/SceneManager.h"


//�R���X�g���N�^
MonthScene::MonthScene(GameObject* parent)
	: GameObject(parent, "MonthScene"), timeConter_(new Time)
{
}

//������
void MonthScene::Initialize()
{
	//������
	timeConter_->Initialize();

}

//�X�V
void MonthScene::Update()
{
	//�^�C������J�n�e�X�g
	if (Input::IsKeyDown(DIK_RETURN))
	{
		timeConter_->SetTimeflag(true);
	}
}

//�`��
void MonthScene::Draw()
{
	//�^�C���\��
	timeConter_->TimeDraw(1100, 100);
}

//�J��
void MonthScene::Release()
{
}
