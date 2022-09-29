#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Time.h"
#include "../Engine/SceneManager.h"

//�����V�[�����Ǘ�����N���X
class EarthScene : public GameObject
{
	enum ImagePicture
	{
		haikei,
		haikei2,
		Maphaikei,
		SIZE_MAX_IMAGEPICTURE
	};

	SceneManager* pSceneManager;

	//���f���ԍ�
	int hModel_;

	//�摜�ԍ�
	int hPict_[SIZE_MAX_IMAGEPICTURE];

	//�w�iflag
	bool haikeiflag_;

public:

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	EarthScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�Z�b�g�w�i
	void Sethaikei() { haikeiflag_ = !haikeiflag_; }
};

