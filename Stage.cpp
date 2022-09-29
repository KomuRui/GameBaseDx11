#include "Stage.h"
#include"Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/CsvReader.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1), hModel_wall(-1), timeConter_(new Time), hPict_(-1), pSceneManager((SceneManager*)FindObject("SceneManager")),
    hPict_2(-1)
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{

    ///////////////stageデータのロード///////////////////
    hModel_ = Model::Load("EarthScene/Model/EarthStage.fbx");
    Model::SetAlpha(hModel_, 0.3);
    assert(hModel_ >= 0);

    hModel_wall = Model::Load("EarthScene/Model/EarthStage_Wall2.fbx");
    Model::SetAlpha(hModel_wall, 0.0f);
    assert(hModel_wall >= 0);

    hModel_space = Model::Load("EarthScene/Model/SpaceBall.fbx");
    assert(hModel_space >= 0);

    hPict_ = Image::Load("Image/Mark.png");
    assert(hPict_ >= 0);

    hPict_2 = Image::Load("Text/demo.png");
    assert(hPict_2 >= 0);

    ///////////////transform/////////////////
    transform_.scale_.x *= 20;
    transform_.scale_.y *= 20;
    transform_.scale_.z *= 20;

    transform_.position_.x = 900;//48
    transform_.position_.y = 150;
    transform_.position_.z = 900;

    spa.scale_.x *= 20;
    spa.scale_.y *= 20;
    spa.scale_.z *= 20;

    spa.position_.x = 900;//48
    spa.position_.y = 150;
    spa.position_.z = 900;

    //初期化
    timeConter_->Initialize();
    timeConter_->SetTimeflag(true);

    Model::SetAmbient(hModel_space, 300);

}

//更新
void Stage::Update()
{
    spa.rotate_.x += 0.05;
    spa.rotate_.y += 0.05;
}

//描画
void Stage::Draw()
{
    if (Direct3D::GetStatus() == 0)
    {
        
        Model::SetTransform(hModel_space, spa);
        Model::Draw(hModel_space);
    }

    if (Direct3D::GetStatus() == 1)
        Model::SetAlpha(hModel_, 0.3f);

    if (Direct3D::GetStatus() == 0)
        Model::SetAlpha(hModel_, 0.4f);

    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);

    Model::SetTransform(hModel_wall, transform_);
    Model::Draw(hModel_wall);

    
    //タイム表示
    timeConter_->TimeDraw(950, 120);

    if (Direct3D::GetStatus() == 1)
    {
        Transform tra;
        tra.scale_.y = 0.3;
        tra.scale_.x = 0.4;
        Image::SetTransform(hPict_, tra);
        Image::Draw(hPict_);
    }

    if (pSceneManager->GetPlayVideo() && Direct3D::GetStatus() == 0)
    {
        Transform tra;
        tra.position_.y = -0.4;

        tra.scale_.x *= 1.5;
        tra.scale_.y *= 1.5;

        Image::SetTransform(hPict_2, tra);
        Image::Draw(hPict_2);
    }
}

//開放
void Stage::Release()
{
}

