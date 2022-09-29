#include "Meteorite.h"
#include"Engine/Model.h"

//コンストラクタ
    //引数：parent  親オブジェクト（PlayScene）
Meteorite::Meteorite(GameObject* parent)
    :GameObject(parent,"Meteorite"), hModel_(-1),modelNamePath_(""), ROTATE_SPEED(0.1f)
{

}

//デストラクタ
Meteorite::~Meteorite()
{

}

//初期化
void Meteorite::Initialize()
{
    ///////////////////モデルロード///////////////////////
    //hModel_ = Model::Load("PlayScene/Model/Meteorite.fbx");
    

    transform_.scale_ = XMFLOAT3(3, 3, 3);
    //transform_.position_ = XMFLOAT3(-240, 3, 0);

    //コライダー
    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.0f);
    AddCollider(collision);
}

//更新
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

//描画
void Meteorite::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
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
