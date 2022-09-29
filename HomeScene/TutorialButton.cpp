#include "TutorialButton.h"
#include "../Engine/Image.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Input.h"
//コンストラクタ
TutorialButton::TutorialButton(GameObject* parent)
	: Button(parent, "TutorialButton")
{
	fileNamePas = "Image/Tutorial.png";
	//transform_.scale_.x *= 0.8;
	transform_.scale_.y *= 0.5;
	transform_.position_.y = -0.5;
}

void TutorialButton::IsButtonPush()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_COURSEORCUSTOMIZED);
}