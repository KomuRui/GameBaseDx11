#include "Bill.h"
#include"../Engine/Model.h"
#include"BillBoard.h"
//�R���X�g���N�^
//�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
Bill::Bill(GameObject* parent)
    :GameObject(parent, "Bill"),hModel_(-1),fileNamePath_("")
{


}

//�f�X�g���N�^
Bill::~Bill()
{

}

//������
void Bill::Initialize()
{
    transform_.scale_ = XMFLOAT3(3, 3, 3);
}

//�X�V
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

//�`��
void Bill::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}
//�J��
void Bill::Release()
{

}

void Bill::SetModel(std::string fileNamePath, XMFLOAT3 position,float angle)
{
    fileNamePath_ = fileNamePath;
    transform_.position_ = position;
    transform_.rotate_.y = angle;
}
