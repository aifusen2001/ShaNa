#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__
#include "cocos2d.h"

USING_NS_CC;

class GameLayer : public Layer{
public:
	GameLayer();
	~GameLayer();

	virtual bool init();
	CREATE_FUNC(GameLayer);
	virtual bool onTouchBegan(Touch *touch,Event*event);
private:
	void addShaNa();
private:
	TMXTiledMap* tilemap;
};
#endif

/*
0.
�ඨ����֮���ڴ��������һ���ֺţ���Ȼ�ᱨ���캯�������з���ֵ��֮���Ī������Ĵ���
1.
�̳�ʱ��Ҫpublic�̳У���Ȼ�ᱨ����ת������
�����������Ϊ c++Ĭ�ϼ̳з�ʽ��private�̳У��������û�б�עpublic�̳еĻ���GameLayer�Ͳ���̳�Layer��create()������
���Ǽ̳�Node��create()���������Ե�����GameLayer��create()�����ᴴ��һ��node����Ȼ����ӵ�������ʱ�ᱨ��
��Ϊ������addChild()�����Ĳ���ֻ����ͼ����󣨴���֤��
*/