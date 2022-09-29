#pragma once
#include "Engine/GameObject.h"
#include "Engine/Time.h"
#include "Engine/SceneManager.h"

//���������Ǘ�����N���X
class Stage : public GameObject
{
    int hPict_;                    //�摜�ԍ�
    int hModel_;                   //���f���ԍ�
    int hModel_wall;
    int hModel_space;

    SceneManager* pSceneManager;
    
    Time* timeConter_;         //�^�C���̕\��

    int hPict_2;               //�摜�ԍ�

    Transform spa;
     
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�X�e�[�W�̃��f���ԍ���Ԃ��Ă�����
    int GetModelHandle() { return hModel_; }

    //�X�e�[�W�̃��f���ԍ���Ԃ��Ă�����
    int GetModelHandle2() { return hModel_wall; }

};