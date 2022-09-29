#pragma once
#include"../Engine/GameObject.h"
class MoonStone : public GameObject
{
    int hModel_;
    std::string modelNamePath_;
    float basePos_;
    float floating_;
    float floatHeight_;
    const float FLOAT_LIMIT;
    const float FLOAT_SPEED;
    const float FLOAT_INTERVAL;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（PlayScene）
    MoonStone(GameObject* parent);

    //デストラクタ
    ~MoonStone();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
    void SetMoonStone(std::string modelNamePath, float posX, float posY, float posZ);
};

