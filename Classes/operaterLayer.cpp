#include"OperaterLayer.h"
#include"JoyStick.h"

OperatorLayer::OperatorLayer() {}
OperatorLayer::~OperatorLayer(){}

bool OperatorLayer::init(){
	bool bRef = false;
	do{
		JoyStick* joyStick = JoyStick::create("joystickBg.png","joystick.png");
		//���ҡ��
		joyStick->setPosition(60,50);
		addChild(joyStick);
		//��Ӽ��ܰ�ť

		bRef = true;
	} while (false);
	return bRef;
}