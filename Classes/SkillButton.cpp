#include"SkillButton.h"
#include"GlobalCtrl.h"
#include"Role.h"
#include"ShaNa.h"

SkillButton::SkillButton(){}
SkillButton::~SkillButton(){}

bool SkillButton::init(){
	bool bRet = false;
	do{
		CC_BREAK_IF(!Node::init());
		auto skillItem = MenuItemImage::create("Encourage.png",
			"skillDown.png",
			CC_CALLBACK_1(SkillButton::SkillMenuCallback, this));
		auto menu = Menu::create(skillItem, nullptr);
		menu->setPosition(Vec2::ZERO);
		addChild(menu);//����Ҫ�ȸ�menu����λ�ã���Ȼskillbutton�Ͳ�����ʾ����
		bRet = true;
	} while (false);
	return bRet;
}

void SkillButton::SkillMenuCallback(Ref*pSender){
	auto shana = GlobalCtrl::getInstance()->Shana;
	if (shana->getCurState() == AC_STAND){
		shana->runSkillAAnimation();
	}
}