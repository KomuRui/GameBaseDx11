#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Time.h"

//�����V�[�����Ǘ�����N���X
class MonthScene : public GameObject
{
	//�^�C���̕\��
	Time* timeConter_;

public:

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	MonthScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

