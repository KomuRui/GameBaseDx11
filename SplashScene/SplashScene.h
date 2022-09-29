#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Fade.h"


//�����V�[�����Ǘ�����N���X
class SplashScene : public GameObject
{
	//SplashScene�ɕ\������摜
	enum Images
	{
		TOUHOKU = 0,
		TEAM,
		MAX_SIZE
	};

	int hPict_[MAX_SIZE];			 //�摜�ԍ�
	int status_;					 //�X�e�[�^�X
	int count_;						 //�����o�鑬��
	const float FADE_TIME = 3.0f;	 //�X�v���b�V���̃t�F�[�h���鎞��

	Fade* pfade_;					 //�t�F�[�h����̂ɕK�v�ȃN���X

public:

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	SplashScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

