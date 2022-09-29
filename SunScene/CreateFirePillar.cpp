#include "CreateFirePillar.h"
#include"../Engine/Global.h"
//コンストラクタ
  //引数：parent  親オブジェクト（PlayScene）
CreateFirePillar::CreateFirePillar(GameObject* parent)
	:GameObject(parent,"CreateFirePillar"),pFire_()
{

}

//デストラクタ
CreateFirePillar::~CreateFirePillar()
{

}

//初期化
void CreateFirePillar::Initialize()
{
	pFire_[0] = Instantiate<FirePillar>(GetParent());
	pFire_[0]->SetFirePillar("EarthScene/Model/FirePillar.fbx", XMFLOAT3(-240, 5, 5),XMFLOAT3(90,0,0));

	pFire_[1] = Instantiate<FirePillar>(GetParent());
	pFire_[0]->SetFirePillar("EarthScene/Model/FirePillar.fbx", -240, 3, 1);

	pFire_[2] = Instantiate<FirePillar>(GetParent());
	pFire_[0]->SetFirePillar("EarthScene/Model/FirePillar.fbx", -240, 4, 6);
}

//更新
void CreateFirePillar::Update()
{

}

//描画
void CreateFirePillar::Draw()
{

}

//開放
void CreateFirePillar::Release()
{
}