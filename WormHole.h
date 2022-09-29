#pragma once
#include"Engine/GameObject.h"

class WormHole : public GameObject
{
    int hModel_;
    XMFLOAT3 end_;
public:
    //コンストラクタ
 //引数：parent  親オブジェクト（PlayScene）
    WormHole(GameObject* parent);

    //デストラクタ
    ~WormHole();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //衝突
    void OnCollision(GameObject* target) override;
    void SetStart_To_End(XMFLOAT3 start, XMFLOAT3 end);
};

