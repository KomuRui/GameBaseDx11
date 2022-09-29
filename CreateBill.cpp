#include "CreateBill.h"
#include"EarthScene/BillBoard.h"
//コンストラクタ
  //引数：parent  親オブジェクト（PlayScene）
CreateBill::CreateBill(GameObject* parent)
	:GameObject(parent,"CreateBill")
{

}

//デストラクタ
CreateBill::~CreateBill()
{

}

//初期化
void CreateBill::Initialize()
{
	std::string filePath = "EarthScene/Model/";
	/////////////////////中盤/////////////////////////////////////////
	//スタートから9列目
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(1380, 1753, 2400), -90);
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(1520, 1753, 2400), 90);
	
	//スタートから10列目
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(1860, 1753, 2250),180);
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(1860, 1753, 2380), 0);
	
	//スタートから13列目
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2210, 1753, 2200), -90);
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2350, 1753, 2200), 90);
	
	//スタートから16列目
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2000, 1753, 1685), 180);
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2000, 1753, 1820), 0);
	
	//スタートから20列目
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2000, 1753, 1395), 0);
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2000, 1753, 1260), 180);
}

//更新
void CreateBill::Update()
{

}

//描画
void CreateBill::Draw()
{

}

//開放
void CreateBill::Release()
{

}

void CreateBill::SetModel(std::string fileNamePath, XMFLOAT3 position, float angle)
{

}