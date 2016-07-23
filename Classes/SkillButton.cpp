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
		addChild(menu);//必须要先给menu设置位置，不然skillbutton就不能显示出来
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