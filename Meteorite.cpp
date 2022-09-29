#include "Meteorite.h"
#include"Engine/Model.h"

//�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
Meteorite::Meteorite(GameObject* parent)
    :GameObject(parent,"Meteorite"), hModel_(-1),modelNamePath_(""), ROTATE_SPEED(0.1f)
{

}

//�f�X�g���N�^
Meteorite::~Meteorite()
{

}

//������
void Meteorite::Initialize()
{
    ///////////////////���f�����[�h///////////////////////
    //hModel_ = Model::Load("PlayScene/Model/Meteorite.fbx");
    

    transform_.scale_ = XMFLOAT3(3, 3, 3);
    //transform_.position_ = XMFLOAT3(-240, 3, 0);

    //�R���C�_�[
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.0f);
    AddCollider(collision);
}

//�X�V
void Meteorite::Update()
{
    if (hModel_ < 0)
    {
        hModel_ = Model::Load(modelNamePath_);
        assert(hModel_ >= 0);
        Model::SetAlpha(hModel_, 1);
        Model::SetAmbient(hModel_, 5);
    }
    transform_.rotate_.x += ROTATE_SPEED;
}

//�`��
void Meteorite::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Meteorite::Release()
{

}
void Meteorite::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Player")
    {
        KillMe();
    }
}

void Meteorite::SetMeteorite(std::string modelNamePath,float posX, float posY, float posZ)
{
    transform_.position_ = XMFLOAT3(posX, posY, posZ);
    modelNamePath_ = modelNamePath;
}
