#pragma once
#include"../Engine/GameObject.h"
class BillBoard : public GameObject
{
    int hModel_;
    std::string modelNamePath_;
public:
    //コンストラクタ
 //引数：parent  親オブジェクト（PlayScene）
    BillBoard(GameObject* parent);

    //デストラクタ
    ~BillBoard();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //看板をビルにセット
    void SetBillBoard(std::string modelNamePath, float posX, float posY, float posZ);
    void SetBillBoard(std::string modelNamePath, XMFLOAT3 position);

};

