#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"
#include "Stage.h"
#include <list>

//◆◆◆を管理するクラス
class Player : public GameObject
{

    ///////////////////モデル///////////////////////

    int hModel_;               //モデル番号

    ///////////////////Player///////////////////////

    const float ROTATE_SPEED;               //キャラの回転速度
          float SPEED_Z;                    //キャラの前に進むのスピード
    const float SPEED_S;                    //キャラのよこに進むのスピード
    const float CHAR_ANGLE;                 //回る最大角度
    const float Limit;                      //ピッチの限界値
    const float move;                       //キャラの上下の向き
    const float MAX_SPEED;                  //最高速度
    const float LOWEST_SPEED;               //最低速度
    const float ACCELERATION_DECELERATION;  //加速減速
    const float CHARGE_ACCELERATION;        //チャージで加速した最高速度
    const XMFLOAT3 rpos;

    ///////////////////カメラ///////////////////////

    const XMVECTOR CAM_VEC;    //カメラのポジション
          XMFLOAT3 CAM_COLL;   //カメラのコリジョン  

    /////////////////当たり判定/////////////////////

    Stage* pStage;                  //ステージのモデル番号入れる

    enum StageRayDecision           //各方向への当たり判定するために列挙する
    {
        Straight = 0,               //前
        Back,                       //後
        Left,                       //左
        Right,                      //右
        Under,                      //下
        Top,                        //上
        MAX_RAY_SIZE
    };
   
    /////////////////再生機能/////////////////////

    bool PlayVideos;
    bool InitializeFlag;                      //再生機能を行うときに必要なフラグ
    int status;                               //状態(０なら操作,1なら再生)
    std::list<std::list<int>>	MoveList_;    //捜査している状態の時の全FPSの行動を入れるList
    std::list<int>	OneFpsMoveList_;          //1FPSの行動をいれるList

    enum Function                             //プレイヤを操作するための関数ごとに列挙
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
    //コンストラクタ
    //引数：parent  親オブジェクト（PlayScene）
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    
    ////////////操縦操作関数//////////////
    
    //ロー　右回転
    void RollingRight();

    //ロー　右回転 コントローラー
    void RollingRight(float PadL);

    //ロー　左回転
    void RollingLeft();

    //ロー　左回転 コントローラー
    void RollingLeft(float PadL);

    //ピッチ　上回転
    void PitchingUp();

    //ピッチ　上回転 コントローラー
    void PitchingUp(float PadL);

    //ピッチ　下回転
    void PitchingDown();

    //ピッチ　下回転 コントローラー
    void PitchingDown(float PadL);

    //ヨー　　横移動（右
    void YawingRight();

    //ヨー　　横移動（左
    void YawingLeft();

    //ロー　初期の位置に戻る
    void InitialRolling();

    //前に進む
    void MoveOn();

    //加速
    void Acceleration();

    void Acceleration(float PadL);

    //減速
    void Deceleration();

    //チャージ加速
    void ChargeAcceleration();

    //回転の関数
    float  FunctionRotation();

    //加速時の挙動
    void AccelerationBehavior();

    //減速時の挙動
    void DecelerationBehavior();

    ////////////レイ//////////////

    //ステージとの当たり判定
    void StageRayCast(RayCastData* data);

    //セット
    void SetPlayVideo(bool flag) { PlayVideos = flag; }
    void SetStatus(int num) { status = num; }
};