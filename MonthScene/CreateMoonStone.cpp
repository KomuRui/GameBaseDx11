#include "CreateMoonStone.h"
//コンストラクタ
   //引数：parent  親オブジェクト（PlayScene）
CreateMoonStone::CreateMoonStone(GameObject* parent)
	:GameObject(parent, "CreateMoonStone"),
	pMoon_()
{

}

//デストラクタ
CreateMoonStone::~CreateMoonStone()
{

}

//初期化
void CreateMoonStone::Initialize()
{
	pMoon_[0] = Instantiate<MoonStone>(GetParent());
	pMoon_[0]->SetMoonStone("EarthScene/Model/MoonStone.fbx", -240, 3, 2);

	pMoon_[1] = Instantiate<MoonStone>(GetParent());
	pMoon_[1]->SetMoonStone("EarthScene/Model/MoonStone.fbx", -240, 4, 4);

	pMoon_[2] = Instantiate<MoonStone>(GetParent());
	pMoon_[2]->SetMoonStone("EarthScene/Model/MoonStone.fbx", -240, 5, 6);

}

//更新
void CreateMoonStone::Update()
{

}

//描画
void CreateMoonStone::Draw()
{

}

//開放
void CreateMoonStone::Release()
{
}