#include"GameScene.h"
#include"GameLayer.h"
#include"OperaterLayer.h"

GameScene::GameScene() {}

GameScene::~GameScene() {}

bool GameScene::init(){
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Scene::init());
		auto gameLayer = GameLayer::create();
		addChild(gameLayer);
		auto operatorLayer = OperatorLayer::create();
		addChild(operatorLayer, 2);
		bRet = true;
	} while (false);
	return bRet;
}

/*
0.
自己添加的头文件经常无法打开
这个问题的原因是我们添加的类文件的路径与工程包含的头文件所在目录不同造成的，
解决方式是：右键点击解决方案中的项目名称-》选中“属性” -》配置属性  -》C/C++ 常规-->附加包含目录
把那个类的路径包含进去
比如原来里面有路径..\classes，所以项目文件夹下这个文件夹里的东西可以读到，
所以应该添加..\proj.win32，就可以读到win32文件夹下的类了。或者把类移到
classes文件夹
1.
调用顺序为 main() -> AppDelegate ->HelloWorld::scene() -> CREATE_FUNC() -> init()
#define CREATE_FUNC(__TYPE__) \
static __TYPE__* create() \
{ \
__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->init()) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}
CREATE_FUNC（类名）它执行了类的构造函数,执行了init()初始化函数,最后又设置创建出的对象为自动释放内存.这样其他人在使用这个类的时候,
只要是用create()函数创建出来的对象就不用费心去管理释放内存了.
2.
do{
//To do
}while(0);
和CC_BREAK_IF宏组合
这是一种c++编程技巧，这是为了当对象创建失败时直接跳到后面继续处理
3.
*发现问题所在了，如果你想要使用CREATE_FUNC这个宏，就要必须要实现这个宏的定义，定义里需要调用autorelease()函数来实现系统自动内存管理功能，
所以你需要有一个autorelease()函数，用来在这个对象不需要的时候自动释放掉。
autorelease在node类里有定义，
所以如果想要用这个宏就必须要继承node类或它的子类(Layer,Sence,node等)
*/
