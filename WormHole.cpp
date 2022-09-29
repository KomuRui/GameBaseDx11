#include "WormHole.h"
#include"Engine/Model.h"
#include"Engine/BoxCollider.h"
#include "EarthScene/EarthScene.h"
//�R���X�g���N�^
 //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
WormHole::WormHole(GameObject* parent)
:GameObject(parent,"WormHole"),
hModel_(-1),
end_(XMFLOAT3(0,0,0))
{

}

//�f�X�g���N�^
WormHole::~WormHole()
{

}

//������
void WormHole::Initialize()
{
	hModel_ = Model::Load("EarthScene/Model/WormHole.fbx");
	assert(hModel_ >= 0);
	//Model::SetAlpha(hModel_, 1);
	BoxCollider* pCollision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(200,400,200));
	AddCollider(pCollision);

	Model::SetAmbient(hModel_,300);
}

//�X�V
void WormHole::Update()
{
	transform_.rotate_.x += 0.5;
}

//�`��
void WormHole::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void WormHole::Release()
{

}

void WormHole::OnCollision(GameObject* target)
{
	if (target->GetObjectName() == "Player")
	{
		EarthScene* pEarthScene = (EarthScene*)FindObject("EarthScene");
		pEarthScene->Sethaikei();
		target->SetPosition(end_);
	}
}
void WormHole::SetStart_To_End(XMFLOAT3 start, XMFLOAT3 end)
{
	transform_.position_ = start;
	end_ = end;
}