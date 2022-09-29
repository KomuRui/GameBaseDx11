#pragma once
#include"Engine/GameObject.h"
#include"EarthScene/Bill.h"
class CreateBill : public GameObject
{
    Bill* p_;
public:
    //�R���X�g���N�^
  //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    CreateBill(GameObject* parent);

    //�f�X�g���N�^
    ~CreateBill();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetModel(std::string fileNamePath, XMFLOAT3 position, float angle);
};

