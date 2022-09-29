#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"
#include "Stage.h"
#include <list>

//���������Ǘ�����N���X
class Player : public GameObject
{

    ///////////////////���f��///////////////////////

    int hModel_;               //���f���ԍ�

    ///////////////////Player///////////////////////

    const float ROTATE_SPEED;               //�L�����̉�]���x
          float SPEED_Z;                    //�L�����̑O�ɐi�ނ̃X�s�[�h
    const float SPEED_S;                    //�L�����̂悱�ɐi�ނ̃X�s�[�h
    const float CHAR_ANGLE;                 //���ő�p�x
    const float Limit;                      //�s�b�`�̌��E�l
    const float move;                       //�L�����̏㉺�̌���
    const float MAX_SPEED;                  //�ō����x
    const float LOWEST_SPEED;               //�Œᑬ�x
    const float ACCELERATION_DECELERATION;  //��������
    const float CHARGE_ACCELERATION;        //�`���[�W�ŉ��������ō����x
    const XMFLOAT3 rpos;

    ///////////////////�J����///////////////////////

    const XMVECTOR CAM_VEC;    //�J�����̃|�W�V����
          XMFLOAT3 CAM_COLL;   //�J�����̃R���W����  

    /////////////////�����蔻��/////////////////////

    Stage* pStage;                  //�X�e�[�W�̃��f���ԍ������

    enum StageRayDecision           //�e�����ւ̓����蔻�肷�邽�߂ɗ񋓂���
    {
        Straight = 0,               //�O
        Back,                       //��
        Left,                       //��
        Right,                      //�E
        Under,                      //��
        Top,                        //��
        MAX_RAY_SIZE
    };
   
    /////////////////�Đ��@�\/////////////////////

    bool PlayVideos;
    bool InitializeFlag;                      //�Đ��@�\���s���Ƃ��ɕK�v�ȃt���O
    int status;                               //���(�O�Ȃ瑀��,1�Ȃ�Đ�)
    std::list<std::list<int>>	MoveList_;    //�{�����Ă����Ԃ̎��̑SFPS�̍s��������List
    std::list<int>	OneFpsMoveList_;          //1FPS�̍s���������List

    enum Function                             //�v���C���𑀍삷�邽�߂̊֐����Ƃɗ�
    {
        ChargeSpeed = 0,
        AcceleRation,
        RollingR,
        RollingL,
        Up,
        Down,
    };

    SceneManager* pSceneManager;

public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    
    ////////////���c����֐�//////////////
    
    //���[�@�E��]
    void RollingRight();

    //���[�@�E��] �R���g���[���[
    void RollingRight(float PadL);

    //���[�@����]
    void RollingLeft();

    //���[�@����] �R���g���[���[
    void RollingLeft(float PadL);

    //�s�b�`�@���]
    void PitchingUp();

    //�s�b�`�@���] �R���g���[���[
    void PitchingUp(float PadL);

    //�s�b�`�@����]
    void PitchingDown();

    //�s�b�`�@����] �R���g���[���[
    void PitchingDown(float PadL);

    //���[�@�@���ړ��i�E
    void YawingRight();

    //���[�@�@���ړ��i��
    void YawingLeft();

    //���[�@�����̈ʒu�ɖ߂�
    void InitialRolling();

    //�O�ɐi��
    void MoveOn();

    //����
    void Acceleration();

    void Acceleration(float PadL);

    //����
    void Deceleration();

    //�`���[�W����
    void ChargeAcceleration();

    //��]�̊֐�
    float  FunctionRotation();

    //�������̋���
    void AccelerationBehavior();

    //�������̋���
    void DecelerationBehavior();

    ////////////���C//////////////

    //�X�e�[�W�Ƃ̓����蔻��
    void StageRayCast(RayCastData* data);

    //�Z�b�g
    void SetPlayVideo(bool flag) { PlayVideos = flag; }
    void SetStatus(int num) { status = num; }
};