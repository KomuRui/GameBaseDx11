#pragma once
#include"../Engine/GameObject.h"
class Bill : public GameObject
{

    int hModel_;
    std::string fileNamePath_;
public:
    //�R���X�g���N�^
  //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    Bill(GameObject* parent);

    //�f�X�g���N�^
    ~Bill();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetModel(std::string fileNamePath,XMFLOAT3 position,float angle);
};

