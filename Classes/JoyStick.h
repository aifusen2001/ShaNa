#pragma once
#include"cocos2d.h"
USING_NS_CC;
class JoyStick:public Node{
public:
	JoyStick();
	~JoyStick();
	static JoyStick* create(const char*background,const char*mask);

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	Rect getJoyStickBox();
	void showJoyStick();
	void hideJoyStick();

private:
	bool init(const char*background, const char*mask);
	Sprite* back;
	Sprite* mask;
	Vec2 start;
};


/*
ΪʲôJoyStick����Ҫʹ��CREATE_FUNC()���أ���������Ϊҡ��ֻ��Ҫһ�������
*/