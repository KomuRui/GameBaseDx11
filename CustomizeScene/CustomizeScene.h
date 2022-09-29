#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Time.h"

//�����V�[�����Ǘ�����N���X
class CustomizeScene : public GameObject
{
	enum TitleImages
	{
		BackGround = 0,
		CustTable,
		MAX
	};

	int hPict_[MAX];    //�摜�ԍ�

	Transform CustTable_;	//CustTable�摜�̃g�����X�t�H�[��

public:

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	CustomizeScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

