#pragma once
#include "../Button.h"
class DuoButton :
    public Button
{
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	DuoButton(GameObject* parent);

	//�{�^���������ꂽ�牽���邩
	void IsButtonPush() override;
};

