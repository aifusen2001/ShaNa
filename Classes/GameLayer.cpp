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
		//setTouchMode(Touch::DispatchMode::ONE_BY_ONE);//��������������Ϊ���㴥��
		tilemap = TMXTiledMap::create("tilemap.tmx");//����TMXTiledMap������Ƭ��ͼ��
		/*
		��Ҫ������tilemap.tmx����ļ��ĸ�ʽ����ô����
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
	//auto objectGroup = map->getObjectGroup("Role");//ͨ�����������ò��ж����鼯��
	//auto obj = objectGroup->getObject("shana");//ͨ����������ö�����Ϣ
	//shana->setPosition(30,obj["y"].asFloat() + shana->getSprite()->getContentSize().height / 2);//ָ��shana��λ��

	/*
	ǰ�漸�����ͺ��漸�䵽����ʲô��ϵ�أ�
	*/

	//auto shana = ShaNa::create();
	//shana->setPosition(30,shana->getSprite()->getContentSize().height / 2);//ָ��shana��λ��
	//addChild(shana);
	//GlobalCtrl::getInstance()->Shana = shana;

	/*
	�����������һ�Σ�shana�����м䣬���ǵ�ͼ�����м䣿����
	����Ƕ�����λ��shana��λ�ã�centerViewOfPoint�����shana��λ�ö�������λ��
	����Ϊshana��update �� centerViewOfPoint(Vec2 pos)����
	����֮��Ϳ�������һ��ʼ�;����м�
	*/
	auto map = GlobalCtrl::getInstance()->tilemap;//��ȡTMX Tiled��ͼ���Ѹõ�ͼ����ŵ�Ψһʵ����
	auto objectGroup = map->getObjectGroup("Role");//��ȡ��ΪRole�Ķ��󼯺ϣ�����Ӧ���Ǹ�����ɣ���
	auto obj = objectGroup->getObject("shana");//���shana�������Ӧ�������˹���

	auto shana = ShaNa::create();//����shana
	shana->setPosition(Vec2(obj["x"].asFloat(),
		obj["y"].asFloat() + shana->getSprite()->getContentSize().height / 2));//ָ��shana��λ��
	addChild(shana);//��shana��ӵ�������
	GlobalCtrl::getInstance()->Shana = shana;//��shana�ŵ�Ψһʵ����

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