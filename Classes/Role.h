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
	//��ɫ����
	CC_SYNTHESIZE_RETAIN(Sprite*, _sprite, Sprite);
	CC_SYNTHESIZE(bool, _allowMove, AllowMove);
	//��ɫӵ�еĶ���
	CC_SYNTHESIZE_RETAIN(Action*, _standAnimn, StandAnimation);//ShaNaվ�Ų����Ķ���
	CC_SYNTHESIZE_RETAIN(Action*,_skillA,SkillA);//ShaNaʹ�ü���A
	CC_SYNTHESIZE_RETAIN(Action*, _runLeft,RunLeft);//ShaNa������
	CC_SYNTHESIZE_RETAIN(Action*, _runRight, RunRight);//ShaNa������

	CC_SYNTHESIZE(Vec2, _velocity, Velocity);//����
	CC_SYNTHESIZE(RoleActionState, _curState, CurState);//��ɫ״̬

public:
	void runStandAnimation();
	void runSkillAAnimation();
	void runRunLeftAnimation();
	void runRunRightAnimation();
protected:
	void createStandAnimCallback(Node* pSender);
	void createSkillAAnimCallback(Ref*pSender);
	void createRunLeftAnimCallback(Ref*pSender);//�⼸���������ǲ�֪����ΪʲôҪ�����ã�����Ϊʲô����Щ********
	void createRunRightAnimCallback(Ref*pSender);
};

#endif

/*
0.
��ʹ��#define
�ڳ����г��ֵ��Ǻ������ڸó��򱻱���ǰ���Ƚ������ñ�������ַ����滻�����Ϊ���滻���滻��Ž��б��룬���滻�Ǽ򵥵��滻��
1.
���滻�����ڱ���ǰ��Ԥ��������Դ�����е�#include ��չΪ�ļ����ģ����Ѱ�����.h�ļ��ҵ���չ����#include ���ڴ���
Ȼ�� Ԥ����������#if��#ifdef�ȱ������������������Դ�����е�ĳ���ְ����������ų����⣬ͨ�����ų���������ת���ɿ��С�
���
2.Ԥ��������Դ�����ļ��г��ֵĶԺ������չ������Ӧ�ĺ� ���壬��������˵��#define�Ĺ��ܣ���Ԥ����������ɡ�
����Ԥ�����������Դ������֮ǰ��Դ���������в�ͬ��������׶������еĹ���ֻ�Ǵ�����滻��չ����û���κμ��㹦��
3.#define area(x) x*x
int y=area��2+2��;(yֵΪ8��2+2*2+2=8)
#define PI 3.1415926
�����֣��򵥵ĺ궨�壬�������ĺ궨��
4.
define�����������������
#define Conn(x,y) x##y ������
#define ToChar(x) #@x ����x���ϵ�����
#define ToString(x) #x ����x����˫����
5.
ʲôʱ������á�Ҫ�úꣿ
ʹ�ô������ĺ������ɺ������ù��ܡ�
- ʹ�ú�����������Ч�ʣ���Ϊ����������Ҫ����ԭ�����ֳ���
ִ������õĺ���֮��Ҫ�ָ��ֳ�����ִ�н϶̲���ʱ������ת���ܺ�ʱ��ֱ��д�����������Եúܼ���
���궨�巽ʽû��������ȱ�㣬����ֱ�Ӱ�ִ�д������ִ�еĵط���
- ���Ǻ��ȱ����ռ��Ŀ�����ռ�ܴ�
���Ժ궨����ɺ���������������ɺ������ܽ��ٵ������

6.
����������������

*/