#include "PauseScene.h"
#include "Niveau1.h"
#include "Niveau2.h"

USING_NS_CC;

// La creation de la scene : 

Scene* Niveau1::createScene()
{
    return Niveau1::create();
}


static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


bool Niveau1::init()
{

    if ( !Scene::init() )
    {
        return false;
    }

        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();


        // LE PLAN DU JEUX: 

        auto PlanNiveau1 = MenuItemImage::create("Niveau1/PlanLevel1.png", "MainMenuScreen/Game_Title.png");
        PlanNiveau1->setPosition(Point((visibleSize.width / 2) +
        origin.x, (visibleSize.height / 2) + origin.y));
        this->addChild(PlanNiveau1, -1);

        // ICON DE PAUSE: 
        auto IconPause = MenuItemImage::create("LevelOne/PauseIcon.png", "GameScreen/Pause_Button(Click).png",
        CC_CALLBACK_1(Niveau1::GoToPauseScene, this));
        IconPause->setPosition(Point(IconPause->getContentSize().width -
        (IconPause->getContentSize().width / 4) + origin.x,
        visibleSize.height - IconPause->getContentSize().height +
        (IconPause->getContentSize().width / 4) + origin.y));
 

        //CREATION DU BALLON:
         Sprite1 = Sprite::create("Niveau1/SPRITE1.png");
         Sprite1->setPosition(Point(121, 37));
         this->addChild(Sprite1, 1);

        //DECLARATION D'UN ECOUTEUR DES TOUCHES: 
        _2ndListner = EventListenerKeyboard::create();
        _2ndListner->onKeyPressed = CC_CALLBACK_2(Niveau1::MoveBall, this);
        _eventDispatcher->addEventListenerWithFixedPriority(_2ndListner, 1);
        
        //CREATION DE MENU QUI CONTIENT L'ICON DE PAUSE: 
        auto menu = Menu::create(IconPause, NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu);

    return true;
}

//DEFINITION DES FONCTIONS BRAVO(), GoToPauseScene() et MoveBall().

void Niveau1::GoToPauseScene(cocos2d::Ref* pSender)
{
    auto scene = PauseMenu::createScene();

    Director::getInstance()->pushScene(scene);
}

void Niveau1::Bravo() {
    auto Saute = JumpBy::create(2.0, Point(0, 0), 15, 5);
    Sprite1->runAction(Saute);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto Next = MenuItemImage::create("NextLevel.png", "PauseScreen/Menu_Button(Click).png",
        CC_CALLBACK_1(Niveau1::GoToTheNextLevel, this));
    auto MenuNext = Menu::create(Next, NULL);
    this->addChild(MenuNext, 6);

    auto Bravo = Sprite::create("Bravo1.png");
    Bravo->setPosition(Point((visibleSize.width / 2) +
        origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(Bravo, 5);
}
void Niveau1::MoveBall(EventKeyboard::KeyCode Keycode, Event* event) {

    Vec2 _Location = Sprite1->getPosition();
    auto Saute = JumpBy::create(2.0, Point(0, 0), 15, 5);

// DECLARATION DES ACTIONS : 

    auto L1 = MoveBy::create(0.1, Point(-160, 0));
    auto L2 = MoveBy::create(0.1, Point(-80, 0));
    auto L3 = MoveBy::create(0.1, Point(-240, 0));

    auto R1 = MoveBy::create(0.1, Point(240, 0));
    auto R2 = MoveBy::create(0.1, Point(240, 0));
    auto R3 = MoveBy::create(0.1, Point(80, 0));
    auto R4 = MoveBy::create(0.1, Point(160, 0));

    auto UP1 = MoveBy::create(0.1, Point(0,70));
    auto UP2 = MoveBy::create(0.1, Point(0, 245));
    auto UP3 = MoveBy::create(0.1, Point(0, 70));

    auto DOWN1 = MoveBy::create(0.1, Point(0, -70));
    auto DOWN2 = MoveBy::create(0.1, Point(0, -70));
    auto DOWN3 = MoveBy::create(0.1, Point(0, -245));

    switch (Keycode) {

    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:

        if (_Location.x == 361 && _Location.y == 37) {
            Sprite1->runAction(L1);
            for (int x = 0; x < 5; x++) {
                auto REC = Sprite::create("Niveau1/COLOR1.png");
                REC->setPosition(360 - (x * (REC->getContentSize().width)), 37);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 201 && _Location.y == 282) {
            Sprite1->runAction(L2);
            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau1/COLOR1.png");
                REC->setPosition(201 - (x * (REC->getContentSize().width)),283);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 361 && _Location.y == 282) {
            Sprite1->runAction(L2);
            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau1/COLOR1.png");
                REC->setPosition(360 - (x * (REC->getContentSize().width)), 283);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 361 && _Location.y == 212) {
            Sprite1->runAction(L3);
        }
        if (_Location.x == 361 && _Location.y == 107) {
            Sprite1->runAction(L3);
        }
        if (_Location.x == 281 && _Location.y == 37) {
            Sprite1->runAction(L2);
        }

        break;

    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:

        if (_Location.x == 121 && _Location.y == 107) {
            Sprite1->runAction(R1);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau1/COLOR1.png");
                REC->setPosition(121 + (x * (REC->getContentSize().width)), 107);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 121 && _Location.y == 212) {
            Sprite1->runAction(R2);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau1/COLOR1.png");
                REC->setPosition(121 + (x * (REC->getContentSize().width)), 212.5);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 281 && _Location.y == 282) {
            Sprite1->runAction(R3);
        }
        if (_Location.x == 121 && _Location.y == 282) {
            Sprite1->runAction(R3);
        }
        if (_Location.x == 201 && _Location.y == 37) {
            Sprite1->runAction(R4);
        }
        if (_Location.x == 281 && _Location.y == 37) {
            Sprite1->runAction(R3);
        }
        break;

    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        if (_Location.x == 121 && _Location.y == 37) {
            Sprite1->runAction(UP1);
            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau1/COLOR1.png");
                REC->setPosition(121, 37 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }

        if (_Location.x == 201 && _Location.y == 37) {
            Sprite1->runAction(UP2);
            for (int x = 0; x < 8; x++) {
                auto REC = Sprite::create("Niveau1/COLOR1.png");
                REC->setPosition(201, 37 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        
        if (_Location.x == 361 && _Location.y == 212) {
            Sprite1->runAction(UP3);
            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau1/COLOR1.png");
                REC->setPosition(361, 212.5 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 281 && _Location.y == 37) {
            Sprite1->runAction(UP2);
        }

        if (_Location.x == 121 && _Location.y == 212) {
            Sprite1->runAction(UP1);
        }
        if (_Location.x == 361 && _Location.y == 37) {
            Sprite1->runAction(UP1);
        }
        break;


    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:

        if (_Location.x == 361 && _Location.y == 107) {
            Sprite1->runAction(DOWN1);
            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau1/COLOR1.png");
                REC->setPosition(360, 107 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }

        if (_Location.x == 121 && _Location.y == 282) {
            Sprite1->runAction(DOWN2);
            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau1/COLOR1.png");
                REC->setPosition(121, 283 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 281 && _Location.y == 282) {
            Sprite1->runAction(DOWN3);
            for (int x = 0; x < 8; x++) {
                auto REC = Sprite::create("Niveau1/COLOR1.png");
                REC->setPosition(281, 283 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
            Bravo();
        }
        if (_Location.x == 361 && _Location.y == 282) {
            Sprite1->runAction(DOWN2);
        }
        if (_Location.x == 201 && _Location.y == 282) {
            Sprite1->runAction(DOWN3);
        }
        if (_Location.x == 121 && _Location.y == 107) {
            Sprite1->runAction(DOWN2);
        }
     
        break;
    }
}

/* LA FONCTION GoToTheNextLevel CREE UNE SCENE DE LA 2EM NIVEAU ET CHANGE LA SCENE ACTUELLE PAR LA NOUVELLE SCENE*/

void Niveau1::GoToTheNextLevel(cocos2d::Ref* pSender)
{
    auto scene = Niveau2::createScene();

    Director::getInstance()->pushScene(scene);
}