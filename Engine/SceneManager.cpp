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


//�R���X�g���N�^
SceneManager::SceneManager(GameObject * parent)
	: GameObject(parent, "SceneManager"), PlayVideo(false)
{
}

//������
void SceneManager::Initialize()
{
	//�ŏ��̃V�[��������
	currentSceneID_ = SCENE_ID_SPLASH;
	nextSceneID_ = currentSceneID_;
	Instantiate<SplashScene>(this);
}

//�X�V
void SceneManager::Update()
{
	//���̃V�[�������݂̃V�[���ƈႤ�@���@�V�[����؂�ւ��Ȃ���΂Ȃ�Ȃ�
	if (currentSceneID_ != nextSceneID_)
	{
		//���̃V�[���̃I�u�W�F�N�g��S�폜
		KillAllChildren();

		//���[�h�����f�[�^��S�폜
		Audio::Release();
		Model::AllRelease();
		Image::AllRelease();

		//���̃V�[�����쐬
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

//�`��
void SceneManager::Draw()
{
}

//�J��
void SceneManager::Release()
{
}

//�V�[���؂�ւ��i���ۂɐ؂�ւ��̂͂��̎��̃t���[���j
void SceneManager::ChangeScene(SCENE_ID next)
{
	nextSceneID_ = next;
}