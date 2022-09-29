#pragma once
#include "../Button.h"

class MonthSelectButton : public Button
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	MonthSelectButton(GameObject* parent);

	//ボタンが押されたら何するか
	void IsButtonPush() override;
};

