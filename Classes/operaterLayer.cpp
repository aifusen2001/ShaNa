#include"OperaterLayer.h"
#include"JoyStick.h"

OperatorLayer::OperatorLayer() {}
OperatorLayer::~OperatorLayer(){}

bool OperatorLayer::init(){
	bool bRef = false;
	do{
		JoyStick* joyStick = JoyStick::create("joystickBg.png","joystick.png");
		//添加摇杆
		joyStick->setPosition(60,50);
		addChild(joyStick);
		//添加技能按钮

		bRef = true;
	} while (false);
	return bRef;
}