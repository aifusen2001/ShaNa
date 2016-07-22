#ifndef __ROLE_H__
#define __ROLE_H__

#include"cocos2d.h"
USING_NS_CC;

enum RoleActionState {
	AC_STAND = 0,
	AC_RUN,
	AC_SKILLA,
};

class Role :public Node{
public:
	Role();
	~Role();
	virtual bool init();
	bool changeState(RoleActionState);
	//角色精灵
	CC_SYNTHESIZE_RETAIN(Sprite*, _sprite, Sprite);
	CC_SYNTHESIZE(bool, _allowMove, AllowMove);
	//角色拥有的动画
	CC_SYNTHESIZE_RETAIN(Action*, _standAnimn, StandAnimation);//ShaNa站着不动的动画
	CC_SYNTHESIZE_RETAIN(Action*,_skillA,SkillA);//ShaNa使用技能A
	CC_SYNTHESIZE_RETAIN(Action*, _runLeft,RunLeft);//ShaNa向左跑
	CC_SYNTHESIZE_RETAIN(Action*, _runRight, RunRight);//ShaNa向右跑

	CC_SYNTHESIZE(Vec2, _velocity, Velocity);//速率
	CC_SYNTHESIZE(RoleActionState, _curState, CurState);//角色状态

public:
	void runStandAnimation();
	void runSkillAAnimation();
	void runRunLeftAnimation();
	void runRunRightAnimation();
protected:
	void createStandAnimCallback(Node* pSender);
	void createSkillAAnimCallback(Ref*pSender);
	void createRunLeftAnimCallback(Ref*pSender);//这几个函数还是不知道是为什么要这样用，参数为什么是这些********
	void createRunRightAnimCallback(Ref*pSender);
};

#endif

/*
0.
宏使用#define
在程序中出现的是宏名，在该程序被编译前，先将宏名用被定义的字符串替换，这称为宏替换，替换后才进行编译，宏替换是简单的替换。
1.
宏替换发生在编译前，预处理器先源程序中的#include 扩展为文件正文，即把包含的.h文件找到并展开到#include 所在处，
然后 预处理器根据#if和#ifdef等编译命令及其后的条件，将源程序中的某部分包含进来或排除在外，通常把排除在外的语句转换成空行。
最后
2.预处理器将源程序文件中出现的对宏的引用展开成相应的宏 定义，即本文所说的#define的功能，由预处理器来完成。
经过预处理器处理的源程序与之前的源程序有所有不同，在这个阶段所进行的工作只是纯粹的替换与展开，没有任何计算功能
3.#define area(x) x*x
int y=area（2+2）;(y值为8：2+2*2+2=8)
#define PI 3.1415926
有两种：简单的宏定义，带参数的宏定义
4.
define中三个常用特殊符号
#define Conn(x,y) x##y ：连接
#define ToChar(x) #@x ：给x加上单引号
#define ToString(x) #x ：给x加上双引号
5.
什么时候可以用、要用宏？
使用带参数的宏可以完成函数调用功能。
- 使用宏可以提高运行效率，因为函数调用需要保留原函数现场，
执行完调用的函数之后还要恢复现场，在执行较短操作时这样的转换很耗时，直接写代码在那又显得很挤，
而宏定义方式没有这样的缺点，它是直接把执行代码插入执行的地方。
- 但是宏的缺点是占用目标代码空间很大。
所以宏定义完成函数功能适用于完成函数功能较少的情况中

6.
本例中用了两个宏

*/