#pragma once
#include "../Button.h"

class MonthSelectButton : public Button
{
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	MonthSelectButton(GameObject* parent);

	//�{�^���������ꂽ�牽���邩
	void IsButtonPush() override;
};

