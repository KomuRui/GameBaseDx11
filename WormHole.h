#pragma once
#include"Engine/GameObject.h"

class WormHole : public GameObject
{
    int hModel_;
    XMFLOAT3 end_;
public:
    //�R���X�g���N�^
 //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    WormHole(GameObject* parent);

    //�f�X�g���N�^
    ~WormHole();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�Փ�
    void OnCollision(GameObject* target) override;
    void SetStart_To_End(XMFLOAT3 start, XMFLOAT3 end);
};

