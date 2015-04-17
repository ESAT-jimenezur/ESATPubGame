#ifndef __PLAYER_BALL_H__
#define __PLAYER_BALL_H__

#include "cocos2d.h"

class PlayerBall : public cocos2d::Sprite {
 public:
   PlayerBall();
  ~PlayerBall() {}
  static PlayerBall* create();

  void initOptions();

  void addEvents();
  void touchEvent(cocos2d::Touch* touch, cocos2d::Vec2 _p);
  void returnToCenter(cocos2d::Touch* touch);
  cocos2d::Vec2 move(cocos2d::Touch* touch);

 private:
  cocos2d::Vec2 center_;
   bool can_move_;
};

#endif // __PLAYER_BALL_H__