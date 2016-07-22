#include "Role.h"
#include"GlobalCtrl.h"
#include"ShaNa.h"


Role::Role() :
_sprite(nullptr),
_standAnimn(nullptr),
_skillA(nullptr),
_runLeft(nullptr),
_runRight(nullptr),
_velocity(Vec2::ZERO)
{}


Role::~Role() {
	CC_SAFE_RELEASE_NULL(_sprite);
	CC_SAFE_RELEASE_NULL(_standAnimn);
}

bool Role::init() {
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Node::init());
		bRet = true;
	} while (false);
	return bRet;
}

bool Role::changeState(RoleActionState state){
	bool bRet = false;
	do{
		CC_BREAK_IF(getCurState() == state);
		bRet = true;
		setCurState(state);
	} while (false);
	return bRet;
}

void Role::runStandAnimation() {
	if (changeState(AC_STAND)){
		getSprite()->stopAllActions();
		getSprite()->runAction(getStandAnimation());
	}
}

void Role::runSkillAAnimation() {
	if (changeState(AC_SKILLA)){
		getSprite()->stopAllActions();
		getSprite()->runAction(getSkillA());
	}
}

void Role::runRunLeftAnimation(){
	if (changeState(AC_RUN)){
		getSprite()->stopAllActions();
		getSprite()->runAction(getRunLeft());
	}
}
void Role::runRunRightAnimation(){
	if (changeState(AC_RUN)){
		getSprite()->stopAllActions();
		getSprite()->runAction(getRunRight());
	}
}

void Role::createStandAnimCallback(Node* pSender) {
	runStandAnimation();
}

void Role::createSkillAAnimCallback(Ref*psender){
	runSkillAAnimation();
}
void Role::createRunLeftAnimCallback(Ref* pSender){
	runRunLeftAnimation();
}
void Role::createRunRightAnimCallback(Ref*pSender){
	runRunRightAnimation();
}





