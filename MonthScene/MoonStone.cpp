#include "MoonStone.h"
#include"../Engine/Model.h"
#include"../Engine/SphereCollider.h"
//�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
MoonStone::MoonStone(GameObject* parent)
    :GameObject(parent, "MoonStone"),
    hModel_(-1),
    modelNamePath_(""),
    floating_(0),
    floatHeight_(0),
    basePos_(0),
    FLOAT_LIMIT(5),
    FLOAT_SPEED(0.01),
    FLOAT_INTERVAL(150)
{

}

//�f�X�g���N�^
MoonStone::~MoonStone()
{

}

//������
void MoonStone::Initialize()
{
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.0f);
    AddCollider(collision);
    basePos_ = transform_.position_.y;
}

//�X�V
void MoonStone::Update()
{
    if (hModel_ < 0)
    {
        hModel_ = Model::Load(modelNamePath_);
        assert(hModel_ >= 0);
    }

    /////////��������//////////
    floatHeight_ = FLOAT_LIMIT * sin(floating_);
    if (floatHeight_ >= 0)
    {
        transform_.position_.y = basePos_ + floatHeight_;
        floating_ += FLOAT_SPEED;
    }
    else if (floatHeight_ < 0)
    {
        floating_=0;
    }
    
}

//�`��
void MoonStone::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void MoonStone::Release()
{

}
void MoonStone::SetMoonStone(std::string modelNamePath, float posX, float posY, float posZ)
{
    transform_.position_ = XMFLOAT3(posX, posY, posZ);
    modelNamePath_ = modelNamePath;
}