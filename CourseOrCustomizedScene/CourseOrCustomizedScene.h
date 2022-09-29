#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Time.h"
#include "../Button.h"

//�����V�[�����Ǘ�����N���X
class CourseOrCustomizedScene : public GameObject
{
	int hPict_;    //�摜�ԍ�

	enum ButtonType
	{
		CourseSelect,
		Customize,
		MAX
	};

	Button* pbutton[MAX];

public:

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	CourseOrCustomizedScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

