#include "MainMenuScene.h"
#include "Niveau1.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

bool MainMenu::init()
{
    if (!Scene::init())
    {
        return false;
    }

    // Obtenir la taille de l'écran visible et l'origine
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Créer le menu avec un élément "Play"
    MenuItemImage* playItem = MenuItemImage::create("MainMenu/CloseNormal.png", "MainMenu/CloseNormal.png", CC_CALLBACK_1(MainMenu::GoToGameScene, this));
    Menu* menu = Menu::create(playItem, nullptr);
    menu->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(menu);

    // Ajouter un sprite d'arrière-plan
    Sprite* backgroundSprite = Sprite::create("MainMenu/BackgroundMenu.png");
    backgroundSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(backgroundSprite, -2);

    return true;
}

void MainMenu::GoToGameScene(Ref* pSender)
{
    // Passer à la scène du premier niveau (Niveau1)
    Director::getInstance()->replaceScene(Niveau1::createScene());
}

