#ifndef __OPERATER_LAYER_H__
#define __OPERATER_LAYER_H__

#include"cocos2d.h"
USING_NS_CC;

class OperatorLayer : public Layer{
public:
	OperatorLayer();
	~OperatorLayer();
	virtual bool init();
	CREATE_FUNC(OperatorLayer);
};

#endif