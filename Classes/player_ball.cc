#include "player_ball.h"

using namespace cocos2d;

PlayerBall* PlayerBall::create() {
  PlayerBall* sprite = new PlayerBall();

  if (sprite->initWithFile("Sprites/basic_ball.png")) {
    sprite->autorelease();
    sprite->initOptions();
    sprite->addEvents();

    return sprite;
  }

  CC_SAFE_DELETE(sprite);
  
  return NULL;
}

void PlayerBall::initOptions() {
  // do things here like setTag(), setPosition(), any custom logic.
}

void PlayerBall::addEvents() {
  auto listener = EventListenerTouchOneByOne::create();
  listener->setSwallowTouches(true);

  listener->onTouchBegan = [&](Touch* touch, Event* event) {
    Vec2 p = touch->getLocation();
    Rect rect = this->getBoundingBox();

    if (rect.containsPoint(p)) {
      return true;  // to indicate that we have consumed the event
    }

    return false; // we did not consume this event, pass thru.
  };

  listener->onTouchMoved = [&](Touch* touch, Event* event) {
    setPosition(touch->getLocation());
  };

  listener->onTouchEnded = [=](Touch* touch, Event* event) {
    PlayerBall::touchEvent(touch, touch->getLocation());
  };

  Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30); // ??
}

void PlayerBall::touchEvent(Touch* touch, Vec2 _p) {
  CCLOG("Touched the ball!");
}