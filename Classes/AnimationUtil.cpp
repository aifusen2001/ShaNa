#include "AnimationUtil.h"


AnimationUtil::AnimationUtil() {}

AnimationUtil::~AnimationUtil() {}


Animation* AnimationUtil::getAnimation( const char* filename, int frame, int fps ) {
	auto animation = Animation::create();

	auto texture = Sprite::create( filename );
	float h = texture->getContentSize().height;//���������������ɶ�ģ����������ȡ��ÿһ֡ͼƬ�Ŀ�ߣ�����֮�����ö���֡
	float w = texture->getContentSize().width / frame;//frame��ʾ֡��

	for ( int i = 0; i < frame; ++i ) {
		auto spriteFrame = SpriteFrame::create( filename, Rect( i*w, 0, w, h ) );//��ǰ��ȡ�õĿ�����ö���֡
		animation->addSpriteFrame( spriteFrame );
	}
	animation->setDelayPerUnit( 1.0f / fps );

	return animation;
}

