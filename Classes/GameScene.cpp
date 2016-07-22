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
�Լ���ӵ�ͷ�ļ������޷���
��������ԭ����������ӵ����ļ���·���빤�̰�����ͷ�ļ�����Ŀ¼��ͬ��ɵģ�
�����ʽ�ǣ��Ҽ������������е���Ŀ����-��ѡ�С����ԡ� -����������  -��C/C++ ����-->���Ӱ���Ŀ¼
���Ǹ����·��������ȥ
����ԭ��������·��..\classes��������Ŀ�ļ���������ļ�����Ķ������Զ�����
����Ӧ�����..\proj.win32���Ϳ��Զ���win32�ļ����µ����ˡ����߰����Ƶ�
classes�ļ���
1.
����˳��Ϊ main() -> AppDelegate ->HelloWorld::scene() -> CREATE_FUNC() -> init()
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
CREATE_FUNC����������ִ������Ĺ��캯��,ִ����init()��ʼ������,��������ô������Ķ���Ϊ�Զ��ͷ��ڴ�.������������ʹ��������ʱ��,
ֻҪ����create()�������������Ķ���Ͳ��÷���ȥ�����ͷ��ڴ���.
2.
do{
//To do
}while(0);
��CC_BREAK_IF�����
����һ��c++��̼��ɣ�����Ϊ�˵����󴴽�ʧ��ʱֱ�����������������
3.
*�������������ˣ��������Ҫʹ��CREATE_FUNC����꣬��Ҫ����Ҫʵ�������Ķ��壬��������Ҫ����autorelease()������ʵ��ϵͳ�Զ��ڴ�����ܣ�
��������Ҫ��һ��autorelease()���������������������Ҫ��ʱ���Զ��ͷŵ���
autorelease��node�����ж��壬
���������Ҫ�������ͱ���Ҫ�̳�node�����������(Layer,Sence,node��)
*/
