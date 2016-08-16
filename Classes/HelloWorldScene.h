#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "VunglePubAd.h"
#include "ui/CocosGUI.h"

class HelloWorld : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    
    static HelloWorld* getInstatnce();
     virtual bool init();
      cocos2d::ui::Button* showAdBtn;
      cocos2d::ui::Button* showAdWithOptionsBtn;
      cocos2d::ui::Button* showIncentivizedAdBtn;
      void setBtnEnable(bool status);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
