#pragma once
#include <string>
#include "../Engine/GameObject.h"

class AirframePlatform : public GameObject
{
protected:

	std::string modelNamePath_; //モデルパス名
	float       weight_;        //重さ(障害物に当たった時の減速度に関係)
	float       acceleration_;  //加速度(機体の加速する速さに関係)
	float       booster_;       //ブースター(ブーストの溜まる速さに関係)

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

	//コンストラクタ(後々値が決まったら外部から値読み込むでコンストラクタで設定)
	Body(std::string Path, float Wei, float Ace, float Boo)
	{ modelNamePath_ = Path; weight_ = Wei; acceleration_ = Ace; booster_ = Boo; }
};

class MainWing : public AirframePlatform
{
	//コンストラクタ(後々値が決まったら外部から値読み込むでコンストラクタで設定)
	MainWing(std::string Path, float Wei, float Ace, float Boo)
	{ modelNamePath_ = Path; weight_ = Wei; acceleration_ = Ace; booster_ = Boo;}
};

class TailPlane : public AirframePlatform
{
	//コンストラクタ(後々値が決まったら外部から値読み込むでコンストラクタで設定)
	TailPlane(std::string Path, float Wei, float Ace, float Boo)
	{ modelNamePath_ = Path; weight_ = Wei; acceleration_ = Ace; booster_ = Boo;}
};

class Engine : public AirframePlatform
{
	//コンストラクタ(後々値が決まったら外部から値読み込むでコンストラクタで設定)
	Engine(std::string Path, float Wei, float Ace, float Boo, GameObject* parent)
	{ modelNamePath_ = Path; weight_ = Wei; acceleration_ = Ace; booster_ = Boo;}
};