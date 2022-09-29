#pragma once
#include"../Engine/GameObject.h"
#include"MoonStone.h"
class CreateMoonStone : public GameObject
{
    MoonStone* pMoon_[3];
public:
    //コンストラクタ
   //引数：parent  親オブジェクト（PlayScene）
    CreateMoonStone(GameObject* parent);

    //デストラクタ
    ~CreateMoonStone();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

