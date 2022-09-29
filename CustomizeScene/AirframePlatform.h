#pragma once
#include <string>
#include "../Engine/GameObject.h"

class AirframePlatform : public GameObject
{
protected:

	std::string modelNamePath_; //���f���p�X��
	float       weight_;        //�d��(��Q���ɓ����������̌����x�Ɋ֌W)
	float       acceleration_;  //�����x(�@�̂̉������鑬���Ɋ֌W)
	float       booster_;       //�u�[�X�^�[(�u�[�X�g�̗��܂鑬���Ɋ֌W)

public:

	AirframePlatform()
	{ modelNamePath_ = ""; weight_ = 0.0f; acceleration_ = 0.0f; booster_ = 0.0f;}

	std::string GetmodelNamePath() { return modelNamePath_; }
	float GetWeight() { return weight_; }
	float GetAcceleration() { return acceleration_; }
	float GetBooster() { return booster_; }
};

class Body : public AirframePlatform
{
public:

	//�R���X�g���N�^(��X�l�����܂�����O������l�ǂݍ��ނŃR���X�g���N�^�Őݒ�)
	Body(std::string Path, float Wei, float Ace, float Boo)
	{ modelNamePath_ = Path; weight_ = Wei; acceleration_ = Ace; booster_ = Boo; }
};

class MainWing : public AirframePlatform
{
	//�R���X�g���N�^(��X�l�����܂�����O������l�ǂݍ��ނŃR���X�g���N�^�Őݒ�)
	MainWing(std::string Path, float Wei, float Ace, float Boo)
	{ modelNamePath_ = Path; weight_ = Wei; acceleration_ = Ace; booster_ = Boo;}
};

class TailPlane : public AirframePlatform
{
	//�R���X�g���N�^(��X�l�����܂�����O������l�ǂݍ��ނŃR���X�g���N�^�Őݒ�)
	TailPlane(std::string Path, float Wei, float Ace, float Boo)
	{ modelNamePath_ = Path; weight_ = Wei; acceleration_ = Ace; booster_ = Boo;}
};

class Engine : public AirframePlatform
{
	//�R���X�g���N�^(��X�l�����܂�����O������l�ǂݍ��ނŃR���X�g���N�^�Őݒ�)
	Engine(std::string Path, float Wei, float Ace, float Boo, GameObject* parent)
	{ modelNamePath_ = Path; weight_ = Wei; acceleration_ = Ace; booster_ = Boo;}
};