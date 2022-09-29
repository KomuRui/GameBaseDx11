#include "CourseOrCustomizedScene.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Model.h"
#include "../Engine/SceneManager.h"
#include "CourseSelectButton.h"
#include "CustomizeButton.h"

//�R���X�g���N�^
CourseOrCustomizedScene::CourseOrCustomizedScene(GameObject* parent)
	: GameObject(parent, "CourseOrCustomizedScene"), hPict_(-1)
{
}

//������
void CourseOrCustomizedScene::Initialize()
{
	pbutton[CourseSelect] = Instantiate<CourseSelectButton>(this);
	pbutton[Customize]    = Instantiate<CustomizeButton>(this);

	pbutton[CourseSelect]->SetSelect(true);

	///////////////�摜�f�[�^�̃��[�h///////////////////

	//�^�C�g��
	hPict_ = Image::Load("Image/BackGround.jpg");
	assert(hPict_ >= 0);
}

//�X�V
void CourseOrCustomizedScene::Update()
{
	if (Input::IsKeyDown(DIK_S))
	{
		pbutton[CourseSelect]->SetSelect(!pbutton[CourseSelect]->GetSelect());
		pbutton[Customize]->SetSelect(!pbutton[Customize]->GetSelect());
	}
}

//�`��
void CourseOrCustomizedScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void CourseOrCustomizedScene::Release()
{
}
