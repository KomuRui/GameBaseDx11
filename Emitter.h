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

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
	void CreateParticle();
};