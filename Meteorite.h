#pragma once
#include "Engine/GameObject.h"
#include "Stage.h"
class Meteorite : public GameObject
{
    int hModel_;
    float ROTATE_SPEED;
    std::string modelNamePath_;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（PlayScene）
    Meteorite(GameObject* parent);

    //デストラクタ
    ~Meteorite();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void OnCollision(GameObject* pTarget);

    void SetMeteorite(std::string modelNamePath,float posX, float posY, float posZ);
};

