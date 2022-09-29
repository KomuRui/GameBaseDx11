#include "CourseSelectButton.h"
#include "../Engine/Image.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Input.h"

//コンストラクタ
CourseSelectButton::CourseSelectButton(GameObject* parent)
	: Button(parent, "CourseSelectButton")
{
	fileNamePas = "Image/CourseSelect.png";
	//transform_.scale_.x *= 0.8;
	transform_.scale_.y *= 0.6;
	transform_.position_.y = 0.4;
}

void CourseSelectButton::IsButtonPush()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_COURSESELECT);
}

