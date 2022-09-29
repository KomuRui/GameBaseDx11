#include "CreateHole.h"

//コンストラクタ
 //引数：parent  親オブジェクト（PlayScene）
CreateHole::CreateHole(GameObject* parent)
	:GameObject(parent,"CreateHole"),
	p_(nullptr)
{

}

//デストラクタ
CreateHole::~CreateHole()
{

}

//初期化
void CreateHole::Initialize()
{
	p_ = Instantiate<WormHole>(GetParent());
	p_->SetStart_To_End(XMFLOAT3(1450, 230, 2200), XMFLOAT3(1450, 1780, 2200));

	p_ = Instantiate<WormHole>(GetParent());
	p_->SetStart_To_End(XMFLOAT3(1900, 1780, 910), XMFLOAT3(1900, 230, 910));
}
//更新
void CreateHole::Update()
{

}

//描画
void CreateHole::Draw()
{

}

//開放
void CreateHole::Release()
{

}