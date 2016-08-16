#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

static HelloWorld* mInstance = nil;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    mInstance=layer;
    
    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene

    return scene;
}

HelloWorld* HelloWorld::getInstatnce()
{
    return mInstance;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto bg = cocos2d::LayerColor::create(Color4B(13, 30, 51, 255));
    this->addChild(bg);
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
//    auto label = Label::createWithTTF("Hello Cocos with Vungle", "fonts/Marker Felt.ttf", 24);
//    
//    // position the label on the center of the screen
//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//    // add the label as a child to this layer
//    this->addChild(label, 1);
    
    //"HelloWorld.png", "HelloWorld.png", "HelloWorld.png"
    showAdBtn = cocos2d::ui::Button::create();
    showAdBtn->setTitleText("showAd");
    showAdBtn->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    showAdBtn->addClickEventListener([&](Ref* sender){
        CCLOG("play ad button on click");
        VunglePubAd::showAd();
    });
    this->addChild(showAdBtn,0);
    
    showAdWithOptionsBtn = cocos2d::ui::Button::create();
    showAdWithOptionsBtn->setPosition(Vec2(visibleSize.width/2 - 100, visibleSize.height/2 + origin.y));
    showAdWithOptionsBtn->setTitleText("showAdWithOptions");
    showAdWithOptionsBtn->addClickEventListener([&](Ref* sender){
        CCLOG("play ad button on click");
        VunglePubAd::showAdWithOptions();
    });
    this->addChild(showAdWithOptionsBtn,0);
    
    showIncentivizedAdBtn = cocos2d::ui::Button::create();
    showIncentivizedAdBtn->setPosition(Vec2(visibleSize.width/2 + 100, visibleSize.height/2 + origin.y));
    showIncentivizedAdBtn->setTitleText("showIncentivizedAd");
    showIncentivizedAdBtn->addClickEventListener([&](Ref* sender){
        CCLOG("play ad button on click");
        VunglePubAd::showIncentivizedAd();
    });
    this->addChild(showIncentivizedAdBtn,0);

    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("VungleLogo.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x,
                             visibleSize.height + origin.y-sprite->getContentSize().height));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    setBtnEnable(false);
    return true;
}


void HelloWorld::setBtnEnable(bool status)
{
    CCLOG("show log from HelloWorld");
    
    showAdBtn->setBright(status);
    showAdBtn->setEnabled(status);
    showAdBtn->setTouchEnabled(status);
    
    showAdWithOptionsBtn->setBright(status);
    showAdWithOptionsBtn->setEnabled(status);
    showAdWithOptionsBtn->setTouchEnabled(status);
    
    showIncentivizedAdBtn->setBright(status);
    showIncentivizedAdBtn->setEnabled(status);
    showIncentivizedAdBtn->setTouchEnabled(status);
    
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}