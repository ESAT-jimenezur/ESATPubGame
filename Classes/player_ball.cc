#include "player_ball.h"

using namespace cocos2d;

PlayerBall::PlayerBall() {
  center_ = Vec2(500.0f, 250.0f);
  can_move_ = false;
}

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
    //setPosition(touch->getLocation());
    setPosition(PlayerBall::move(touch));
  };

  listener->onTouchEnded = [=](Touch* touch, Event* event) {
    PlayerBall::returnToCenter(touch);
    PlayerBall::touchEvent(touch, touch->getLocation());
  };

  Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30); // ??
}

void PlayerBall::touchEvent(Touch* touch, Vec2 _p) {
  CCLOG("Touched the ball!");
}

void PlayerBall::returnToCenter(Touch* touch) {
  MoveTo* action = MoveTo::create(0.25f, center_);
  this->runAction(action);
}

Vec2 PlayerBall::move(Touch* touch) {
  float tmp_x = touch->getLocation().x;
  float tmp_y = touch->getLocation().y;

  float res_x;
  float res_y;

  if (tmp_x > center_.x) {
    res_x = center_.x - (tmp_x - center_.x);
  }
  else if (tmp_x < center_.x) {
    res_x = center_.x + (center_.x - tmp_x);
  }
  if (tmp_y > center_.y) {
    res_y = center_.y - (tmp_y - center_.y);
  }
  else if (tmp_y < center_.y) {
    res_y = center_.y + (center_.y - tmp_y);
  }

  return Vec2(res_x, res_y);
}