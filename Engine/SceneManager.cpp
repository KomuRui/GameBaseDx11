#include "sceneManager.h"
#include "../SplashScene/SplashScene.h"
#include "../TitleScene/TitleScene.h"
#include "../EarthScene/EarthScene.h"
#include "../HomeScene/HomeScene.h"
#include "../MonthScene/MonthScene.h"
#include "../SunScene/SunScene.h"
#include "../CustomizeScene/CustomizeScene.h"
#include "../CourseOrCustomizedScene/CourseOrCustomizedScene.h"
#include "../CourseSelectScene/CourseSelectScene.h"
#include "../ResultScene/ResultScene.h"
#include "Model.h"
#include "Image.h"
#include "Audio.h"


//コンストラクタ
SceneManager::SceneManager(GameObject * parent)
	: GameObject(parent, "SceneManager"), PlayVideo(false)
{
}

//初期化
void SceneManager::Initialize()
{
	//最初のシーンを準備
	currentSceneID_ = SCENE_ID_SPLASH;
	nextSceneID_ = currentSceneID_;
	Instantiate<SplashScene>(this);
}

//更新
void SceneManager::Update()
{
	//次のシーンが現在のシーンと違う　＝　シーンを切り替えなければならない
	if (currentSceneID_ != nextSceneID_)
	{
		//そのシーンのオブジェクトを全削除
		KillAllChildren();

		//ロードしたデータを全削除
		Audio::Release();
		Model::AllRelease();
		Image::AllRelease();

		//次のシーンを作成
		switch (nextSceneID_)
		{
		case SCENE_ID_SPLASH:				 Instantiate<SplashScene>(this); break;
		case SCENE_ID_TITLE:				 Instantiate<TitleScene>(this); break;
		case SCENE_ID_EARTH:				 Instantiate<EarthScene>(this); break;
		case SCENE_ID_HOME:					 Instantiate<HomeScene>(this); break;
		case SCENE_ID_SUN:					 Instantiate<SunScene>(this); break;
		case SCENE_ID_MONTH:				 Instantiate<MonthScene>(this); break;
		case SCENE_ID_CUSTOMIZE:			 Instantiate<CustomizeScene>(this); break;
		case SCENE_ID_COURSEORCUSTOMIZED:	 Instantiate<CourseOrCustomizedScene>(this); break;
		case SCENE_ID_COURSESELECT:			 Instantiate<CourseSelectScene>(this); break;
		case SCENE_ID_RESULT:				 Instantiate<ResultScene>(this); break;
		}
		Audio::Initialize();
		currentSceneID_ = nextSceneID_;
	}

}

//描画
void SceneManager::Draw()
{
}

//開放
void SceneManager::Release()
{
}

//シーン切り替え（実際に切り替わるのはこの次のフレーム）
void SceneManager::ChangeScene(SCENE_ID next)
{
	nextSceneID_ = next;
}