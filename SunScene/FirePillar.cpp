#include "FirePillar.h"
#include"../Engine/Model.h"
#include"../Engine/BoxCollider.h"

//コンストラクタ
   //引数：parent  親オブジェクト（PlayScene）
FirePillar::FirePillar(GameObject* parent)
	:GameObject(parent,"FirePillar"),
	hModel_(-1),
	modelNamePath_(""),
	eruption_(0),
	//////////噴出速度設定////////
	ERUPTION_SPEED(0.05f),
	//////////噴出サイズ設定
	PILLAR_SIZE(5.0f)
{

}

//デストラクタ
FirePillar::~FirePillar()
{

}

//初期化
void FirePillar::Initialize()
{
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1),true);
	AddCollider(collision);
}

//更新
void FirePillar::Update()
{
	if (hModel_ < 0)
	{
		///////////モデルのロード////////////////
		hModel_ = Model::Load(modelNamePath_);
		assert(hModel_ >= 0);
	}

	transform_.scale_.y = abs(PILLAR_SIZE * sin(eruption_));
	SetScaleCollider(XMFLOAT3(0, transform_.scale_.y, 0));
	eruption_ += ERUPTION_SPEED;
}

//描画
void FirePillar::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void FirePillar::Release()
{

}
//モデルセット
void FirePillar::SetFirePillar(std::string modelNamePath, float posX, float posY, float posZ)
{
	transform_.position_ = XMFLOAT3(posX, posY, posZ);
	modelNamePath_ = modelNamePath;
}

void FirePillar::SetFirePillar(std::string modelNamePath, XMFLOAT3 position, XMFLOAT3 angle)
{
	transform_.position_ = position;
	transform_.rotate_ = angle;
	modelNamePath_ = modelNamePath;
}