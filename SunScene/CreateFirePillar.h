#pragma once
#include"../Engine/GameObject.h"
#include"FirePillar.h"
class CreateFirePillar : public GameObject
{
    FirePillar* pFire_[3];

public:
    //�R���X�g���N�^
   //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    CreateFirePillar(GameObject* parent);

    //�f�X�g���N�^
    ~CreateFirePillar();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

