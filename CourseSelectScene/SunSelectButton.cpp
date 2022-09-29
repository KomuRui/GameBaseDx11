#include "SunSelectButton.h"
#include "../Engine/Image.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Input.h"

//コンストラクタ
SunSelectButton::SunSelectButton(GameObject* parent)
	: Button(parent, "SunSelectButton")
{
	fileNamePas = "Image/Sun.png";
	//transform_.scale_.x *= 0.8;
	transform_.scale_.y *= 0.5;
	transform_.position_.y = 0;
}

void SunSelectButton::IsButtonPush()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_EARTH);
}

