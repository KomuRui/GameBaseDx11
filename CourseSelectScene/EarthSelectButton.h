#pragma once
#include "../Button.h"

class EarthSelectButton : public Button
{
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	EarthSelectButton(GameObject* parent);

	//�{�^���������ꂽ�牽���邩
	void IsButtonPush() override;
};

