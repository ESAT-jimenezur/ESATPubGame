#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

#include "player_ball.h"

class Game : public cocos2d::Layer
{
public:
  // there's no 'id' in cpp, so we recommend returning the class instance pointer
  static cocos2d::Scene* createScene();

  // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
  virtual bool init();

  void update(float dt) override;

  void menuCloseCallback(cocos2d::Ref* pSender);
  // a selector callback

  // implement the "static create()" method manually
  CREATE_FUNC(Game);

private:
  PlayerBall* player_;
};

#endif // __GAME_SCENE_H__