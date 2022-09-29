#pragma once
#include"../Engine/GameObject.h"
class FirePillar : public GameObject
{
    int hModel_;
    std::string modelNamePath_;
    float eruption_;
    const float ERUPTION_SPEED;
    const float PILLAR_SIZE;

public:
    //�R���X�g���N�^
   //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    FirePillar(GameObject* parent);

    //�f�X�g���N�^
    ~FirePillar();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //���f���Z�b�g
    void SetFirePillar(std::string modelNamePath, float posX, float posY, float posZ);
    void SetFirePillar(std::string modelNamePath, XMFLOAT3 position,XMFLOAT3 angle);
};

