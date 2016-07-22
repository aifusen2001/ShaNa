#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__
#include "cocos2d.h"

USING_NS_CC;

class GameLayer : public Layer{
public:
	GameLayer();
	~GameLayer();

	virtual bool init();
	CREATE_FUNC(GameLayer);
	virtual bool onTouchBegan(Touch *touch,Event*event);
private:
	void addShaNa();
private:
	TMXTiledMap* tilemap;
};
#endif

/*
0.
类定义完之后，在大括号外加一个分号，不然会报构造函数不能有返回值啊之类的莫名其妙的错误
1.
继承时需要public继承，不然会报类型转换错误
初步理解是因为 c++默认继承方式是private继承，所以如果没有标注public继承的话，GameLayer就不会继承Layer的create()方法，
而是继承Node的create()方法，所以当调用GameLayer的create()方法会创建一个node对象，然后添加到场景中时会报错，
因为场景的addChild()函数的参数只能是图层对象（待考证）
*/