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

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), 

    ///////////////////モデル///////////////////////

    hModel_(-1), 

    ///////////////////プレイヤ///////////////////////

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

    ///////////////////カメラ///////////////////////

    CAM_VEC(XMVectorSet(0.0f, 8.0f, -25.0f, 0.0f)),

    ///////////////////当たり判定///////////////////////

    pStage(nullptr),
    
    status(0),
    InitializeFlag(false),
    PlayVideos(false)

{
}

//デストラクタ
Player::~Player()
{
}

//初期化
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
    


    ///////////////画像データのロード///////////////////
    hModel_ = Model::Load("EarthScene/Model/craft.fbx");
    assert(hModel_ >= 0);

    //コライダー
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 0), XMFLOAT3(3, 3, 3),true);
    AddCollider(collision);
    //Instantiate<Emitter>(this);

}

//更新
void Player::Update()
{             
    
    Charge* pCharge = (Charge*)FindObject("Charge");    //ステージオブジェクトを探す
    int Count = pCharge->GetCount();    //モデル番号を取得

    ///////////////当たり判定///////////////////

    RayCastData data[MAX_RAY_SIZE];                 //再定義
    StageRayCast(data);                             //レイが当たっているか調べる

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

        /////////////キーボード操作///////////////////

        //チャージがたまってたら加速
        if (Input::IsKeyDown(DIK_SPACE))
        {
            ChargeAcceleration();
            OneFpsMoveList_.push_back(ChargeSpeed);         //Listに動いた記録をのせる
        }

        //加速減速
        if (Input::IsKey(DIK_LSHIFT))
        {
            Acceleration();
            OneFpsMoveList_.push_back(AcceleRation);   //Listに動いた記録をのせる
        }
        else
            Deceleration();

        //前に進む
        MoveOn();

        ///////ロール////////

        //触っていない処理
        /*if (Input::IsKey(DIK_D) == NULL && Input::IsKey(DIK_A) == NULL)
        {
            InitialRolling();
        }*/

        //右回転
        //if (Input::IsKey(DIK_D))
        //{
        //    RollingRight();
        //    OneFpsMoveList_.push_back(RollingR);   //Listに動いた記録をのせる
        //}

        ////左回転
        //if (Input::IsKey(DIK_A))
        //{
        //    RollingLeft();
        //    OneFpsMoveList_.push_back(RollingL);  //Listに動いた記録をのせる
        //}

        //////////ピッチ/////////
        ////上回転
        //if (Input::IsKey(DIK_W))
        //{
        //    PitchingUp();
        //    OneFpsMoveList_.push_back(Up);     //Listに動いた記録をのせる
        //}
        ////下回転
        //if (Input::IsKey(DIK_S))
        //{
        //    PitchingDown();
        //    OneFpsMoveList_.push_back(Down);  //Listに動いた記録をのせる
        //}

        /////////ヨー///////
        ////右移動
        //if (Input::IsKey(DIK_RIGHT))
        //{
        //    YawingRight();
        //}
        ////左移動
        //if (Input::IsKey(DIK_LEFT))
        //{
        //    YawingLeft();
        //}

        //////////コントローラー///////////




        //チャージがたまってたら加速
            if (Input::GetPadTrrigerL() >= 1 && Count >= 8)
            {
                ChargeAcceleration();
                OneFpsMoveList_.push_back(ChargeSpeed);        //Listに動いた記録をのせる

                pCharge->SetCount(0);

                // ofs << ChargeSpeed << std::endl;
            }

            //加速減速
            if (Input::GetPadTrrigerR() >= 1)
            {
                Acceleration();
                OneFpsMoveList_.push_back(AcceleRation);  //Listに動いた記録をのせる

                //ofs << AcceleRation << std::endl;

            }
            else
                //Deceleration();

            //前に進む
            //MoveOn();

            ///////ロール////////

            //触っていない処理
            /*if (Input::IsKey(DIK_D) == NULL && Input::IsKey(DIK_A) == NULL)
            {
                InitialRolling();
            }*/


            ////右回転
            //if (Input::IsKey(DIK_D))

            if (SPEED_Z != 0)
            {
                //右回転
                if (Input::IsKey(DIK_D))
                {
                    RollingRight();
                    OneFpsMoveList_.push_back(RollingR);   //Listに動いた記録をのせる
                }

                ////右回転
                //if (Input::GetPadStickL().x > 0)
                //{
                //    RollingRight();
                //    OneFpsMoveList_.push_back(RollingR);   //Listに動いた記録をのせる
                //}

                //左回転
                if (Input::IsKey(DIK_A))
                {
                    RollingLeft();
                    OneFpsMoveList_.push_back(RollingL);  //Listに動いた記録をのせる

                   //ofs << RollingR << std::endl;
                }

                ////左回転
                //if (Input::GetPadStickL().x < 0)
                //{
                //    RollingLeft();
                //    OneFpsMoveList_.push_back(RollingL);   //Listに動いた記録をのせる

                //    //ofs << RollingL << std::endl;
                //}
            }
            //触っていない処理
            if (SPEED_Z == 0)
            {
                InitialRolling();
            }
            ////////ピッチ/////////
            //上回転
            if (Input::IsKey(DIK_W))
            {
                PitchingUp();
                OneFpsMoveList_.push_back(Up);     //Listに動いた記録をのせる

                //ofs << Up << std::endl;
            }
            //下回転
            if (Input::IsKey(DIK_S))
            {
                PitchingDown();
                OneFpsMoveList_.push_back(Down);  //Listに動いた記録をのせる

                //ofs << Down << std::endl;
            }

            ///////ヨー///////
            //右移動
            if (Input::IsKey(DIK_RIGHT))
            {
                YawingRight();
            }
            //左移動
            if (Input::IsKey(DIK_LEFT))
            {
                YawingLeft();
            }

            //ofs << "end" << std::endl;

            //////////コントローラー///////////

            //チャージがたまってたら加速
            if (Input::GetPadTrrigerL() > 0 && Count >= 8)
            {
                ChargeAcceleration();
                
                OneFpsMoveList_.push_back(ChargeSpeed);        //Listに動いた記録をのせる

                pCharge->SetCount(0);
            }

            //加速減速
            if (Input::GetPadTrrigerR() > 0)
            {
                float PadL = Input::GetPadTrrigerR();
                Acceleration(PadL);
                OneFpsMoveList_.push_back(AcceleRation);  //Listに動いた記録をのせる
            }
            else
                Deceleration();

            //前に進む
            MoveOn();

            ///////ロール////////

            
            //触っていない処理
            if (Input::GetPadStickL().x > -0.3&& Input::GetPadStickL().x < 0.3)
            {
                InitialRolling();
            }
            if (SPEED_Z != 0)
            {
                //右回転
                if (Input::GetPadStickL().x > 0)
                {
                    
                    float PadL = Input::GetPadStickL().x;
                    RollingRight(PadL);
                    
                    OneFpsMoveList_.push_back(RollingR);   //Listに動いた記録をのせる
                }

                //左回転
                if (Input::GetPadStickL().x < 0)
                {
                    
                    float PadL = Input::GetPadStickL().x;
                    RollingLeft(PadL);
                    
                    OneFpsMoveList_.push_back(RollingL);   //Listに動いた記録をのせる
                }
                if (Input::GetPadStickL().x == 0)
                {
                    InitialRolling();
                }
            }
            ////////ピッチ/////////
           //上回転
            if (Input::GetPadStickL().y > 0)
            {
                float PadL = Input::GetPadStickL().y;
                PitchingUp(PadL);
                OneFpsMoveList_.push_back(Up);     //Listに動いた記録をのせる
            }
            //下回転
            if (Input::GetPadStickL().y < 0)
            {
                float PadL = Input::GetPadStickL().y;
                PitchingDown(PadL);
                OneFpsMoveList_.push_back(Down);  //Listに動いた記録をのせる
            }

            ///////ヨー///////
            //右移動
            if (Input::GetPadStickR().x > 0)
            {
                YawingRight();
            }
            //左移動
            if (Input::GetPadStickR().x < 0)
            {
                YawingLeft();
            }

           // MoveList_.push_back(OneFpsMoveList_);      //1FPSの行動を全FPSの行動を記録しているListに格納
           // OneFpsMoveList_.clear();                   //1FPSの行動クリア

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
                        MoveList_.push_back(OneFpsMoveList_);      //1FPSの行動を全FPSの行動を記録しているListに格納
                        OneFpsMoveList_.clear();                   //1FPSの行動クリア
                    }
                }
            }

            static auto counter = MoveList_.begin();   //Listの最初の行動から始める

            //チャージがたまってたら加速
            if (Input::IsKeyDown(DIK_Q))
            {
                status = 0;
                SPEED_Z = 0;
                transform_.position_ = (XMFLOAT3(300, 50, 300));
                transform_.rotate_ = (XMFLOAT3(0, 0, 0));
            }

            //Listの最初の行動から始める
            if (InitializeFlag)
            {
                counter = MoveList_.begin();
                InitializeFlag = false;
            }

            //最後までいったらクリア
            if (counter == MoveList_.end())
                MoveList_.clear();

            //最後までまわす
            if (counter != MoveList_.end())
            {
                int RL = 0;
                int LShift = 0;

                //１FPSで行っている行動をすべて行う
                //MoveList_の中のListの中を最初から最後まで回す
                for (auto i = counter->begin(); i != counter->end(); i++)
                {
                    //行動の番号ごとに行う行動を分ける
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

                //前に進む
                MoveOn();

                //特定の行動を押していなかったら
                if (RL == 0)
                    InitialRolling();
                if (LShift == 0)
                    Deceleration();

                //行動を一つ進める
                counter++;
            }

        }

        ////カメラ処理//////
        XMFLOAT3 camPos;
        XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
        XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
        XMMATRIX mRotateX4 = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));
        XMMATRIX mRotateZ1 = XMMatrixRotationZ(XMConvertToRadians(transform_.rotate_.z));
        XMVECTOR vCam = CAM_VEC;
        vCam = XMVector3TransformCoord(vCam, mRotateZ1);//vCamを回す
        vCam = XMVector3TransformCoord(vCam, mRotateX4);//vCamを回す
        vCam = XMVector3TransformCoord(vCam, mRotate);//vCamを回す

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
            vCam = XMVector3TransformCoord(vCam, mRotateZ1);//vCamを回す
            vCam = XMVector3TransformCoord(vCam, mRotateX4);//vCamを回す
            vCam = XMVector3TransformCoord(vCam, mRotate);//vCamを回す

            vPos += vCam;
            XMStoreFloat3(&camPos, vPos);
            Direct3D::SetCameraPos(camPos);
        }
    
}

//描画
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);

}

//開放
void Player::Release()
{
}

////////////操縦操作関数//////////////

//ロー　右回転
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

//ロー　左回転
void Player::RollingLeft()
{
    transform_.rotate_.z += 1.5f;//自機の傾き
    transform_.rotate_.y -= ROTATE_SPEED * FunctionRotation();//自機の回転
    if (transform_.rotate_.z >= CHAR_ANGLE)
    {
        transform_.rotate_.z = CHAR_ANGLE;
    }
}

void Player::RollingLeft(float PadL)
{
    if (Input::GetPadStickL().x < 0)
    {
        transform_.rotate_.z += 1.5 * -PadL;//自機の傾き
        transform_.rotate_.y -= ROTATE_SPEED * -PadL;//自機の回転
        if (transform_.rotate_.z >= CHAR_ANGLE)
        {
            transform_.rotate_.z = CHAR_ANGLE;
        }
    }
    
}



//ピッチ　上回転
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



//ピッチ　下回転
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

//ヨー　　横移動（右
void Player::YawingRight()
{
    //XMVECTOR vPos = XMLoadFloat3(&transform_.position_); 
    //XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));   //自分のY軸分回転させる行列を作る
    //XMMATRIX mRotateX = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));  //自分のX軸分回転させる行列を作る
    //XMMATRIX mRotateZ = XMMatrixRotationZ(XMConvertToRadians(transform_.rotate_.z));  //自分のZ軸分回転させる行列を作る
    //XMFLOAT3 move = { SPEED_S,0,0 };
    //XMVECTOR vMove = XMLoadFloat3(&move);
    //vMove = XMVector3TransformCoord(vMove, mRotateZ);
    //vMove = XMVector3TransformCoord(vMove, mRotateX);                                 
    //vMove = XMVector3TransformCoord(vMove, mRotate);
    //vPos += vMove;                                                                   
    //XMStoreFloat3(&transform_.position_, vPos);
    transform_.rotate_.y += ROTATE_SPEED * FunctionRotation();
}

//ヨー　　横移動（左
void Player::YawingLeft()
{
    //XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
    //XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));   //自分のY軸分回転させる行列を作る
    //XMMATRIX mRotateX = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));  //自分のX軸分回転させる行列を作る
    //XMMATRIX mRotateZ = XMMatrixRotationZ(XMConvertToRadians(transform_.rotate_.z));  //自分のZ軸分回転させる行列を作る
    //XMFLOAT3 move = { -SPEED_S,0,0 };
    //XMVECTOR vMove = XMLoadFloat3(&move);
    //vMove = XMVector3TransformCoord(vMove, mRotateZ);
    //vMove = XMVector3TransformCoord(vMove, mRotateX);                                 
    //vMove = XMVector3TransformCoord(vMove, mRotate);
    //vPos += vMove;                                                                  
    //XMStoreFloat3(&transform_.position_, vPos);
    transform_.rotate_.y -= ROTATE_SPEED * FunctionRotation();
}

//ロー　初期の位置に戻る
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

//前に進む
void Player::MoveOn()
{
    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);                             //自分のポジションのベクトル
    XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));  //自分のY軸分回転させる行列を作る
    XMMATRIX mRotateX = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x)); //自分のX軸分回転させる行列を作る
    XMMATRIX mRotateZ = XMMatrixRotationZ(XMConvertToRadians(transform_.rotate_.z)); //自分のZ軸分回転させる行列を作る
    XMFLOAT3 move = { 0,0,SPEED_Z };                                                 //動かす値
    XMVECTOR vMove = XMLoadFloat3(&move);                                            //moveのベクトル
    
    vMove = XMVector3TransformCoord(vMove, mRotateZ);                                //VMoveのベクトルをmRotateと同じ向きにする
    vMove = XMVector3TransformCoord(vMove, mRotateX);                                //VMoveのベクトルをmRotateと同じ向きにする
    vMove = XMVector3TransformCoord(vMove, mRotate);                                 //VMoveのベクトルをmRotateと同じ向きにする
   
    vPos += vMove;                                                                   //自分のポジションのベクトルにvMoveのベクトルをたす
    XMStoreFloat3(&transform_.position_, vPos);                                      //移動後のベクトルを自分のポジションに代入
   
}

void Player::Acceleration()
{
    if (SPEED_Z < MAX_SPEED)                    //最高速度よりしたなら
        SPEED_Z += ACCELERATION_DECELERATION;   //加速する
    else if (SPEED_Z > MAX_SPEED)               //チャージで早くなったやつを徐々に最高速度まで落としていく   
        SPEED_Z -= ACCELERATION_DECELERATION;   //減速
    else
        SPEED_Z = MAX_SPEED;                    //最高速度より上なら
}

void Player::Acceleration(float PadL)
{
    if (SPEED_Z < MAX_SPEED)                    //最高速度よりしたなら
        SPEED_Z += ACCELERATION_DECELERATION * PadL;   //加速する
    else if (SPEED_Z > MAX_SPEED)               //チャージで早くなったやつを徐々に最高速度まで落としていく   
        SPEED_Z -= ACCELERATION_DECELERATION * PadL;   //減速
    else
        SPEED_Z = MAX_SPEED;                    //最高速度より上なら
}

void Player::Deceleration()
{
    if (SPEED_Z > LOWEST_SPEED)                 //最低速度より上なら
        SPEED_Z -= ACCELERATION_DECELERATION;   //減速
    else
        SPEED_Z = LOWEST_SPEED;                 //最低速度より下なら
}

void Player::ChargeAcceleration()
{
    SPEED_Z = CHARGE_ACCELERATION;              //仮
}

//回転
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



////////////レイ//////////////

//ステージとの当たり判定
void Player::StageRayCast(RayCastData *data)
{

    //////レイ//////
    Stage* pStage = (Stage*)FindObject("Stage");    //ステージオブジェクトを探す
    int hGroundModel = pStage->GetModelHandle();    //モデル番号を取得
    int hGroundModel2 = pStage->GetModelHandle2();

    //////////////////////////////レイ発射//////////////////////////////////////

    //右
    data[Right].start = transform_.position_;       //レイの発射位置
    XMFLOAT3 moveX = { 1,0,0 };                     //動かす値
    data[Right].dir = moveX;
    Model::RayCast(hGroundModel2, &data[Right]);     //レイを発射

    //左
    data[Left].start = transform_.position_;        //レイの発射位置
    XMFLOAT3 moveX2 = { -1,0,0 };                   //動かす値
    data[Left].dir = moveX2;
    Model::RayCast(hGroundModel2, &data[Left]);      //レイを発射

    //前
    data[Straight].start = transform_.position_;    //レイの発射位置
    XMFLOAT3 moveZ = { 0,0,1 };                     //動かす値
    data[Straight].dir = moveZ;
    Model::RayCast(hGroundModel2, &data[Straight]);  //レイを発射s

    //後
    data[Back].start = transform_.position_;        //レイの発射位置
    XMFLOAT3 moveZ2 = { 0,0,-1 };                   //動かす値
    data[Back].dir = moveZ2;
    Model::RayCast(hGroundModel2, &data[Back]);      //レイを発射

    //上
    data[Top].start = transform_.position_;        //レイの発射位置
    XMFLOAT3 moveY = { 0,1,0 };                   //動かす値
    data[Top].dir = moveY;
    Model::RayCast(hGroundModel, &data[Top]);      //レイを発射

    //下
    data[Under].start = transform_.position_;        //レイの発射位置
    XMFLOAT3 moveY2 = { 0,-1,0 };                   //動かす値
    data[Under].dir = moveY2;
    Model::RayCast(hGroundModel, &data[Under]);      //レイを発射

    //////////////////////////////はみ出した分下げる//////////////////////////////////////

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

