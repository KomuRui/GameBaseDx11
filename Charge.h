#pragma once
#include "Engine/GameObject.h"


//�����V�[�����Ǘ�����N���X
class Charge : public GameObject
{
	enum ImagePicture
	{
		ChargeGage,
		ChargeMax,
		ChargeOriginal,
		SIZE_MAX_IMAGEPICTURE
	};

	//�摜�ԍ�
	int hPict_[SIZE_MAX_IMAGEPICTURE];

	//�摜���Ƃ̃g�����X�t�H�[��
	Transform tra_[SIZE_MAX_IMAGEPICTURE];

    //���Ԃ��v��
	int time;

	//ChargeGage�̌�
	int Count;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Charge(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�`���[�W�̃J�E���g��Ԃ�
	int GetCount() { return Count; }

	//�`���[�W�̃J�E���g��set
	void SetCount(int count) { Count = count; }
};