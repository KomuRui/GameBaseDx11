#include "CustomizeButton.h"
#include "../Engine/Image.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Input.h"

//コンストラクタ
CustomizeButton::CustomizeButton(GameObject* parent)
	: Button(parent, "CustomizeButton")
{
	fileNamePas = "Image/Customize.png";
	//transform_.scale_.x *= 0.8;
	transform_.scale_.y *= 0.6;
	transform_.position_.y = -0.4;
}

void CustomizeButton::IsButtonPush()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_CUSTOMIZE);
}

