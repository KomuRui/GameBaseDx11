#pragma once
#include "Engine/GameObject.h"


//�����V�[�����Ǘ�����N���X
class Star : public GameObject
{
	int hPict_;    //�摜�ԍ�

	int hMict_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Star(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};