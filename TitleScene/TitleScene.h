#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Fade.h"
#include "../Button.h"

//�����V�[�����Ǘ�����N���X
class TitleScene : public GameObject
{
	//TitleScene�ɕ\������摜
	enum TitleImages
	{
		TITLE = 0,
		START,
		MAX_SIZE_TITLEIMAGE
	};

	const float FADE_TIME = 3.0f;       //�X�v���b�V���̃t�F�[�h���鎞��
	int hPict_[MAX_SIZE_TITLEIMAGE];    //�摜�ԍ�

	Fade* pfade_;				        //�t�F�[�h�p
	Transform start_;					//start�摜�̃g�����X�t�H�[��


	int time_;                        	//����


public:

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

