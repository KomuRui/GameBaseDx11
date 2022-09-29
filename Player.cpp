#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Charge.h"
#include "Engine/SceneManager.h"
#include"Emitter.h"
#include"Particle.h"
#include <fstream>
#include <string>
#include <iostream>

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), 

    ///////////////////���f��///////////////////////

    hModel_(-1), 

    ///////////////////�v���C��///////////////////////

    Limit(70),
    CHAR_ANGLE(90), 
    ROTATE_SPEED(1.5f),
    SPEED_Z(0.0f),
    SPEED_S(1.0f),
    move(1.0f),
    MAX_SPEED(1.5f),
    ACCELERATION_DECELERATION(0.02f),
    LOWEST_SPEED(0.0f),
    CHARGE_ACCELERATION(2.0f),//15
    CAM_COLL(0, 3, -6),
    rpos(transform_.rotate_),

    ///////////////////�J����///////////////////////

    CAM_VEC(XMVectorSet(0.0f, 8.0f, -25.0f, 0.0f)),

    ///////////////////�����蔻��///////////////////////

    pStage(nullptr),
    
    status(0),
    InitializeFlag(false),
    PlayVideos(false)

{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    //transform_.position_.x = 1700;//48
    //transform_.position_.y = 150;
    //transform_.position_.z = 2400;

    transform_.position_.x = 900;//48
    transform_.position_.y = 152;
    transform_.position_.z = 905;

    transform_.scale_.x *= 0.5;
    transform_.scale_.y *= 0.5;
    transform_.scale_.z *= 0.5;
    


    ///////////////�摜�f�[�^�̃��[�h///////////////////
    hModel_ = Model::Load("EarthScene/Model/craft.fbx");
    assert(hModel_ >= 0);

    //�R���C�_�[
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 0), XMFLOAT3(3, 3, 3),true);
    AddCollider(collision);
    //Instantiate<Emitter>(this);

}

//�X�V
void Player::Update()
{             
    
    Charge* pCharge = (Charge*)FindObject("Charge");    //�X�e�[�W�I�u�W�F�N�g��T��
    int Count = pCharge->GetCount();    //���f���ԍ����擾

    ///////////////�����蔻��///////////////////

    RayCastData data[MAX_RAY_SIZE];                 //�Ē�`
    StageRayCast(data);                             //���C���������Ă��邩���ׂ�

    /*static const char* fileName = "test.txt";
    static std::ofstream ofs(fileName);*/

   

    if (status == 0)
    {

        if (Input::IsKeyDown(DIK_Q))
        {
            status++;
            InitializeFlag = true;
            transform_.position_.x = 900;//48
            transform_.position_.y = 150;
            transform_.position_.z = 900;

            transform_.rotate_ = (XMFLOAT3(0, 0, 0));
        }

        /////////////�L�[�{�[�h����///////////////////

        //�`���[�W�����܂��Ă������
        if (Input::IsKeyDown(DIK_SPACE))
        {
            ChargeAcceleration();
            OneFpsMoveList_.push_back(ChargeSpeed);         //List�ɓ������L�^���̂���
        }

        //��������
        if (Input::IsKey(DIK_LSHIFT))
        {
            Acceleration();
            OneFpsMoveList_.push_back(AcceleRation);   //List�ɓ������L�^���̂���
        }
        else
            Deceleration();

        //�O�ɐi��
        MoveOn();

        ///////���[��////////

        //�G���Ă��Ȃ�����
        /*if (Input::IsKey(DIK_D) == NULL && Input::IsKey(DIK_A) == NULL)
        {
            InitialRolling();
        }*/

        //�E��]
        //if (Input::IsKey(DIK_D))
        //{
        //    RollingRight();
        //    OneFpsMoveList_.push_back(RollingR);   //List�ɓ������L�^���̂���
        //}

        ////����]
        //if (Input::IsKey(DIK_A))
        //{
        //    RollingLeft();
        //    OneFpsMoveList_.push_back(RollingL);  //List�ɓ������L�^���̂���
        //}

        //////////�s�b�`/////////
        ////���]
        //if (Input::IsKey(DIK_W))
        //{
        //    PitchingUp();
        //    OneFpsMoveList_.push_back(Up);     //List�ɓ������L�^���̂���
        //}
        ////����]
        //if (Input::IsKey(DIK_S))
        //{
        //    PitchingDown();
        //    OneFpsMoveList_.push_back(Down);  //List�ɓ������L�^���̂���
        //}

        /////////���[///////
        ////�E�ړ�
        //if (Input::IsKey(DIK_RIGHT))
        //{
        //    YawingRight();
        //}
        ////���ړ�
        //if (Input::IsKey(DIK_LEFT))
        //{
        //    YawingLeft();
        //}

        //////////�R���g���[���[///////////




        //�`���[�W�����܂��Ă������
            if (Input::GetPadTrrigerL() >= 1 && Count >= 8)
            {
                ChargeAcceleration();
                OneFpsMoveList_.push_back(ChargeSpeed);        //List�ɓ������L�^���̂���

                pCharge->SetCount(0);

                // ofs << ChargeSpeed << std::endl;
            }

            //��������
            if (Input::GetPadTrrigerR() >= 1)
            {
                Acceleration();
                OneFpsMoveList_.push_back(AcceleRation);  //List�ɓ������L�^���̂���

                //ofs << AcceleRation << std::endl;

            }
            else
                //Deceleration();

            //�O�ɐi��
            //MoveOn();

            ///////���[��////////

            //�G���Ă��Ȃ�����
            /*if (Input::IsKey(DIK_D) == NULL && Input::IsKey(DIK_A) == NULL)
            {
                InitialRolling();
            }*/


            ////�E��]
            //if (Input::IsKey(DIK_D))

            if (SPEED_Z != 0)
            {
                //�E��]
                if (Input::IsKey(DIK_D))
                {
                    RollingRight();
                    OneFpsMoveList_.push_back(RollingR);   //List�ɓ������L�^���̂���
                }

                ////�E��]
                //if (Input::GetPadStickL().x > 0)
                //{
                //    RollingRight();
                //    OneFpsMoveList_.push_back(RollingR);   //List�ɓ������L�^���̂���
                //}

                //����]
                if (Input::IsKey(DIK_A))
                {
                    RollingLeft();
                    OneFpsMoveList_.push_back(RollingL);  //List�ɓ������L�^���̂���

                   //ofs << RollingR << std::endl;
                }

                ////����]
                //if (Input::GetPadStickL().x < 0)
                //{
                //    RollingLeft();
                //    OneFpsMoveList_.push_back(RollingL);   //List�ɓ������L�^���̂���

                //    //ofs << RollingL << std::endl;
                //}
            }
            //�G���Ă��Ȃ�����
            if (SPEED_Z == 0)
            {
                InitialRolling();
            }
            ////////�s�b�`/////////
            //���]
            if (Input::IsKey(DIK_W))
            {
                PitchingUp();
                OneFpsMoveList_.push_back(Up);     //List�ɓ������L�^���̂���

                //ofs << Up << std::endl;
            }
            //����]
            if (Input::IsKey(DIK_S))
            {
                PitchingDown();
                OneFpsMoveList_.push_back(Down);  //List�ɓ������L�^���̂���

                //ofs << Down << std::endl;
            }

            ///////���[///////
            //�E�ړ�
            if (Input::IsKey(DIK_RIGHT))
            {
                YawingRight();
            }
            //���ړ�
            if (Input::IsKey(DIK_LEFT))
            {
                YawingLeft();
            }

            //ofs << "end" << std::endl;

            //////////�R���g���[���[///////////

            //�`���[�W�����܂��Ă������
            if (Input::GetPadTrrigerL() > 0 && Count >= 8)
            {
                ChargeAcceleration();
                
                OneFpsMoveList_.push_back(ChargeSpeed);        //List�ɓ������L�^���̂���

                pCharge->SetCount(0);
            }

            //��������
            if (Input::GetPadTrrigerR() > 0)
            {
                float PadL = Input::GetPadTrrigerR();
                Acceleration(PadL);
                OneFpsMoveList_.push_back(AcceleRation);  //List�ɓ������L�^���̂���
            }
            else
                Deceleration();

            //�O�ɐi��
            MoveOn();

            ///////���[��////////

            
            //�G���Ă��Ȃ�����
            if (Input::GetPadStickL().x > -0.3&& Input::GetPadStickL().x < 0.3)
            {
                InitialRolling();
            }
            if (SPEED_Z != 0)
            {
                //�E��]
                if (Input::GetPadStickL().x > 0)
                {
                    
                    float PadL = Input::GetPadStickL().x;
                    RollingRight(PadL);
                    
                    OneFpsMoveList_.push_back(RollingR);   //List�ɓ������L�^���̂���
                }

                //����]
                if (Input::GetPadStickL().x < 0)
                {
                    
                    float PadL = Input::GetPadStickL().x;
                    RollingLeft(PadL);
                    
                    OneFpsMoveList_.push_back(RollingL);   //List�ɓ������L�^���̂���
                }
                if (Input::GetPadStickL().x == 0)
                {
                    InitialRolling();
                }
            }
            ////////�s�b�`/////////
           //���]
            if (Input::GetPadStickL().y > 0)
            {
                float PadL = Input::GetPadStickL().y;
                PitchingUp(PadL);
                OneFpsMoveList_.push_back(Up);     //List�ɓ������L�^���̂���
            }
            //����]
            if (Input::GetPadStickL().y < 0)
            {
                float PadL = Input::GetPadStickL().y;
                PitchingDown(PadL);
                OneFpsMoveList_.push_back(Down);  //List�ɓ������L�^���̂���
            }

            ///////���[///////
            //�E�ړ�
            if (Input::GetPadStickR().x > 0)
            {
                YawingRight();
            }
            //���ړ�
            if (Input::GetPadStickR().x < 0)
            {
                YawingLeft();
            }

           // MoveList_.push_back(OneFpsMoveList_);      //1FPS�̍s����SFPS�̍s�����L�^���Ă���List�Ɋi�[
           // OneFpsMoveList_.clear();                   //1FPS�̍s���N���A

        }
        else if (status == 1)
        {
            SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
            if (pSceneManager->GetPlayVideo())
            {
                static const char* fileName = "test.txt";
                static std::ifstream ifs(fileName);

                std::string buf;

                while (!ifs.eof())
                {
                    std::getline(ifs, buf);
                    if (buf != "end")
                    {
                        int num = atoi(buf.c_str());
                        OneFpsMoveList_.push_back(num);
                        buf += buf + "\n";
                    }
                    else
                    {
                        MoveList_.push_back(OneFpsMoveList_);      //1FPS�̍s����SFPS�̍s�����L�^���Ă���List�Ɋi�[
                        OneFpsMoveList_.clear();                   //1FPS�̍s���N���A
                    }
                }
            }

            static auto counter = MoveList_.begin();   //List�̍ŏ��̍s������n�߂�

            //�`���[�W�����܂��Ă������
            if (Input::IsKeyDown(DIK_Q))
            {
                status = 0;
                SPEED_Z = 0;
                transform_.position_ = (XMFLOAT3(300, 50, 300));
                transform_.rotate_ = (XMFLOAT3(0, 0, 0));
            }

            //List�̍ŏ��̍s������n�߂�
            if (InitializeFlag)
            {
                counter = MoveList_.begin();
                InitializeFlag = false;
            }

            //�Ō�܂ł�������N���A
            if (counter == MoveList_.end())
                MoveList_.clear();

            //�Ō�܂ł܂킷
            if (counter != MoveList_.end())
            {
                int RL = 0;
                int LShift = 0;

                //�PFPS�ōs���Ă���s�������ׂčs��
                //MoveList_�̒���List�̒����ŏ�����Ō�܂ŉ�
                for (auto i = counter->begin(); i != counter->end(); i++)
                {
                    //�s���̔ԍ����Ƃɍs���s���𕪂���
                    switch (*i)
                    {
                    case ChargeSpeed:
                        if (Count >= 8)
                        {
                            ChargeAcceleration();
                            pCharge->SetCount(0);
                        }
                        break;

                    case AcceleRation:
                        Acceleration();
                        LShift++;
                        break;

                    case RollingR:
                        RollingRight();
                        RL++;
                        break;

                    case RollingL:
                        RollingLeft();
                        RL++;
                        break;

                    case Up:
                        PitchingUp();
                        break;

                    case Down:
                        PitchingDown();
                        break;

                    default:
                        break;
                    }
                }

                //�O�ɐi��
                MoveOn();

                //����̍s���������Ă��Ȃ�������
                if (RL == 0)
                    InitialRolling();
                if (LShift == 0)
                    Deceleration();

                //�s������i�߂�
                counter++;
            }

        }

        ////�J��������//////
        XMFLOAT3 camPos;
        XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
        XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
        XMMATRIX mRotateX4 = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));
        XMMATRIX mRotateZ1 = XMMatrixRotationZ(XMConvertToRadians(transform_.rotate_.z));
        XMVECTOR vCam = CAM_VEC;
        vCam = XMVector3TransformCoord(vCam, mRotateZ1);//vCam����
        vCam = XMVector3TransformCoord(vCam, mRotateX4);//vCam����
        vCam = XMVector3TransformCoord(vCam, mRotate);//vCam����

        vPos += vCam;
        XMStoreFloat3(&camPos, vPos);

        Camera::SetPosition(camPos);
        Camera::SetTarget(XMFLOAT3(transform_.position_.x, transform_.position_.y + 4, transform_.position_.z));

        if (Direct3D::GetCamera())
        {
            XMFLOAT3 camPos;
            XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
            XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
            XMMATRIX mRotateX4 = XMMatrixRotationX(XMConvertToRadians(-5));
            XMMATRIX mRotateZ1 = XMMatrixRotationZ(XMConvertToRadians(0));
            XMVECTOR vCam = XMVectorSet(0.0f, 800.0f, 0.0f, 0.0f);
            vCam = XMVector3TransformCoord(vCam, mRotateZ1);//vCam����
            vCam = XMVector3TransformCoord(vCam, mRotateX4);//vCam����
            vCam = XMVector3TransformCoord(vCam, mRotate);//vCam����

            vPos += vCam;
            XMStoreFloat3(&camPos, vPos);
            Direct3D::SetCameraPos(camPos);
        }
    
}

//�`��
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);

}

//�J��
void Player::Release()
{
}

////////////���c����֐�//////////////

//���[�@�E��]
void Player::RollingRight()
{
    transform_.rotate_.z -= 1.5;
    transform_.rotate_.y += ROTATE_SPEED * FunctionRotation();

    if (transform_.rotate_.z <= -(CHAR_ANGLE))
    {
        transform_.rotate_.z = -(CHAR_ANGLE);
    }

}

void Player::RollingRight(float PadL)
{
   
    if (Input::GetPadStickL().x > 0)
    {
        transform_.rotate_.z -= 1.5 * PadL;
        transform_.rotate_.y += ROTATE_SPEED * PadL;

        if (transform_.rotate_.z <= -(CHAR_ANGLE))
        {
            transform_.rotate_.z = -(CHAR_ANGLE);
        }
        
    }
    
}

//���[�@����]
void Player::RollingLeft()
{
    transform_.rotate_.z += 1.5f;//���@�̌X��
    transform_.rotate_.y -= ROTATE_SPEED * FunctionRotation();//���@�̉�]
    if (transform_.rotate_.z >= CHAR_ANGLE)
    {
        transform_.rotate_.z = CHAR_ANGLE;
    }
}

void Player::RollingLeft(float PadL)
{
    if (Input::GetPadStickL().x < 0)
    {
        transform_.rotate_.z += 1.5 * -PadL;//���@�̌X��
        transform_.rotate_.y -= ROTATE_SPEED * -PadL;//���@�̉�]
        if (transform_.rotate_.z >= CHAR_ANGLE)
        {
            transform_.rotate_.z = CHAR_ANGLE;
        }
    }
    
}



//�s�b�`�@���]
void Player::PitchingUp()
{
    transform_.rotate_.x -= move ;
    if (transform_.rotate_.x <= -(Limit))
    {
        transform_.rotate_.x = -(Limit);
    }
}

void Player::PitchingUp(float PadL)
{
        transform_.rotate_.x -= move * PadL;
        if (transform_.rotate_.x <= -(Limit))
        {
            transform_.rotate_.x = -(Limit);
        }
}



//�s�b�`�@����]
void Player::PitchingDown()
{
    transform_.rotate_.x += move;
    if (transform_.rotate_.x >= Limit-20)
    {
        transform_.rotate_.x = Limit-20;
    }
}

void Player::PitchingDown(float PadL)
{
    transform_.rotate_.x += move * -PadL;
    if (transform_.rotate_.x >= Limit - 20)
    {
        transform_.rotate_.x = Limit - 20;
    }
}

//���[�@�@���ړ��i�E
void Player::YawingRight()
{
    //XMVECTOR vPos = XMLoadFloat3(&transform_.position_); 
    //XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));   //������Y������]������s������
    //XMMATRIX mRotateX = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));  //������X������]������s������
    //XMMATRIX mRotateZ = XMMatrixRotationZ(XMConvertToRadians(transform_.rotate_.z));  //������Z������]������s������
    //XMFLOAT3 move = { SPEED_S,0,0 };
    //XMVECTOR vMove = XMLoadFloat3(&move);
    //vMove = XMVector3TransformCoord(vMove, mRotateZ);
    //vMove = XMVector3TransformCoord(vMove, mRotateX);                                 
    //vMove = XMVector3TransformCoord(vMove, mRotate);
    //vPos += vMove;                                                                   
    //XMStoreFloat3(&transform_.position_, vPos);
    transform_.rotate_.y += ROTATE_SPEED * FunctionRotation();
}

//���[�@�@���ړ��i��
void Player::YawingLeft()
{
    //XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
    //XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));   //������Y������]������s������
    //XMMATRIX mRotateX = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));  //������X������]������s������
    //XMMATRIX mRotateZ = XMMatrixRotationZ(XMConvertToRadians(transform_.rotate_.z));  //������Z������]������s������
    //XMFLOAT3 move = { -SPEED_S,0,0 };
    //XMVECTOR vMove = XMLoadFloat3(&move);
    //vMove = XMVector3TransformCoord(vMove, mRotateZ);
    //vMove = XMVector3TransformCoord(vMove, mRotateX);                                 
    //vMove = XMVector3TransformCoord(vMove, mRotate);
    //vPos += vMove;                                                                  
    //XMStoreFloat3(&transform_.position_, vPos);
    transform_.rotate_.y -= ROTATE_SPEED * FunctionRotation();
}

//���[�@�����̈ʒu�ɖ߂�
void Player::InitialRolling()
{
    if (transform_.rotate_.z <= 0)
    {
        transform_.rotate_.z += 3.0;
        if (transform_.rotate_.z >= 0)
        {
            transform_.rotate_.z = 0;
        }
    }
   
    if (transform_.rotate_.z >= 0)
    {
        transform_.rotate_.z -= 3.0;
        if (transform_.rotate_.z <= 0)
        {
            transform_.rotate_.z = 0;
        }
    }
}

//�O�ɐi��
void Player::MoveOn()
{
    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);                             //�����̃|�W�V�����̃x�N�g��
    XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));  //������Y������]������s������
    XMMATRIX mRotateX = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x)); //������X������]������s������
    XMMATRIX mRotateZ = XMMatrixRotationZ(XMConvertToRadians(transform_.rotate_.z)); //������Z������]������s������
    XMFLOAT3 move = { 0,0,SPEED_Z };                                                 //�������l
    XMVECTOR vMove = XMLoadFloat3(&move);                                            //move�̃x�N�g��
    
    vMove = XMVector3TransformCoord(vMove, mRotateZ);                                //VMove�̃x�N�g����mRotate�Ɠ��������ɂ���
    vMove = XMVector3TransformCoord(vMove, mRotateX);                                //VMove�̃x�N�g����mRotate�Ɠ��������ɂ���
    vMove = XMVector3TransformCoord(vMove, mRotate);                                 //VMove�̃x�N�g����mRotate�Ɠ��������ɂ���
   
    vPos += vMove;                                                                   //�����̃|�W�V�����̃x�N�g����vMove�̃x�N�g��������
    XMStoreFloat3(&transform_.position_, vPos);                                      //�ړ���̃x�N�g���������̃|�W�V�����ɑ��
   
}

void Player::Acceleration()
{
    if (SPEED_Z < MAX_SPEED)                    //�ō����x��肵���Ȃ�
        SPEED_Z += ACCELERATION_DECELERATION;   //��������
    else if (SPEED_Z > MAX_SPEED)               //�`���[�W�ő����Ȃ���������X�ɍō����x�܂ŗ��Ƃ��Ă���   
        SPEED_Z -= ACCELERATION_DECELERATION;   //����
    else
        SPEED_Z = MAX_SPEED;                    //�ō����x����Ȃ�
}

void Player::Acceleration(float PadL)
{
    if (SPEED_Z < MAX_SPEED)                    //�ō����x��肵���Ȃ�
        SPEED_Z += ACCELERATION_DECELERATION * PadL;   //��������
    else if (SPEED_Z > MAX_SPEED)               //�`���[�W�ő����Ȃ���������X�ɍō����x�܂ŗ��Ƃ��Ă���   
        SPEED_Z -= ACCELERATION_DECELERATION * PadL;   //����
    else
        SPEED_Z = MAX_SPEED;                    //�ō����x����Ȃ�
}

void Player::Deceleration()
{
    if (SPEED_Z > LOWEST_SPEED)                 //�Œᑬ�x����Ȃ�
        SPEED_Z -= ACCELERATION_DECELERATION;   //����
    else
        SPEED_Z = LOWEST_SPEED;                 //�Œᑬ�x��艺�Ȃ�
}

void Player::ChargeAcceleration()
{
    SPEED_Z = CHARGE_ACCELERATION;              //��
}

//��]
float Player::FunctionRotation()
{

    float Roll = 0;
    if (transform_.rotate_.z >= 0)
    {
        Roll = ((transform_.rotate_.z) / CHAR_ANGLE) + 1.0;
        return Roll;
    }
    else if (transform_.rotate_.z <= 0)
    {
        Roll = ( -(transform_.rotate_.z) / CHAR_ANGLE) + 1.0;
        return Roll;
    }
    
}

void Player::AccelerationBehavior()
{
    transform_.rotate_.x -= 0.2;
}

void Player::DecelerationBehavior()
{
}



////////////���C//////////////

//�X�e�[�W�Ƃ̓����蔻��
void Player::StageRayCast(RayCastData *data)
{

    //////���C//////
    Stage* pStage = (Stage*)FindObject("Stage");    //�X�e�[�W�I�u�W�F�N�g��T��
    int hGroundModel = pStage->GetModelHandle();    //���f���ԍ����擾
    int hGroundModel2 = pStage->GetModelHandle2();

    //////////////////////////////���C����//////////////////////////////////////

    //�E
    data[Right].start = transform_.position_;       //���C�̔��ˈʒu
    XMFLOAT3 moveX = { 1,0,0 };                     //�������l
    data[Right].dir = moveX;
    Model::RayCast(hGroundModel2, &data[Right]);     //���C�𔭎�

    //��
    data[Left].start = transform_.position_;        //���C�̔��ˈʒu
    XMFLOAT3 moveX2 = { -1,0,0 };                   //�������l
    data[Left].dir = moveX2;
    Model::RayCast(hGroundModel2, &data[Left]);      //���C�𔭎�

    //�O
    data[Straight].start = transform_.position_;    //���C�̔��ˈʒu
    XMFLOAT3 moveZ = { 0,0,1 };                     //�������l
    data[Straight].dir = moveZ;
    Model::RayCast(hGroundModel2, &data[Straight]);  //���C�𔭎�s

    //��
    data[Back].start = transform_.position_;        //���C�̔��ˈʒu
    XMFLOAT3 moveZ2 = { 0,0,-1 };                   //�������l
    data[Back].dir = moveZ2;
    Model::RayCast(hGroundModel2, &data[Back]);      //���C�𔭎�

    //��
    data[Top].start = transform_.position_;        //���C�̔��ˈʒu
    XMFLOAT3 moveY = { 0,1,0 };                   //�������l
    data[Top].dir = moveY;
    Model::RayCast(hGroundModel, &data[Top]);      //���C�𔭎�

    //��
    data[Under].start = transform_.position_;        //���C�̔��ˈʒu
    XMFLOAT3 moveY2 = { 0,-1,0 };                   //�������l
    data[Under].dir = moveY2;
    Model::RayCast(hGroundModel, &data[Under]);      //���C�𔭎�

    //////////////////////////////�͂ݏo������������//////////////////////////////////////

    if (data[Right].dist <= 3)
    {
        transform_.position_.x -= 3 - data[Right].dist;
    }
    if (data[Left].dist <= 3)
    {
        transform_.position_.x += 3 - data[Left].dist;
    }
    if (data[Straight].dist <= 3)
    {
        transform_.position_.z -= 3 - data[Straight].dist;
    }
    if (data[Back].dist <= 3)
    {
        transform_.position_.z += 3 - data[Back].dist;
    }
    if (data[Top].dist <= 3)
    {
        transform_.position_.y -= 3 - data[Top].dist;
    }
    if (data[Under].dist <= 3)
    {
        transform_.position_.y += 3 - data[Under].dist;
    }
    
}

