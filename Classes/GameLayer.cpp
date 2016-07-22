#include"GameLayer.h"
#include"ShaNa.h"
#include "GlobalCtrl.h"

GameLayer::GameLayer() {}

GameLayer::~GameLayer() {}

bool GameLayer::init(){
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());
		//setTouchEnabled(true);
		//setTouchMode(Touch::DispatchMode::ONE_BY_ONE);//开启触摸并设置为单点触摸
		tilemap = TMXTiledMap::create("tilemap.tmx");//创建TMXTiledMap对象（瓦片地图）
		/*
		需要搞明白tilemap.tmx这个文件的格式是怎么样的
		*/
		GlobalCtrl::getInstance()->tilemap = tilemap;
		addChild(tilemap, -10); //addChild(tileMap,0,100);
		addShaNa();
		bRet = true;
	} while (false);

	return bRet;
}

void GameLayer::addShaNa(){
	//auto map = this->tilemap;
	//auto objectGroup = map->getObjectGroup("Role");//通过对象层名获得层中对象组集合
	//auto obj = objectGroup->getObject("shana");//通过对象名获得对象信息
	//shana->setPosition(30,obj["y"].asFloat() + shana->getSprite()->getContentSize().height / 2);//指定shana的位置

	/*
	前面几句代码和后面几句到底有什么联系呢？
	*/

	//auto shana = ShaNa::create();
	//shana->setPosition(30,shana->getSprite()->getContentSize().height / 2);//指定shana的位置
	//addChild(shana);
	//GlobalCtrl::getInstance()->Shana = shana;

	/*
	如果用下面这一段，shana会在中间，但是地图不在中间？？？
	这段是定好了位置shana的位置，centerViewOfPoint会根据shana的位置定背景的位置
	是因为shana的update 和 centerViewOfPoint(Vec2 pos)函数
	加上之后就可以让他一开始和就在中间
	*/
	auto map = GlobalCtrl::getInstance()->tilemap;//获取TMX Tiled地图，把该地图对象放到唯一实例中
	auto objectGroup = map->getObjectGroup("Role");//获取名为Role的对象集合（返回应该是个数组吧？）
	auto obj = objectGroup->getObject("shana");//获得shana对象（这个应该是主人公）

	auto shana = ShaNa::create();//创建shana
	shana->setPosition(Vec2(obj["x"].asFloat(),
		obj["y"].asFloat() + shana->getSprite()->getContentSize().height / 2));//指定shana的位置
	addChild(shana);//把shana添加到容器中
	GlobalCtrl::getInstance()->Shana = shana;//把shana放到唯一实例中

}

bool GameLayer::onTouchBegan(Touch *touch, Event*event){
	bool bRet = false;
	do{
		//ShaNa* shana = GlobalCtrl::getInstance()->Shana;
		//shana->runSkillAAnimation();
		bRet = true;
	} while (false);
	return bRet;
}