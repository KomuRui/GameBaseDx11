#include "Bill.h"
#include"../Engine/Model.h"
#include"BillBoard.h"
//コンストラクタ
//引数：parent  親オブジェクト（PlayScene）
Bill::Bill(GameObject* parent)
    :GameObject(parent, "Bill"),hModel_(-1),fileNamePath_("")
{


}

//デストラクタ
Bill::~Bill()
{

}

//初期化
void Bill::Initialize()
{
    transform_.scale_ = XMFLOAT3(3, 3, 3);
}

//更新
void Bill::Update()
{
    if (hModel_ < 0)
    {
        hModel_ = Model::Load(fileNamePath_);
        assert(hModel_ >= 0);
        BillBoard* pBill = Instantiate<BillBoard>(this);
        pBill->SetBillBoard("EarthScene/Model/BillBoard.fbx", Model::GetBonePosition(hModel_, "Root"));
    }
}

//描画
void Bill::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}
//開放
void Bill::Release()
{

}

void Bill::SetModel(std::string fileNamePath, XMFLOAT3 position,float angle)
{
    fileNamePath_ = fileNamePath;
    transform_.position_ = position;
    transform_.rotate_.y = angle;
}
