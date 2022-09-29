#pragma once
#include "../Button.h"
class TutorialButton :
    public Button
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TutorialButton(GameObject* parent);

	//ボタンが押されたら何するか
	void IsButtonPush() override;
};

