#pragma once
#include"Engine/GameObject.h"
#include "Meteorite.h"
class CreateMeteorite : public GameObject
{
    Meteorite* p_;

public:
    //�R���X�g���N�^
   //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    CreateMeteorite(GameObject* parent);

    //�f�X�g���N�^
    ~CreateMeteorite();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;     
};

