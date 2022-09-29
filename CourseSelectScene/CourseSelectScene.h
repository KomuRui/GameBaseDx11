#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Time.h"
#include "../Button.h"

//�����V�[�����Ǘ�����N���X
class CourseSelectScene : public GameObject
{
	int hPict_;    //�摜�ԍ�

	int nowType;   //���ǂ��̃{�^�������Ă��邩

	enum ButtonType
	{
		Earth,
		Sun,
		Month,
		MAX
	};

	Button* pbutton[MAX];

public:

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	CourseSelectScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

