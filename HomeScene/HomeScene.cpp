#include "HomeScene.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Model.h"
#include "../Engine/SceneManager.h"
#include "SoloButton.h"
#include "DuoButton.h"
#include "TutorialButton.h"


//�R���X�g���N�^
HomeScene::HomeScene(GameObject* parent)
	: GameObject(parent, "HomeScene"), hPict_(-1), nowType(0)
{
}

//������
void HomeScene::Initialize()
{
	pbutton[Solo] = Instantiate<SoloButton>(this);
	pbutton[Duo] = Instantiate<DuoButton>(this);
	pbutton[Tutorial] = Instantiate<TutorialButton>(this);

	pbutton[Solo]->SetSelect(true);
	///////////////�摜�f�[�^�̃��[�h///////////////////

	//�^�C�g��
	hPict_ = Image::Load("Image/BackGround.jpg");
	assert(hPict_ >= 0);
}

//�X�V
void HomeScene::Update()
{
	if (Input::IsKeyDown(DIK_S))
	{
		if (nowType + 1 < MAX)
		{
			for (int i = 0; i < MAX; i++)
			{
				if (nowType + 1 == i)
				{
					pbutton[i]->SetSelect(true);
				}
				else
				{
					pbutton[i]->SetSelect(false);
				}
			}

			nowType = nowType + 1;
		}
		else
		{
			pbutton[nowType]->SetSelect(false);
			pbutton[Solo]->SetSelect(true);
			nowType = 0;
		}
	}
}

//�`��
void HomeScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void HomeScene::Release()
{
}
