#pragma once
#include "../Button.h"
class SoloButton :
    public Button
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	SoloButton(GameObject* parent);

	//ボタンが押されたら何するか
	void IsButtonPush() override;
};

