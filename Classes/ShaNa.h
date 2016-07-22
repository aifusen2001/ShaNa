#ifndef __SHA_NA_H__
#define __SHA_NA_H__

#include "cocos2d.h"
#include "Role.h"
USING_NS_CC;

//enum SkillState{
//	SKILL_NULL = 0,
//	SKILL_A,
//	SKILL_B,
//	SKILL_C,
//	SKILL_D
//};

class ShaNa :public Role{
public:
	ShaNa();
	~ShaNa();
	void onMove(Vec2 direction, float distance);
	void onStop();
	virtual bool init(); 
	CREATE_FUNC(ShaNa);
	void update(float delay);
	void updateSelf();
	void centerViewOfPoint(Vec2 pos);
  
private:
	void attackCallbackFunc(Node* pSender);

};


#endif