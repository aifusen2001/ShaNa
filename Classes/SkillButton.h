#pragma once
#include "cocos2d.h"
USING_NS_CC;

class SkillButton :public Node{
public:
	SkillButton();
	~SkillButton();

	virtual bool init();
	CREATE_FUNC(SkillButton);
private:
	void SkillMenuCallback(Ref*pSender);
};