#pragma once
#include"Engine/GameObject.h"
#include"EarthScene/Bill.h"
class CreateBill : public GameObject
{
    Bill* p_;
public:
    //コンストラクタ
  //引数：parent  親オブジェクト（PlayScene）
    CreateBill(GameObject* parent);

    //デストラクタ
    ~CreateBill();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetModel(std::string fileNamePath, XMFLOAT3 position, float angle);
};

