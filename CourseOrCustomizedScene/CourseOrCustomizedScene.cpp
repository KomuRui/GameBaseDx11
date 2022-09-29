#include "CourseOrCustomizedScene.h"
#include "../Engine/Image.h"
#include "../Engine/Input.h"
#include "../Engine/Model.h"
#include "../Engine/SceneManager.h"
#include "CourseSelectButton.h"
#include "CustomizeButton.h"

//コンストラクタ
CourseOrCustomizedScene::CourseOrCustomizedScene(GameObject* parent)
	: GameObject(parent, "CourseOrCustomizedScene"), hPict_(-1)
{
}

//初期化
void CourseOrCustomizedScene::Initialize()
{
	pbutton[CourseSelect] = Instantiate<CourseSelectButton>(this);
	pbutton[Customize]    = Instantiate<CustomizeButton>(this);

	pbutton[CourseSelect]->SetSelect(true);

	///////////////画像データのロード///////////////////

	//タイトル
	hPict_ = Image::Load("Image/BackGround.jpg");
	assert(hPict_ >= 0);
}

//更新
void CourseOrCustomizedScene::Update()
{
	if (Input::IsKeyDown(DIK_S))
	{
		pbutton[CourseSelect]->SetSelect(!pbutton[CourseSelect]->GetSelect());
		pbutton[Customize]->SetSelect(!pbutton[Customize]->GetSelect());
	}
}

//描画
void CourseOrCustomizedScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void CourseOrCustomizedScene::Release()
{
}
