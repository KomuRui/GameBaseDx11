#pragma once
#include "../Button.h"
class DuoButton :
    public Button
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	DuoButton(GameObject* parent);

	//ボタンが押されたら何するか
	void IsButtonPush() override;
};

