#include "CreateMeteorite.h"
#include"Engine/Global.h"
//�R���X�g���N�^
   //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
CreateMeteorite::CreateMeteorite(GameObject* parent)
	:GameObject(parent, "CreateMeteorite")
{

}

//�f�X�g���N�^
CreateMeteorite::~CreateMeteorite()
{

}

//������
void CreateMeteorite::Initialize()
{
	std::string filePath = "EarthScene/Model/";

	////////////////////////////����/////////////////////////////////
	//�X�^�[�g����1��ڂ̏�Q��
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Star_Main_Character.fbx", 910, 170, 1500);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 940, 170, 1500);

	//�X�^�[�g����2���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 860, 200, 1600);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 890, 200, 1600);

	//�X�^�[�g����3���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 860, 170, 1800);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 900, 200, 1800);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 940, 200, 1800);

	//�X�^�[�g����4���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 860, 200, 2000);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 900, 170, 2000);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 940, 200, 2000);

	//�X�^�[�g����5���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 860, 200, 2200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 900, 200, 2200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 940, 200, 2200);

	//�X�^�[�g����6���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1210, 170, 2200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1180, 170, 2200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1150, 170, 2200);

	//�X�^�[�g����7���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1210, 200, 2050);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1180, 200, 2050);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1150, 200, 2050);

	//�X�^�[�g����8���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1300, 200, 1930);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1300, 200, 1900);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1300, 170, 1870);
	/////////////////////////�I��//////////////////////////////////	
	//�X�^�[�g����23���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1535, 170, 1100);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1575, 200, 1100);
	
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1615, 200, 1100);

	//�X�^�[�g����24���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1540, 200, 1300);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1570, 170, 1300);

	//�X�^�[�g����25���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1330, 200, 1200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1290, 200, 1200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1250, 170, 1200);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1250, 200, 1200);

	//�X�^�[�g����26���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1150, 200, 950);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1150, 200, 910);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1150, 200, 870);

	//�X�^�[�g����27���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1010, 200, 1100);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1010, 170, 1100);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 980, 200, 1100);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 980, 170, 1100);

	//�X�^�[�g����28���
	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 980, 200, 1300);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1020, 200, 1300);

	p_ = Instantiate<Meteorite>(GetParent());
	p_->SetMeteorite(filePath + "Meteorite.fbx", 1060, 200, 1300);
}

//�X�V
void CreateMeteorite::Update()
{

}

//�`��
void CreateMeteorite::Draw()
{

}

//�J��
void CreateMeteorite::Release()
{
}