#pragma once
#include"../Engine/GameObject.h"
#include"FirePillar.h"
class CreateFirePillar : public GameObject
{
    FirePillar* pFire_[3];

public:
    //コンストラクタ
   //引数：parent  親オブジェクト（PlayScene）
    CreateFirePillar(GameObject* parent);

    //デストラクタ
    ~CreateFirePillar();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

