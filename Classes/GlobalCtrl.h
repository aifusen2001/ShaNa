#pragma once

#include "cocos2d.h"
USING_NS_CC;

class ShaNa;
class GlobalCtrl {
public:
	GlobalCtrl();
	~GlobalCtrl();
	static GlobalCtrl* getInstance();
	static void destroyInstance();

	ShaNa* Shana;
	TMXTiledMap* tilemap;

private:
	static GlobalCtrl* _instance;
};

