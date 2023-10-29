#include "PauseScene.h"
#include "Niveau2.h"
#include "Niveau3.h"

USING_NS_CC;

Scene* Niveau2::createScene()
{
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto layer = Niveau2::create();
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;

}


static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


bool Niveau2::init()
{

    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

        // Creation des limites pour l'écran: 

        auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
        auto edgeNode = Node::create();
        edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        edgeNode->setPhysicsBody(edgeBody);
        this->addChild(edgeNode);

        /* Creatio d'un plan de niveau 2 + un bouton de pause + un menu qui contient ce bouton*/

        auto PlanNiveau2 = MenuItemImage::create("Niveau2/PlanLevel2.png", "MainMenuScreen/Game_Title.png");
        PlanNiveau2->setPosition(Point((visibleSize.width / 2) +
        origin.x, (visibleSize.height / 2) + origin.y));
        this->addChild(PlanNiveau2, -1);

        auto IconPause = MenuItemImage::create("LevelOne/PauseIcon.png", "GameScreen/Pause_Button(Click).png",
        CC_CALLBACK_1(Niveau2::GoToPauseScene, this));
        IconPause->setPosition(Point(IconPause->getContentSize().width -
        (IconPause->getContentSize().width / 4) + origin.x,
        visibleSize.height - IconPause->getContentSize().height +
        (IconPause->getContentSize().width / 4) + origin.y));
 


        //Creation de ballon :
         Sprite2 = Sprite::create("Niveau2/SPRITE2.png");
         Sprite2->setPosition(Point(120, 40));
         auto SpriteBody = PhysicsBody::createCircle((Sprite2->getContentSize().width / 2.5), PhysicsMaterial(0, 1, 0));
         SpriteBody->setCollisionBitmask(0);
         SpriteBody->setDynamic(false);
         SpriteBody->setContactTestBitmask(true);
         Sprite2->setPhysicsBody(SpriteBody);
         this->addChild(Sprite2, 1);

         /*On declare premièrement un événement qui détecte le keycode chaque fois que vous cliquez sur
         les touches de clavier, pour cela on utilise la fonction prédéfinie EventListenerKeyboard : : create().
         Après, comme une solution proposée j’ai choisi de travailler avec un switch qui a comme argument le keycode 
         de la touche de clavier avec 4 possibilités (Up, Down, Left and Right) dans chaque cas elle exécute 
         une partie de code.*/

         auto contactListener =
             EventListenerPhysicsContact::create();
         contactListener->onContactBegin =
             CC_CALLBACK_1(Niveau2::onContactBegin, this);
         this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

        _2ndListner = EventListenerKeyboard::create();
        _2ndListner->onKeyPressed = CC_CALLBACK_2(Niveau2::MoveBall, this);
        _eventDispatcher->addEventListenerWithFixedPriority(_2ndListner, 1);

        auto menu = Menu::create(IconPause, NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu);



        /*On crée un sprite non dynamique avec une position fixe.apès, on fait la création d’un corps physique 
        qui a la même taille que l’élement avec un identificateur diffirent que le sprite principale
        (Dans notre cas la balle a un CollisionBitMask = 0 et d’obstacle égale a 1).
        Les obstacles sont placés avec une manière qu’ils couvrent tout le plan ou bien les couloires principales de plan:*/ 

        //OBS 1 
        OB1 = Sprite::create("Niveau2/OBS2.png");
        OB1->setPosition(120, 80);
        auto OB1B = PhysicsBody::createBox(OB1->getContentSize()/2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB1B->setDynamic(false);
        OB1B->setCollisionBitmask(1);
        OB1B->setContactTestBitmask(1);
        OB1->setPhysicsBody(OB1B);
        this->addChild(OB1);

        //OBS 2
        OB2 = Sprite::create("Niveau2/OBS2.png");
        OB2->setPosition(120, 240);
        auto OB2B = PhysicsBody::createBox(OB2->getContentSize()/2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB2B->setDynamic(false);
        OB2B->setCollisionBitmask(2);
        OB2B->setContactTestBitmask(2);
        OB2->setPhysicsBody(OB2B);
        this->addChild(OB2);
        
        //OBS 3
        OB3 = Sprite::create("Niveau2/OBS2.png");
        OB3->setPosition(120, 280);
        auto OB3B = PhysicsBody::createBox(OB3->getContentSize()/2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB3B->setDynamic(false);
        OB3B->setCollisionBitmask(3);
        OB3B->setContactTestBitmask(3);
        OB3->setPhysicsBody(OB3B);
        this->addChild(OB3);

        //OBS 4
        OB4 = Sprite::create("Niveau2/OBS2.png");
        OB4->setPosition(160, 120);
        auto OB4B = PhysicsBody::createBox(OB4->getContentSize()/2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB4B->setDynamic(false);
        OB4B->setCollisionBitmask(4);
        OB4B->setContactTestBitmask(4);
        OB4->setPhysicsBody(OB4B);
        this->addChild(OB4);

        //OBS 5
        OB5 = Sprite::create("Niveau2/OBS2.png");
        OB5->setPosition(200, 40);
        auto OB5B = PhysicsBody::createBox(OB5->getContentSize()/2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB5B->setDynamic(false);
        OB5B->setCollisionBitmask(5);
        OB5B->setContactTestBitmask(5);
        OB5->setPhysicsBody(OB5B);
        this->addChild(OB5);

        //OBS 6
        OB6 = Sprite::create("Niveau2/OBS2.png");
        OB6->setPosition(200, 80);
        auto OB6B = PhysicsBody::createBox(OB6->getContentSize()/2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB6B->setDynamic(false);
        OB6B->setCollisionBitmask(6);
        OB6B->setContactTestBitmask(6);
        OB6->setPhysicsBody(OB6B);
        this->addChild(OB6);

        //OBS 7
        OB7 = Sprite::create("Niveau2/OBS2.png");
        OB7->setPosition(200, 160);
        auto OB7B = PhysicsBody::createBox(OB7->getContentSize()/2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB7B->setDynamic(false);
        OB7B->setCollisionBitmask(7);
        OB7B->setContactTestBitmask(7);
        OB7->setPhysicsBody(OB7B);
        this->addChild(OB7);

        //OBS 8
        OB8 = Sprite::create("Niveau2/OBS2.png");
        OB8->setPosition(200, 240);
        auto OB8B = PhysicsBody::createBox(OB8->getContentSize()/2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB8B->setDynamic(false);
        OB8B->setCollisionBitmask(8);
        OB8B->setContactTestBitmask(8);
        OB8->setPhysicsBody(OB8B);
        this->addChild(OB8);

        //OBS 9
        OB9 = Sprite::create("Niveau2/OBS2.png");
        OB9->setPosition(240, 120);
        auto OB9B = PhysicsBody::createBox(OB9->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB9B->setDynamic(false);
        OB9B->setCollisionBitmask(9);
        OB9B->setContactTestBitmask(9);
        OB9->setPhysicsBody(OB9B);
        this->addChild(OB9);

        //OBS 10
        OB10 = Sprite::create("Niveau2/OBS2.png");
        OB10->setPosition(240, 280);
        auto OB10B = PhysicsBody::createBox(OB10->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB10B->setDynamic(false);
        OB10B->setCollisionBitmask(10);
        OB10B->setContactTestBitmask(10);
        OB10->setPhysicsBody(OB10B);
        this->addChild(OB10);

        //OBS 11
        OB11 = Sprite::create("Niveau2/OBS2.png");
        OB11->setPosition(320, 200);
        auto OB11B = PhysicsBody::createBox(OB11->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB11B->setDynamic(false);
        OB11B->setCollisionBitmask(11);
        OB11B->setContactTestBitmask(11);
        OB11->setPhysicsBody(OB11B);
        this->addChild(OB11);

        //OBS 12
        OB12 = Sprite::create("Niveau2/OBS2.png");
        OB12->setPosition(356, 40);
        auto OB12B = PhysicsBody::createBox(OB12->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB12B->setDynamic(false);
        OB12B->setCollisionBitmask(12);
        OB12B->setContactTestBitmask(12);
        OB12->setPhysicsBody(OB12B);
        this->addChild(OB12);

        //OBS 13
        OB13 = Sprite::create("Niveau2/OBS2.png");
        OB13->setPosition(356, 280);
        auto OB13B = PhysicsBody::createBox(OB13->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB13B->setDynamic(false);
        OB13B->setCollisionBitmask(13);
        OB13B->setContactTestBitmask(13);
        OB13->setPhysicsBody(OB13B);
        this->addChild(OB13);

        //OBS 14
        OB14 = Sprite::create("Niveau2/OBS2.png");
        OB14->setPosition(356, 120);
        auto OB14B = PhysicsBody::createBox(OB14->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB14B->setDynamic(false);
        OB14B->setCollisionBitmask(14);
        OB14B->setContactTestBitmask(14);
        OB14->setPhysicsBody(OB14B);
        this->addChild(OB14);

        //OBS 15
        OB15 = Sprite::create("Niveau2/OBS2.png");
        OB15->setPosition(280, 280);
        auto OB15B = PhysicsBody::createBox(OB15->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB15B->setDynamic(false);
        OB15B->setCollisionBitmask(15);
        OB15B->setContactTestBitmask(15);
        OB15->setPhysicsBody(OB15B);
        this->addChild(OB15);
    return true;
}

void Niveau2::GoToPauseScene(cocos2d::Ref* pSender)
{
    auto scene = PauseMenu::createScene();

    Director::getInstance()->pushScene(scene);
}

void Niveau2::MoveBall(EventKeyboard::KeyCode Keycode, Event* event) {

    Vec2 _Location = Sprite2->getPosition();


// DECLARATION DES ACTIONS : 

    auto L40 = MoveBy::create(0.05, Point(-40, 0));
    auto L80 = MoveBy::create(0.05, Point(-80, 0));
    auto L120 = MoveBy::create(0.05, Point(-120, 0));
    auto L240 = MoveBy::create(0.05, Point(-240, 0));


    auto R40 = MoveBy::create(0.05, Point(40, 0));
    auto R80 = MoveBy::create(0.05, Point(80, 0));
    auto R120 = MoveBy::create(0.05, Point(120, 0));
    auto R240 = MoveBy::create(0.05, Point(240, 0));

    auto UP40 = MoveBy::create(0.05, Point(0, 40));
    auto UP80 = MoveBy::create(0.05, Point(0, 80));
    auto UP120 = MoveBy::create(0.05, Point(0, 120));
    auto UP160 = MoveBy::create(0.05, Point(0, 160));
    auto UP200 = MoveBy::create(0.05, Point(0, 200));
    auto UP240 = MoveBy::create(0.05, Point(0, 240));


    auto DOWN40 = MoveBy::create(0.05, Point(0,-40));
    auto DOWN80 = MoveBy::create(0.05, Point(0,-80));
    auto DOWN120 = MoveBy::create(0.05, Point(0,-120));
    auto DOWN160 = MoveBy::create(0.05, Point(0,-160));
    auto DOWN200 = MoveBy::create(0.05, Point(0,-200));
    auto DOWN240 = MoveBy::create(0.05, Point(0,-240));


    switch (Keycode) {

    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:

        if (_Location.x == 360 && _Location.y == 40) {
            Sprite2->runAction(L40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(357 - (x * (REC->getContentSize().width)), 40);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 80) {
            Sprite2->runAction(L240);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(357 - (x * (REC->getContentSize().width)), 80);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 160) {
            Sprite2->runAction(L240);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(357 - (x * (REC->getContentSize().width)), 160);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 240) {
            Sprite2->runAction(L240);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(358 - (x * (REC->getContentSize().width)), 240);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 280) {
            Sprite2->runAction(L120);
            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(357 - (x * (REC->getContentSize().width)), 280);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 320 && _Location.y == 280) {
            Sprite2->runAction(L80);
            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(320 - (x * (REC->getContentSize().width)), 280.5);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 240 && _Location.y == 40) {
            Sprite2->runAction(L120);
            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(240 - (x * (REC->getContentSize().width)), 40);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 40) {
            Sprite2->runAction(L40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(160 - (x * (REC->getContentSize().width)), 40);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 280) {
            Sprite2->runAction(L40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(160 - (x * (REC->getContentSize().width)), 280.5);
                addChild(REC, 0);
            }
        }

        break;

    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:

        if (_Location.x == 120 && _Location.y == 40) {
            Sprite2->runAction(R120);
            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(119 + (x * (REC->getContentSize().width)), 40);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 120 && _Location.y == 80) {
            Sprite2->runAction(R240);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(119 + (x * (REC->getContentSize().width)), 80);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 120 && _Location.y == 160) {
            Sprite2->runAction(R240);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(119 + (x * (REC->getContentSize().width)), 160);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 120 && _Location.y == 240) {
            Sprite2->runAction(R240);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(119 + (x * (REC->getContentSize().width)), 240);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 120 && _Location.y == 280) {
            Sprite2->runAction(R40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(119 + (x * (REC->getContentSize().width)), 280);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 40) {
            Sprite2->runAction(R80);
            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(159 + (x * (REC->getContentSize().width)), 40);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 240 && _Location.y == 280) {
            Sprite2->runAction(R120);
            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(238 + (x * (REC->getContentSize().width)), 280);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 320 && _Location.y == 280) {
            Sprite2->runAction(R40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(318 + (x * (REC->getContentSize().width)), 280.5);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 320 && _Location.y == 40) {
            Sprite2->runAction(R40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(319 + (x * (REC->getContentSize().width)), 40);
                addChild(REC, 0);
            }
        }
        break;

    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        if (_Location.x == 120 && _Location.y == 40) {
            Sprite2->runAction(UP40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(120 , 40 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 40) {
            Sprite2->runAction(UP240);
            for (int x = 0; x <7 ; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(160, 40.5 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 240 && _Location.y == 40) {
            Sprite2->runAction(UP240);

            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(240, 40 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 320 && _Location.y == 40) {
            Sprite2->runAction(UP240);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(319, 39.5 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 40) {
            Sprite2->runAction(UP120);
            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(358, 40.5 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 80) {
            Sprite2->runAction(UP80);
            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(358, 80.5 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 120 && _Location.y == 240) {
            Sprite2->runAction(UP40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(120, 240 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 240) {
            Sprite2->runAction(UP40);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(358, 240.5 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }

        break;


    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        if (_Location.x == 120 && _Location.y == 280) {
            Sprite2->runAction(DOWN40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(120, 280 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 280) {
            Sprite2->runAction(DOWN240);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(160, 280.5 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 240 && _Location.y == 280) {
            Sprite2->runAction(DOWN240);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(240, 280 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 320 && _Location.y == 280) {
            Sprite2->runAction(DOWN240);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(318, 280.5 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 280) {
            Sprite2->runAction(DOWN40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(358, 280.5 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 160) {
            Sprite2->runAction(DOWN120);
            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(358, 160.5 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 120 && _Location.y == 80) {
            Sprite2->runAction(DOWN40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(120, 80 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 80) {
            Sprite2->runAction(DOWN40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau2/COLOR2.png");
                REC->setPosition(358, 80.5 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        break;
    }
}

void Niveau2::GoToTheNextLevel(cocos2d::Ref* pSender)
{
    auto scene = Niveau3::createScene();

    Director::getInstance()->pushScene(scene);
}
void Niveau2::Bravo() {
    auto Saute = JumpBy::create(2.0, Point(0, 0), 15, 5);
    Sprite2->runAction(Saute);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto Next = MenuItemImage::create("NextLevel.png", "PauseScreen/Menu_Button(Click).png",
        CC_CALLBACK_1(Niveau2::GoToTheNextLevel, this));
    auto MenuNext = Menu::create(Next, NULL);
    this->addChild(MenuNext,6);

    auto Bravo = Sprite::create("Bravo2.png");
    Bravo->setPosition(Point((visibleSize.width / 2) +
        origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(Bravo,5);
}

bool Niveau2::onContactBegin(PhysicsContact& contact) {
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();
    
    static int y = 0;

    if (y != 15) {
        if ((1 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 1 == b->getCollisionBitmask()) {
            OB1->removeFromParent();
            y++;
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((2 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 2 == b->getCollisionBitmask()) {
            OB2->removeFromParent();
            y++;
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((3 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 3 == b->getCollisionBitmask()) {
            OB3->removeFromParent();
            y++;
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((4 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 4 == b->getCollisionBitmask()) {
            OB4->removeFromParent();
            y++;
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((5 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 5 == b->getCollisionBitmask()) {
            OB5->removeFromParent();
            y++;
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((6 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 6 == b->getCollisionBitmask()) {
            OB6->removeFromParent();
            y++;
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((7 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 7 == b->getCollisionBitmask()) {
            OB7->removeFromParent();
            y++;
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((8 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 8 == b->getCollisionBitmask()) {
            OB8->removeFromParent();
            y++;
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((9 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 9 == b->getCollisionBitmask()) {
            OB9->removeFromParent();
            y++;
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((10 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 10 == b->getCollisionBitmask()) {
            OB10->removeFromParent();
            y++;
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((11 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 11 == b->getCollisionBitmask()) {
            OB11->removeFromParent();
            y++;
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((12 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 12 == b->getCollisionBitmask()) {
            OB12->removeFromParent();
            y++;
    
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((13 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 13 == b->getCollisionBitmask()) {
            OB13->removeFromParent();
            y++;
   
            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((14 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 14 == b->getCollisionBitmask()) {
            OB14->removeFromParent();
            y++;

            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
        if ((15 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 15 == b->getCollisionBitmask()) {
            OB15->removeFromParent();
            y++;

            if (y == 15) {
                Bravo();
                y = 0;
            }
            return true;
        }
    }

    return 0;
}