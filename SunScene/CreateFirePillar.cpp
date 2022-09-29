#include "CreateFirePillar.h"
#include"../Engine/Global.h"
//�R���X�g���N�^
  //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
CreateFirePillar::CreateFirePillar(GameObject* parent)
	:GameObject(parent,"CreateFirePillar"),pFire_()
{

}

//�f�X�g���N�^
CreateFirePillar::~CreateFirePillar()
{

}

//������
void CreateFirePillar::Initialize()
{
	pFire_[0] = Instantiate<FirePillar>(GetParent());
	pFire_[0]->SetFirePillar("EarthScene/Model/FirePillar.fbx", XMFLOAT3(-240, 5, 5),XMFLOAT3(90,0,0));

	pFire_[1] = Instantiate<FirePillar>(GetParent());
	pFire_[0]->SetFirePillar("EarthScene/Model/FirePillar.fbx", -240, 3, 1);

	pFire_[2] = Instantiate<FirePillar>(GetParent());
	pFire_[0]->SetFirePillar("EarthScene/Model/FirePillar.fbx", -240, 4, 6);
}

//�X�V
void CreateFirePillar::Update()
{

}

//�`��
void CreateFirePillar::Draw()
{

}

//�J��
void CreateFirePillar::Release()
{
}