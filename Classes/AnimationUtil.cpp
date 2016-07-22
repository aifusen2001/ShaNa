#include "AnimationUtil.h"


AnimationUtil::AnimationUtil() {}

AnimationUtil::~AnimationUtil() {}


Animation* AnimationUtil::getAnimation( const char* filename, int frame, int fps ) {
	auto animation = Animation::create();

	auto texture = Sprite::create( filename );
	float h = texture->getContentSize().height;//这个函数是用来干啥的？这个函数是取得每一帧图片的宽高，方便之后设置动画帧
	float w = texture->getContentSize().width / frame;//frame表示帧数

	for ( int i = 0; i < frame; ++i ) {
		auto spriteFrame = SpriteFrame::create( filename, Rect( i*w, 0, w, h ) );//用前面取得的宽高设置动画帧
		animation->addSpriteFrame( spriteFrame );
	}
	animation->setDelayPerUnit( 1.0f / fps );

	return animation;
}

