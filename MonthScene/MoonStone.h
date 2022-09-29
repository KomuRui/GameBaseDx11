#pragma once
#include"../Engine/GameObject.h"
class MoonStone : public GameObject
{
    int hModel_;
    std::string modelNamePath_;
    float basePos_;
    float floating_;
    float floatHeight_;
    const float FLOAT_LIMIT;
    const float FLOAT_SPEED;
    const float FLOAT_INTERVAL;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    MoonStone(GameObject* parent);

    //�f�X�g���N�^
    ~MoonStone();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
    void SetMoonStone(std::string modelNamePath, float posX, float posY, float posZ);
};

