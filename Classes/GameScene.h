#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
class GameScene : public cocos2d::Scene {
public:
	GameScene();
	~GameScene();
	virtual bool init();
	CREATE_FUNC(GameScene);
};
#endif

/*
0.
USING_NS_CC;ʹ��cocos2d�����ռ�
*/