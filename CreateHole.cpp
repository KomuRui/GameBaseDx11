#include "CreateHole.h"

//�R���X�g���N�^
 //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
CreateHole::CreateHole(GameObject* parent)
	:GameObject(parent,"CreateHole"),
	p_(nullptr)
{

}

//�f�X�g���N�^
CreateHole::~CreateHole()
{

}

//������
void CreateHole::Initialize()
{
	p_ = Instantiate<WormHole>(GetParent());
	p_->SetStart_To_End(XMFLOAT3(1450, 230, 2200), XMFLOAT3(1450, 1780, 2200));

	p_ = Instantiate<WormHole>(GetParent());
	p_->SetStart_To_End(XMFLOAT3(1900, 1780, 910), XMFLOAT3(1900, 230, 910));
}
//�X�V
void CreateHole::Update()
{

}

//�`��
void CreateHole::Draw()
{

}

//�J��
void CreateHole::Release()
{

}