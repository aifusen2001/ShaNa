#include"ShaNa.h"
#include"AnimationUtil.h"
#include"GlobalCtrl.h"

ShaNa::ShaNa(){}
ShaNa::~ShaNa(){}

void ShaNa::attackCallbackFunc(Node* pSender) {

}//���Ŷ�������ʱ�����������Ӧ����Ϊ�˿������������ֵ��

bool ShaNa::init(){
	bool bRet = false;
	do
	{
		setSprite(Sprite::create("$shana_1.png", Rect(0, 0, 55, 62)));//����ǽ�ȡ$shana_1.png��rect������Ϊһ��sprite
		addChild(getSprite());
		//��ʼ�����ֶ���
		auto standAnimn = AnimationUtil::getAnimation("$shana_1.png", 4, 4);//��һ�������Ǵ���������֡�����ļ������ǵ��ļ����Ա�˫����Ҳ�ǲ���
		                                             //�ڶ��������Ǹ�֡�����ļ����幤�����˼���֡
		                                             //������������1���в��ż�֡
		                                             //��������һ��animation����
		setStandAnimation(RepeatForever::create(Animate::create(standAnimn)));//��������Ǵ�Role��̳����ģ�
		                                             //������Action* _standAnimnΪ�������action����
		auto skillA = AnimationUtil::getAnimation("$shana_2.png", 7, 20);
		setSkillA(Sequence::create(Animate::create(skillA),
			CallFuncN::create(CC_CALLBACK_1(ShaNa::attackCallbackFunc,this)),
			CallFuncN::create(CC_CALLBACK_1(ShaNa::createStandAnimCallback, this)), nullptr));
		auto runLeft = AnimationUtil::getAnimation("$shana_rollback.png", 8, 8);
		setRunLeft(RepeatForever::create(Animate::create(runLeft)));
		auto runRight = AnimationUtil::getAnimation("$shana_forward.png", 8, 8);
		setRunRight(RepeatForever::create(Animate::create(runRight)));

		setAllowMove(true);
		runStandAnimation();//���Ҳ�Ǽ̳���Role�࣬������ֹͣ_sprite�����������ж�����Ȼ�󲥷�stand����
		scheduleUpdate();
		bRet = true;
	} while (false);
	return bRet;
}

void ShaNa::update(float delay){
	updateSelf();
	centerViewOfPoint(getPosition());
}

/*��ʵ�ǿ��Բ���ShaNa::��ע��shana��ĳ�Ա�����ģ�������ע��Ϊ���������ڲ�����ʹ��һЩ������getParent,������ĳ�Ա�����Ͳ�����*/
void ShaNa::centerViewOfPoint(Vec2 pos) {

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto map = GlobalCtrl::getInstance()->tilemap;

	float mapWidth = map->getMapSize().width*map->getTileSize().width;
	float mapHeight = map->getMapSize().height*map->getTileSize().height;

	float x = MAX(getPositionX(), visibleSize.width / 2);
	float y = MAX(getPositionY(), visibleSize.height / 2);

	x = MIN(x, mapWidth - visibleSize.width / 2);
	y = MIN(y, mapHeight - visibleSize.height / 2);

	Vec2 actualPos = Vec2(x, y);
	Vec2 centerPos = Vec2(visibleSize / 2);
	Vec2 disPos = centerPos - actualPos;

	getParent()->setPosition(disPos);
}

void ShaNa::updateSelf(){
	//��������Ǵ��Ǳ߿������ģ�����ɶ��˼
		auto visibleSize = Director::getInstance()->getVisibleSize();
		auto curPos = getPosition();//��ǰλ��
		auto expectPos = curPos + getVelocity();//����Ҫ����λ��
		auto actualPos = expectPos;

		float width = getSprite()->getContentSize().width;
		float height = getSprite()->getContentSize().height;

		float mapHeight = GlobalCtrl::getInstance()->tilemap->getTileSize().height * 4;
		float mapWidth = GlobalCtrl::getInstance()->tilemap->getContentSize().width;

		/*if (expectPos.x - width / 2 < 0 || expectPos.x + width / 2 > mapWidth) {
			actualPos.x = curPos.x;
		}
		if (expectPos.y - height / 2 < 0 || expectPos.y - height / 2 > mapHeight) {
			actualPos.y = curPos.y;
		}*/
		setPosition(actualPos);

		setLocalZOrder(visibleSize.height - getPositionY());
}

void ShaNa::onMove(Vec2 direction, float distance){
	distance = (distance > 15.0 ? 3.0f : 1.0f);
	setVelocity(direction*distance);
	bool isRight = direction.x < 0 ? true : false;
	getSprite()->setFlippedX(isRight);
	runRunRightAnimation();

	/****
	****����������һ�����⡣֮ǰ��direction.x>0��runRunLeftAnimation()ʱ,shana���Գ���ȷ�����ܣ�����ͣ�������򷴷���
	������Ϊһ��ʼվ�Ų���ʱ��shana�����ǳ��ҵġ�
	���run�����ߣ���Ҫ��ת������runͣ��ʱ��shana�Ƿ�ת���ĳ���

	����Ӧ����runRunRightAnimation()
	һ��ʼ���ǳ��ң�run������ʱ����ת��ͣ��ʱ����
	run����ʱ��ת��ͣ��ʱ�Ƿ�ת���ĳ���

	****/


}

void ShaNa::onStop(){
	setVelocity(Vec2::ZERO);
	runStandAnimation();
}