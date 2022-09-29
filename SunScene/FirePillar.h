#pragma once
#include"../Engine/GameObject.h"
class FirePillar : public GameObject
{
    int hModel_;
    std::string modelNamePath_;
    float eruption_;
    const float ERUPTION_SPEED;
    const float PILLAR_SIZE;

public:
    //コンストラクタ
   //引数：parent  親オブジェクト（PlayScene）
    FirePillar(GameObject* parent);

    //デストラクタ
    ~FirePillar();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //モデルセット
    void SetFirePillar(std::string modelNamePath, float posX, float posY, float posZ);
    void SetFirePillar(std::string modelNamePath, XMFLOAT3 position,XMFLOAT3 angle);
};

