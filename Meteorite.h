#pragma once
#include "Engine/GameObject.h"
#include "Stage.h"
class Meteorite : public GameObject
{
    int hModel_;
    float ROTATE_SPEED;
    std::string modelNamePath_;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    Meteorite(GameObject* parent);

    //�f�X�g���N�^
    ~Meteorite();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void OnCollision(GameObject* pTarget);

    void SetMeteorite(std::string modelNamePath,float posX, float posY, float posZ);
};

