#include "SoloButton.h"
#include "../Engine/Image.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Input.h"
//コンストラクタ
SoloButton::SoloButton(GameObject* parent)
	: Button(parent, "SoloButton")
{
	fileNamePas = "Image/OnePlay.png";
	//transform_.scale_.x *= 0.8;
	transform_.scale_.y *= 0.5;
	transform_.position_.y = 0.5;
}

void SoloButton::IsButtonPush()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_COURSEORCUSTOMIZED);
}
