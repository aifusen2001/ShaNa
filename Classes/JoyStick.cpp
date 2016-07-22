#include"JoyStick.h"
#include"GlobalCtrl.h"
#include"ShaNa.h"

JoyStick::JoyStick(){}
JoyStick::~JoyStick(){}

JoyStick* JoyStick::create(const char*background, const char*mask){
	JoyStick* joyStick = new JoyStick();
	if (joyStick&&joyStick->init(background, mask)){
		joyStick->autorelease();//因为没有用CREATE_FUNC宏，所以需要手动调用这个函数
		return joyStick;
	}
	CC_SAFE_DELETE(joyStick);
	return nullptr;
}

bool JoyStick::init(const char*background, const char*mask){
	back = Sprite::create(background);
	this->mask = Sprite::create(mask);

	addChild(back, -1);
	addChild(this->mask, 0);
	start = Vec2::ZERO; //*****
	
	auto touchListener = EventListenerTouchOneByOne::create();//这个函数不明白什么意思****
	touchListener->onTouchBegan = CC_CALLBACK_2(JoyStick::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(JoyStick::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(JoyStick::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);//这个变量完全没看过****

	hideJoyStick();

	return true;
}

bool JoyStick::onTouchBegan(Touch* touch, Event* event){
	auto pos = touch->getLocation();
	if (getJoyStickBox().containsPoint(pos)){
		showJoyStick();
	}
	return true;
}
void JoyStick::onTouchMoved(Touch* touch, Event* event){
	auto pos = touch->getLocation();
	//转化成结点内部的坐标系
	pos = convertToNodeSpace(pos);
	//计算与原来位置的距离
	float distance = pos.getDistance(start);
	if (distance > 33.0f) {
		distance = 33.0f;//33是mask的半径
	}
	Vec2 direction = (pos - start).getNormalized();//这个函数好像是用来求两点之间方向的**** direction值应该是（cos,sin）
	//把JoyStick移到新位置上
	this->mask->setPosition(distance*direction);//这个算术要研究一下
	//根据指示让shana也移动*****
	GlobalCtrl::getInstance()->Shana->onMove(direction,distance);
}
void JoyStick::onTouchEnded(Touch* touch, Event* event){
	hideJoyStick();
	mask->setPosition(start);
	GlobalCtrl::getInstance()->Shana->onStop();
}
Rect JoyStick::getJoyStickBox(){
	float x = getPosition().x;//这个函数返回_position,当创建joystick时会设置position,_position会由position得到****
	float y = getPosition().y;
	float width = getContentSize().width;//注意这个函数****
	float height = getContentSize().height;

	return Rect(x-width/2,y-height/2,x+width/2,y+height/2);
}

void JoyStick::hideJoyStick(){
	back->setVisible(true);
	mask->setVisible(false);
}
void JoyStick::showJoyStick(){
	back->setVisible(true);
	mask->setVisible(true);
}

/*
cocos每帧会把节点树里的东西都画一遍，所以我们只需要在代码中设置节点树中每一个节点的状态即可
*/




