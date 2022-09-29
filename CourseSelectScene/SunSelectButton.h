#pragma once
#include "../Button.h"

class SunSelectButton : public Button
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	SunSelectButton(GameObject* parent);

	//ボタンが押されたら何するか
	void IsButtonPush() override;
};

