#include "MainMenuScene.h"
#include "PauseScene.h"
#include "Niveau1.h"
#include "Niveau2.h"
#include "Niveau3.h"


USING_NS_CC;

Scene* PauseMenu::createScene()
{
    return PauseMenu::create();
}


static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool PauseMenu::init()
{

    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background1 = MenuItemImage::create("PauseScreen/menuBackround.png", "MainMenuScreen/Game_Title.png");
    background1->setPosition(Point((visibleSize.width / 2) +
        origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(background1, -1);

    auto resumeItem =
        MenuItemImage::create("PauseScreen/Resume_Button.png",
            "PauseScreen/Resume_Button(Click).png",
            CC_CALLBACK_1(PauseMenu::Resume, this));

    auto retryItem =
        MenuItemImage::create("PauseScreen/Retry_Button.png",
            "PauseScreen/Retry_Button(Click).png",
            CC_CALLBACK_1(PauseMenu::Retry, this));

    auto mainMenuItem =
        MenuItemImage::create("PauseScreen/Menu_Button.png",
            "PauseScreen/Menu_Button(Click).png",
            CC_CALLBACK_1(PauseMenu::GoToMainMenuScene, this));

   auto menu = Menu::create(resumeItem, retryItem, mainMenuItem, NULL);
   menu->alignItemsVerticallyWithPadding(visibleSize.height / 7.5);
    this->addChild(menu);

    return true;
}

void PauseMenu::Resume(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}
void PauseMenu::GoToMainMenuScene(cocos2d::Ref* pSender)
{
    auto scene = MainMenu::createScene();

    Director::getInstance()->popScene();
    Director::getInstance()->pushScene(scene);
}
void PauseMenu::Retry(cocos2d::Ref* pSender)
{
    auto scene = Niveau1::createScene();
    Director::getInstance()->popScene();
    Director::getInstance()->pushScene(scene);
}