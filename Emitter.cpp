#include "Emitter.h"
#include"Particle.h"

Emitter::Emitter(GameObject* parent)
	:GameObject(parent,"Emitter"),particleCount_(0),createTime_(300),vDir_(XMVectorSet(0,-1,0,0))
{

}

Emitter::~Emitter()
{

}


//‰Šú‰»
void Emitter::Initialize()
{

}

//XV
void Emitter::Update()
{

	if (particleCount_==10)
	{
		XMMATRIX matDir = XMMatrixRotationX(XMConvertToRadians(rand())) * XMMatrixRotationY(rand()) * XMMatrixRotationZ(rand());
		vDir_ = XMVector3TransformCoord(vDir_, matDir);
		JetParticle* particle = Instantiate<JetParticle>(this);
		particle->SetParticle(1.0f, 0.0f, 1.0f, vDir_);
		particleCount_ = 0;
	}
	particleCount_++;
}

//•`‰æ
void Emitter::Draw()
{

}

//ŠJ•ú
void Emitter::Release()
{

}

void Emitter::CreateParticle()
{

}