#pragma once
#include"Engine/GameObject.h"
#include"CreateHole.h"
#include"WormHole.h"
class CreateHole : public GameObject
{
    WormHole* p_;
public:
    //�R���X�g���N�^
 //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    CreateHole(GameObject* parent);

    //�f�X�g���N�^
    ~CreateHole();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

