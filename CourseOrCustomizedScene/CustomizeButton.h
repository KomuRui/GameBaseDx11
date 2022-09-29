#pragma once
#include "../Button.h"

class CustomizeButton : public Button
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	CustomizeButton(GameObject* parent);

	//ボタンが押されたら何するか
	void IsButtonPush() override;
};

