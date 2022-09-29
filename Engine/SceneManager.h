#pragma once
#include "global.h"
#include "GameObject.h"

//�Q�[���ɓo�ꂷ��V�[��
enum SCENE_ID
{
	SCENE_ID_SPLASH = 0,
	SCENE_ID_TITLE,
	SCENE_ID_EARTH,
	SCENE_ID_HOME,
	SCENE_ID_SUN,
	SCENE_ID_MONTH,
	SCENE_ID_CUSTOMIZE,
	SCENE_ID_COURSEORCUSTOMIZED,
	SCENE_ID_COURSESELECT,
	SCENE_ID_RESULT
};

//-----------------------------------------------------------
//�V�[���؂�ւ���S������I�u�W�F�N�g
//-----------------------------------------------------------
class SceneManager : public GameObject
{

public:

	//�R���X�g���N�^
	//�����Fparent	�e�I�u�W�F�N�g�i��{�I�ɃQ�[���}�l�[�W���[�j
	SceneManager(GameObject* parent);

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	//�V�[���؂�ւ��i���ۂɐ؂�ւ��̂͂��̎��̃t���[���j
	//�����Fnext	���̃V�[����ID
	void ChangeScene(SCENE_ID next);

	void SetPlayVideo(bool flag) { PlayVideo = flag; }

	bool GetPlayVideo() { return PlayVideo; }

private:
	SCENE_ID currentSceneID_;	//���݂̃V�[��
	SCENE_ID nextSceneID_;		//���̃V�[��

	bool PlayVideo;
};