#include "DuoButton.h"
#include "../Engine/Image.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Input.h"
//コンストラクタ
DuoButton::DuoButton(GameObject* parent)
	: Button(parent, "DuoButton")
{
	fileNamePas = "Image/TwoPlay.png";
	//transform_.scale_.x *= 0.8;
	transform_.scale_.y *= 0.5;
	transform_.position_.y = 0;
}

void DuoButton::IsButtonPush()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_COURSEORCUSTOMIZED);
}