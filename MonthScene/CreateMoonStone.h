#pragma once
#include"../Engine/GameObject.h"
#include"MoonStone.h"
class CreateMoonStone : public GameObject
{
    MoonStone* pMoon_[3];
public:
    //�R���X�g���N�^
   //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    CreateMoonStone(GameObject* parent);

    //�f�X�g���N�^
    ~CreateMoonStone();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

