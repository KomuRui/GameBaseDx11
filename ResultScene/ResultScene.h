#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Time.h"

//�����V�[�����Ǘ�����N���X
class ResultScene : public GameObject
{
	int hPict_;    //�摜�ԍ�

public:

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	ResultScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
