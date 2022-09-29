#include "CourseSelectScene.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Model.h"
#include "../Engine/SceneManager.h"
#include "EarthSelectButton.h"
#include "SunSelectButton.h"
#include "MonthSelectButton.h"

//�R���X�g���N�^
CourseSelectScene::CourseSelectScene(GameObject* parent)
	: GameObject(parent, "CourseSelectScene"), hPict_(-1), nowType(0)
{
}

//������
void CourseSelectScene::Initialize()
{
	pbutton[Earth] = Instantiate<EarthSelectButton>(this);
	pbutton[Sun]   = Instantiate<SunSelectButton>(this);
	pbutton[Month] = Instantiate<MonthSelectButton>(this);

	pbutton[Earth]->SetSelect(true);

	///////////////�摜�f�[�^�̃��[�h///////////////////

	hPict_ = Image::Load("Image/BackGround.jpg");
	assert(hPict_ >= 0);
}

//�X�V
void CourseSelectScene::Update()
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
			pbutton[Earth]->SetSelect(true);
			nowType = 0;
		}
	}
}

//�`��
void CourseSelectScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void CourseSelectScene::Release()
{
}
