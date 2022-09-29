#include "BillBoard.h"
#include"../Engine/Model.h"
#include"../Engine/BoxCollider.h"
//�R���X�g���N�^
//�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
BillBoard::BillBoard(GameObject* parent)
	:GameObject(parent, "BillBoard"), hModel_(-1) , modelNamePath_("")
{

}


//�f�X�g���N�^
BillBoard::~BillBoard()
{

}

//������
void BillBoard::Initialize()
{
	transform_.scale_ = XMFLOAT3(1, 1, 1);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 4, 1));

}

//�X�V
void BillBoard::Update()
{
	if (hModel_ < 0)
	{
		///////////���f���̃��[�h////////////////
		hModel_ = Model::Load(modelNamePath_);
		assert(hModel_ >= 0);
	}

}

//�`��
void BillBoard::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void BillBoard::Release()
{

}

void BillBoard::SetBillBoard(std::string modelNamePath, float posX, float posY, float posZ)
{
	transform_.position_ = XMFLOAT3(posX, posY, posZ);
	modelNamePath_ = modelNamePath;
}
void BillBoard::SetBillBoard(std::string modelNamePath, XMFLOAT3 position)
{
	transform_.position_ = position;
	modelNamePath_ = modelNamePath;
}