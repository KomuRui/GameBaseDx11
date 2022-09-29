#pragma once
#include"Engine/GameObject.h"
#include"CreateHole.h"
#include"WormHole.h"
class CreateHole : public GameObject
{
    WormHole* p_;
public:
    //コンストラクタ
 //引数：parent  親オブジェクト（PlayScene）
    CreateHole(GameObject* parent);

    //デストラクタ
    ~CreateHole();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

