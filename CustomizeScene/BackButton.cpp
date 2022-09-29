#include "BackButton.h"
#include "../Engine/Image.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Input.h"

//コンストラクタ
BackButton::BackButton(GameObject* parent)
	: Button(parent, "BackButton")
{
	fileNamePas = "Image/BackButton.png";
	transform_.scale_.x *= 0.6;
	transform_.scale_.y *= 0.6;
	transform_.position_.y = 0.86;
	transform_.position_.x = -0.84;
}

void BackButton::IsButtonPush()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_COURSEORCUSTOMIZED);
}

