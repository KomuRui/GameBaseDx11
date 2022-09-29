#pragma once
#include "Engine/GameObject.h"
#include "Engine/Time.h"
#include "Engine/SceneManager.h"

//◆◆◆を管理するクラス
class Stage : public GameObject
{
    int hPict_;                    //画像番号
    int hModel_;                   //モデル番号
    int hModel_wall;
    int hModel_space;

    SceneManager* pSceneManager;
    
    Time* timeConter_;         //タイムの表示

    int hPict_2;               //画像番号

    Transform spa;
     
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（PlayScene）
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //ステージのモデル番号を返してあげる
    int GetModelHandle() { return hModel_; }

    //ステージのモデル番号を返してあげる
    int GetModelHandle2() { return hModel_wall; }

};