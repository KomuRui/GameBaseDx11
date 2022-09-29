#include "MoonStone.h"
#include"../Engine/Model.h"
#include"../Engine/SphereCollider.h"
//コンストラクタ
    //引数：parent  親オブジェクト（PlayScene）
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

//デストラクタ
MoonStone::~MoonStone()
{

}

//初期化
void MoonStone::Initialize()
{
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.0f);
    AddCollider(collision);
    basePos_ = transform_.position_.y;
}

//更新
void MoonStone::Update()
{
    if (hModel_ < 0)
    {
        hModel_ = Model::Load(modelNamePath_);
        assert(hModel_ >= 0);
    }

    /////////浮く処理//////////
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

//描画
void MoonStone::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void MoonStone::Release()
{

}
void MoonStone::SetMoonStone(std::string modelNamePath, float posX, float posY, float posZ)
{
    transform_.position_ = XMFLOAT3(posX, posY, posZ);
    modelNamePath_ = modelNamePath;
}