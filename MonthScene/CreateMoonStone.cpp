#include "CreateMoonStone.h"
//�R���X�g���N�^
   //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
CreateMoonStone::CreateMoonStone(GameObject* parent)
	:GameObject(parent, "CreateMoonStone"),
	pMoon_()
{

}

//�f�X�g���N�^
CreateMoonStone::~CreateMoonStone()
{

}

//������
void CreateMoonStone::Initialize()
{
	pMoon_[0] = Instantiate<MoonStone>(GetParent());
	pMoon_[0]->SetMoonStone("EarthScene/Model/MoonStone.fbx", -240, 3, 2);

	pMoon_[1] = Instantiate<MoonStone>(GetParent());
	pMoon_[1]->SetMoonStone("EarthScene/Model/MoonStone.fbx", -240, 4, 4);

	pMoon_[2] = Instantiate<MoonStone>(GetParent());
	pMoon_[2]->SetMoonStone("EarthScene/Model/MoonStone.fbx", -240, 5, 6);

}

//�X�V
void CreateMoonStone::Update()
{

}

//�`��
void CreateMoonStone::Draw()
{

}

//�J��
void CreateMoonStone::Release()
{
}