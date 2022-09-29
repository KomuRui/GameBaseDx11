#pragma once
#include"Engine/GameObject.h"
#include "Meteorite.h"
class CreateMeteorite : public GameObject
{
    Meteorite* p_;

public:
    //コンストラクタ
   //引数：parent  親オブジェクト（PlayScene）
    CreateMeteorite(GameObject* parent);

    //デストラクタ
    ~CreateMeteorite();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;     
};

