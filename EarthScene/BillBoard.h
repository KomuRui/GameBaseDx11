#pragma once
#include"../Engine/GameObject.h"
class BillBoard : public GameObject
{
    int hModel_;
    std::string modelNamePath_;
public:
    //�R���X�g���N�^
 //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    BillBoard(GameObject* parent);

    //�f�X�g���N�^
    ~BillBoard();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�Ŕ��r���ɃZ�b�g
    void SetBillBoard(std::string modelNamePath, float posX, float posY, float posZ);
    void SetBillBoard(std::string modelNamePath, XMFLOAT3 position);

};

