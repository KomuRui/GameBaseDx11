#pragma once
#include "../Button.h"

class EarthSelectButton : public Button
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	EarthSelectButton(GameObject* parent);

	//ボタンが押されたら何するか
	void IsButtonPush() override;
};

