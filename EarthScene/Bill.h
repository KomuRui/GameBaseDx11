#pragma once
#include"../Engine/GameObject.h"
class Bill : public GameObject
{

    int hModel_;
    std::string fileNamePath_;
public:
    //コンストラクタ
  //引数：parent  親オブジェクト（PlayScene）
    Bill(GameObject* parent);

    //デストラクタ
    ~Bill();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetModel(std::string fileNamePath,XMFLOAT3 position,float angle);
};

