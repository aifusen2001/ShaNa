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
USING_NS_CC;使用cocos2d命名空间
*/