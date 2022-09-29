#pragma once
#include "../Button.h"

class BackButton : public Button
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	BackButton(GameObject* parent);

	//ボタンが押されたら何するか
	void IsButtonPush() override;
};

