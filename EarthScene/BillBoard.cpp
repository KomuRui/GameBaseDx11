#include "BillBoard.h"
#include"../Engine/Model.h"
#include"../Engine/BoxCollider.h"
//コンストラクタ
//引数：parent  親オブジェクト（PlayScene）
BillBoard::BillBoard(GameObject* parent)
	:GameObject(parent, "BillBoard"), hModel_(-1) , modelNamePath_("")
{

}


//デストラクタ
BillBoard::~BillBoard()
{

}

//初期化
void BillBoard::Initialize()
{
	transform_.scale_ = XMFLOAT3(1, 1, 1);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 4, 1));

}

//更新
void BillBoard::Update()
{
	if (hModel_ < 0)
	{
		///////////モデルのロード////////////////
		hModel_ = Model::Load(modelNamePath_);
		assert(hModel_ >= 0);
	}

}

//描画
void BillBoard::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
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