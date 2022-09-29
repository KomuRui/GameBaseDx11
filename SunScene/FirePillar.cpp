#include "FirePillar.h"
#include"../Engine/Model.h"
#include"../Engine/BoxCollider.h"

//�R���X�g���N�^
   //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
FirePillar::FirePillar(GameObject* parent)
	:GameObject(parent,"FirePillar"),
	hModel_(-1),
	modelNamePath_(""),
	eruption_(0),
	//////////���o���x�ݒ�////////
	ERUPTION_SPEED(0.05f),
	//////////���o�T�C�Y�ݒ�
	PILLAR_SIZE(5.0f)
{

}

//�f�X�g���N�^
FirePillar::~FirePillar()
{

}

//������
void FirePillar::Initialize()
{
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1),true);
	AddCollider(collision);
}

//�X�V
void FirePillar::Update()
{
	if (hModel_ < 0)
	{
		///////////���f���̃��[�h////////////////
		hModel_ = Model::Load(modelNamePath_);
		assert(hModel_ >= 0);
	}

	transform_.scale_.y = abs(PILLAR_SIZE * sin(eruption_));
	SetScaleCollider(XMFLOAT3(0, transform_.scale_.y, 0));
	eruption_ += ERUPTION_SPEED;
}

//�`��
void FirePillar::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void FirePillar::Release()
{

}
//���f���Z�b�g
void FirePillar::SetFirePillar(std::string modelNamePath, float posX, float posY, float posZ)
{
	transform_.position_ = XMFLOAT3(posX, posY, posZ);
	modelNamePath_ = modelNamePath;
}

void FirePillar::SetFirePillar(std::string modelNamePath, XMFLOAT3 position, XMFLOAT3 angle)
{
	transform_.position_ = position;
	transform_.rotate_ = angle;
	modelNamePath_ = modelNamePath;
}