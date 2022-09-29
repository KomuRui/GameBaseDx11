#include "CreateBill.h"
#include"EarthScene/BillBoard.h"
//�R���X�g���N�^
  //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
CreateBill::CreateBill(GameObject* parent)
	:GameObject(parent,"CreateBill")
{

}

//�f�X�g���N�^
CreateBill::~CreateBill()
{

}

//������
void CreateBill::Initialize()
{
	std::string filePath = "EarthScene/Model/";
	/////////////////////����/////////////////////////////////////////
	//�X�^�[�g����9���
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(1380, 1753, 2400), -90);
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(1520, 1753, 2400), 90);
	
	//�X�^�[�g����10���
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(1860, 1753, 2250),180);
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(1860, 1753, 2380), 0);
	
	//�X�^�[�g����13���
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2210, 1753, 2200), -90);
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2350, 1753, 2200), 90);
	
	//�X�^�[�g����16���
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2000, 1753, 1685), 180);
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2000, 1753, 1820), 0);
	
	//�X�^�[�g����20���
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2000, 1753, 1395), 0);
	p_ = Instantiate<Bill>(GetParent());
	p_->SetModel(filePath + "Bill.fbx", XMFLOAT3(2000, 1753, 1260), 180);
}

//�X�V
void CreateBill::Update()
{

}

//�`��
void CreateBill::Draw()
{

}

//�J��
void CreateBill::Release()
{

}

void CreateBill::SetModel(std::string fileNamePath, XMFLOAT3 position, float angle)
{

}