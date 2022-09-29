#pragma once
#include"Engine/GameObject.h"
#include<string>
class Particle : public GameObject
{
protected:
    int hModel_;
    float lifeLimit_;
    float attenuationRate_;
    float speed_;

    
    XMVECTOR vDir_;

public:
    //�f�X�g���N�^
    Particle(GameObject* parent,std::string name);
    virtual ~Particle();

    
    void SetParticle(float timeLimit,float attenuationRate, float speed,XMVECTOR vDir);
    void SetLifeLimit(float timeLimit);
    void SetAttenution(float attenuationRate);
    void SetSpeed(float speed);
    void SetDir(XMVECTOR dir);
};

class JetParticle : public Particle
{
    int a_;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iPlayScene�j
    JetParticle(GameObject* parent);

    //�f�X�g���N�^
    ~JetParticle();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};