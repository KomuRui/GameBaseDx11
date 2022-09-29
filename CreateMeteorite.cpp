#include "CreateMeteorite.h"
#include"Engine/Global.h"
//コンストラクタ
   //引数：parent  親オブジェクト（PlayScene）
CreateMeteorite::CreateMeteorite(GameObject* parent)
	:GameObject(parent, "CreateMeteorite")
{

}

//デストラクタ
CreateMeteorite::~CreateMeteorite()
{

}

//初期化
void CreateMeteorite::Initialize()
{
	std::string filePath = "EarthScene/Model/";

	////////////////////////////序盤/////////////////////////////////
	//スタートから1列目の障害物
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Star_Main_Character.fbx", 910, 170, 1500);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 940, 170, 1500);

	//スタートから2列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 860, 200, 1600);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 890, 200, 1600);

	//スタートから3列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 860, 170, 1800);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 900, 200, 1800);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 940, 200, 1800);

	//スタートから4列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 860, 200, 2000);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 900, 170, 2000);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 940, 200, 2000);

	//スタートから5列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 860, 200, 2200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 900, 200, 2200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 940, 200, 2200);

	//スタートから6列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1210, 170, 2200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1180, 170, 2200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1150, 170, 2200);

	//スタートから7列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1210, 200, 2050);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1180, 200, 2050);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1150, 200, 2050);

	//スタートから8列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1300, 200, 1930);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1300, 200, 1900);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1300, 170, 1870);
	/////////////////////////終盤//////////////////////////////////	
	//スタートから23列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1535, 170, 1100);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1575, 200, 1100);
	
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1615, 200, 1100);

	//スタートから24列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1540, 200, 1300);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1570, 170, 1300);

	//スタートから25列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1330, 200, 1200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1290, 200, 1200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1250, 170, 1200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1250, 200, 1200);

	//スタートから26列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1150, 200, 950);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1150, 200, 910);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1150, 200, 870);

	//スタートから27列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1010, 200, 1100);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1010, 170, 1100);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 980, 200, 1100);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 980, 170, 1100);

	//スタートから28列目
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 980, 200, 1300);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1020, 200, 1300);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1060, 200, 1300);
}

//更新
void CreateMeteorite::Update()
{

}

//描画
void CreateMeteorite::Draw()
{

}

//開放
void CreateMeteorite::Release()
{
}