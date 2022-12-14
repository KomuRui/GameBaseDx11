#pragma once
#include"Engine/GameObject.h"
class Emitter : public GameObject
{
    int particleCount_;
    float createTime_;
    float patStart_;
    float patSpeed_;
    float acceleration_;

    XMVECTOR vDir_;
public:
	Emitter(GameObject* parent);
	~Emitter();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
	void CreateParticle();
};