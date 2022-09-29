#pragma once
#include <vector>
#include "GameObject.h"

const int MAX_OBJECT_SIZE = 50;

//�����V�[�����Ǘ�����N���X
class ImGuiSet : public GameObject
{
	//�\���������I�u�W�F�N�g���i�[����ꏊ
	//first->���f���ԍ�
	//second->���f���ԍ����Ƃ̃g�����X�t�H�[��
	std::vector<std::pair<int,Transform>>obj;

	//3D�����{�^���������Ă�����true
	bool Create3Dflag;

	//3D�����������
	int ObjectCount;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	ImGuiSet(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	void Create3D();

	//�J��
	void Release() override;
};