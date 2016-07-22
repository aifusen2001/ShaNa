#include"JoyStick.h"
#include"GlobalCtrl.h"
#include"ShaNa.h"

JoyStick::JoyStick(){}
JoyStick::~JoyStick(){}

JoyStick* JoyStick::create(const char*background, const char*mask){
	JoyStick* joyStick = new JoyStick();
	if (joyStick&&joyStick->init(background, mask)){
		joyStick->autorelease();//��Ϊû����CREATE_FUNC�꣬������Ҫ�ֶ������������
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
	
	auto touchListener = EventListenerTouchOneByOne::create();//�������������ʲô��˼****
	touchListener->onTouchBegan = CC_CALLBACK_2(JoyStick::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(JoyStick::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(JoyStick::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);//���������ȫû����****

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
	//ת���ɽ���ڲ�������ϵ
	pos = convertToNodeSpace(pos);
	//������ԭ��λ�õľ���
	float distance = pos.getDistance(start);
	if (distance > 33.0f) {
		distance = 33.0f;//33��mask�İ뾶
	}
	Vec2 direction = (pos - start).getNormalized();//�����������������������֮�䷽���**** directionֵӦ���ǣ�cos,sin��
	//��JoyStick�Ƶ���λ����
	this->mask->setPosition(distance*direction);//�������Ҫ�о�һ��
	//����ָʾ��shanaҲ�ƶ�*****
	GlobalCtrl::getInstance()->Shana->onMove(direction,distance);
}
void JoyStick::onTouchEnded(Touch* touch, Event* event){
	hideJoyStick();
	mask->setPosition(start);
	GlobalCtrl::getInstance()->Shana->onStop();
}
Rect JoyStick::getJoyStickBox(){
	float x = getPosition().x;//�����������_position,������joystickʱ������position,_position����position�õ�****
	float y = getPosition().y;
	float width = getContentSize().width;//ע���������****
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
cocosÿ֡��ѽڵ�����Ķ�������һ�飬��������ֻ��Ҫ�ڴ��������ýڵ�����ÿһ���ڵ��״̬����
*/




