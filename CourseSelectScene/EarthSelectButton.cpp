#include "EarthSelectButton.h"
#include "../Engine/Image.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Input.h"

//コンストラクタ
EarthSelectButton::EarthSelectButton(GameObject* parent)
	: Button(parent, "EarthSelectButton")
{
	fileNamePas = "Image/Earth.png";
	//transform_.scale_.x *= 0.8;
	transform_.scale_.y *= 0.5;
	transform_.position_.y = 0.5;
}

void EarthSelectButton::IsButtonPush()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_EARTH);
}

