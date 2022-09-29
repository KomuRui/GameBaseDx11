#pragma once
#include "../Button.h"

class CourseSelectButton : public Button
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	CourseSelectButton(GameObject* parent);

	//ボタンが押されたら何するか
	void IsButtonPush() override;
};

