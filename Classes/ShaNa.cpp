#include"ShaNa.h"
#include"AnimationUtil.h"
#include"GlobalCtrl.h"

ShaNa::ShaNa(){}
ShaNa::~ShaNa(){}

void ShaNa::attackCallbackFunc(Node* pSender) {

}//播放动画结束时调用这个函数应该是为了控制人物的生命值吧

bool ShaNa::init(){
	bool bRet = false;
	do
	{
		setSprite(Sprite::create("$shana_1.png", Rect(0, 0, 55, 62)));//这个是截取$shana_1.png中rect部分作为一个sprite
		addChild(getSprite());
		//初始化各种动画
		auto standAnimn = AnimationUtil::getAnimation("$shana_1.png", 4, 4);//第一个参数是创建动画的帧序列文件名，记得文件名旁边双引号也是参数
		                                             //第二个参数是该帧序列文件中义工包含了几个帧
		                                             //第三个参数是1秒中播放几帧
		                                             //函数返回一个animation对象
		setStandAnimation(RepeatForever::create(Animate::create(standAnimn)));//这个函数是从Role类继承来的，
		                                             //它设置Action* _standAnimn为参数里的action动作
		auto skillA = AnimationUtil::getAnimation("$shana_2.png", 7, 20);
		setSkillA(Sequence::create(Animate::create(skillA),
			CallFuncN::create(CC_CALLBACK_1(ShaNa::attackCallbackFunc,this)),
			CallFuncN::create(CC_CALLBACK_1(ShaNa::createStandAnimCallback, this)), nullptr));
		auto runLeft = AnimationUtil::getAnimation("$shana_rollback.png", 8, 8);
		setRunLeft(RepeatForever::create(Animate::create(runLeft)));
		auto runRight = AnimationUtil::getAnimation("$shana_forward.png", 8, 8);
		setRunRight(RepeatForever::create(Animate::create(runRight)));

		setAllowMove(true);
		runStandAnimation();//这个也是继承自Role类，作用是停止_sprite正在做的所有动作，然后播放stand动画
		scheduleUpdate();
		bRet = true;
	} while (false);
	return bRet;
}

void ShaNa::update(float delay){
	updateSelf();
	centerViewOfPoint(getPosition());
}

/*其实是可以不用ShaNa::标注是shana类的成员函数的，这样标注是为了让它的内部可以使用一些函数如getParent,不是类的成员函数就不能用*/
void ShaNa::centerViewOfPoint(Vec2 pos) {

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto map = GlobalCtrl::getInstance()->tilemap;

	float mapWidth = map->getMapSize().width*map->getTileSize().width;
	float mapHeight = map->getMapSize().height*map->getTileSize().height;
	Vec2 dispos = Vec2::ZERO;

	if (pos.x < visibleSize.width / 2){
		dispos.x = 0;
	}
	else if (pos.x > visibleSize.width / 2 && pos.x < (mapWidth - visibleSize.width / 2)){
		dispos.x = -(pos.x - visibleSize.width / 2);
	}
	else {
		dispos.x = -(mapWidth - visibleSize.width);
	}

	if (pos.y > visibleSize.height / 2){
		dispos.y = visibleSize.height / 2;
	}
	else if (pos.y < 0){
		dispos.y = 0;
	}

	/*float x = MAX(getPositionX(), visibleSize.width / 2);
	float y = MAX(getPositionY(), visibleSize.height / 2);

	x = MIN(x, mapWidth - visibleSize.width / 2);
	y = MIN(y, mapHeight - visibleSize.height / 2);

	Vec2 actualPos = Vec2(x, y);
	Vec2 centerPos = Vec2(visibleSize / 2);
	Vec2 disPos = centerPos - actualPos;*/

	getParent()->setPosition(dispos);
}

void ShaNa::updateSelf(){
	//这个函数是从那边拷过来的，看懂啥意思
		auto visibleSize = Director::getInstance()->getVisibleSize();
		auto curPos = getPosition();//当前位置
		auto expectPos = curPos + getVelocity();//马上要到的位置
		auto actualPos = expectPos;

		float width = getSprite()->getContentSize().width;
		float height = getSprite()->getContentSize().height;

		float mapHeight = GlobalCtrl::getInstance()->tilemap->getTileSize().height * 4;
		float mapWidth = GlobalCtrl::getInstance()->tilemap->getContentSize().width;

		if (expectPos.x - width / 2 < 0 || expectPos.x + width / 2 > mapWidth) {
			actualPos.x = curPos.x;
		}
		if (expectPos.y - height / 2 < 0 || expectPos.y - height / 2 > mapHeight) {
			actualPos.y = curPos.y;
		}
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
	****这里碰到了一个问题。之前用direction.x>0和runRunLeftAnimation()时,shana可以朝正确方向跑，但是停下来朝向反方向
	这里因为一开始站着不动时，shana本身是朝右的。
	如果run朝右走，就要反转，这样run停下时，shana是反转过的朝左

	所以应该用runRunRightAnimation()
	一开始还是朝右，run向右走时不反转，停下时朝右
	run向左时反转，停下时是反转过的朝左

	****/


}

void ShaNa::onStop(){
	setVelocity(Vec2::ZERO);
	runStandAnimation();
}