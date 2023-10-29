#include "PauseScene.h"
#include "Niveau1.h"
#include "Niveau3.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* Niveau3::createScene()
{
    auto scene = Scene::createWithPhysics();
   //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto layer = Niveau3::create();
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


bool Niveau3::init()
{

    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

        auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
        auto edgeNode = Node::create();
        edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        edgeNode->setPhysicsBody(edgeBody);
        this->addChild(edgeNode);

        auto PlanNiveau2 = MenuItemImage::create("Niveau3/PlanLevel3.png", "MainMenuScreen/Game_Title.png");
        PlanNiveau2->setPosition(Point((visibleSize.width / 2) +
        origin.x, (visibleSize.height / 2) + origin.y));
        this->addChild(PlanNiveau2, -1);

        auto IconPause = MenuItemImage::create("LevelOne/PauseIcon.png", "GameScreen/Pause_Button(Click).png",
        CC_CALLBACK_1(Niveau3::GoToPauseScene, this));
        IconPause->setPosition(Point(IconPause->getContentSize().width -
        (IconPause->getContentSize().width / 4) + origin.x,
        visibleSize.height - IconPause->getContentSize().height +
        (IconPause->getContentSize().width / 4) + origin.y));
 

        //Ballon:
         Sprite3 = Sprite::create("Niveau3/SPRITE3.png");
         Sprite3->setPosition(Point(160, 37));
         auto SpriteBody = PhysicsBody::createCircle((Sprite3->getContentSize().width / 2.5), PhysicsMaterial(0, 1, 0));
         SpriteBody->setCollisionBitmask(0);
         SpriteBody->setDynamic(false);
         SpriteBody->setContactTestBitmask(true);
         Sprite3->setPhysicsBody(SpriteBody);
         this->addChild(Sprite3, 1);



         auto contactListener =
             EventListenerPhysicsContact::create();
         contactListener->onContactBegin =
             CC_CALLBACK_1(Niveau3::onContactBegin, this);
         this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

        _2ndListner = EventListenerKeyboard::create();
        _2ndListner->onKeyPressed = CC_CALLBACK_2(Niveau3::MoveBall, this);
        _eventDispatcher->addEventListenerWithFixedPriority(_2ndListner, 1);

        auto menu = Menu::create(IconPause, NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu);



        //Creation des obstacles: 

        //OBS 1 
        OB1 = Sprite::create("Niveau3/OBS3.png");
        OB1->setPosition(198, 37);
        auto OB1B = PhysicsBody::createBox(OB1->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB1B->setDynamic(false);
        OB1B->setCollisionBitmask(1);
        OB1B->setContactTestBitmask(true);
        OB1->setPhysicsBody(OB1B);
        this->addChild(OB1);

        //OBS 2
        OB2 = Sprite::create("Niveau3/OBS3.png");
        OB2->setPosition(238, 37);
        auto OB2B = PhysicsBody::createBox(OB2->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB2B->setDynamic(false);
        OB2B->setCollisionBitmask(2);
        OB2B->setContactTestBitmask(true);
        OB2->setPhysicsBody(OB2B);
        this->addChild(OB2);

        //OBS 3
        OB3 = Sprite::create("Niveau3/OBS3.png");
        OB3->setPosition(318, 37);
        auto OB3B = PhysicsBody::createBox(OB3->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB3B->setDynamic(false);
        OB3B->setCollisionBitmask(3);
        OB3B->setContactTestBitmask(true);
        OB3->setPhysicsBody(OB3B);
        this->addChild(OB3);

        //OBS 4
        OB4 = Sprite::create("Niveau3/OBS3.png");
        OB4->setPosition(358, 37);
        auto OB4B = PhysicsBody::createBox(OB4->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB4B->setDynamic(false);
        OB4B->setCollisionBitmask(4);
        OB4B->setContactTestBitmask(true);
        OB4->setPhysicsBody(OB4B);
        this->addChild(OB4);

        //OBS 5
        OB5 = Sprite::create("Niveau3/OBS3.png");
        OB5->setPosition(120, 72);
        auto OB5B = PhysicsBody::createBox(OB5->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB5B->setDynamic(false);
        OB5B->setCollisionBitmask(5);
        OB5B->setContactTestBitmask(true);
        OB5->setPhysicsBody(OB5B);
        this->addChild(OB5);

        //OBS 6
        OB6 = Sprite::create("Niveau3/OBS3.png");
        OB6->setPosition(158, 72);
        auto OB6B = PhysicsBody::createBox(OB6->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB6B->setDynamic(false);
        OB6B->setCollisionBitmask(6);
        OB6B->setContactTestBitmask(true);
        OB6->setPhysicsBody(OB6B);
        this->addChild(OB6);

        //OBS 7
        OB7 = Sprite::create("Niveau3/OBS3.png");
        OB7->setPosition(198, 72);
        auto OB7B = PhysicsBody::createBox(OB7->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB7B->setDynamic(false);
        OB7B->setCollisionBitmask(7);
        OB7B->setContactTestBitmask(true);
        OB7->setPhysicsBody(OB7B);
        this->addChild(OB7);

        //OBS 8
        OB8 = Sprite::create("Niveau3/OBS3.png");
        OB8->setPosition(238, 72);
        auto OB8B = PhysicsBody::createBox(OB8->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB8B->setDynamic(false);
        OB8B->setCollisionBitmask(8);
        OB8B->setContactTestBitmask(true);
        OB8->setPhysicsBody(OB8B);
        this->addChild(OB8);

        //OBS 9
        OB9 = Sprite::create("Niveau3/OBS3.png");
        OB9->setPosition(278, 72);
        auto OB9B = PhysicsBody::createBox(OB9->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB9B->setDynamic(false);
        OB9B->setCollisionBitmask(9);
        OB9B->setContactTestBitmask(true);
        OB9->setPhysicsBody(OB9B);
        this->addChild(OB9);

        //OBS 10
        OB10 = Sprite::create("Niveau3/OBS3.png");
        OB10->setPosition(318, 72);
        auto OB10B = PhysicsBody::createBox(OB10->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB10B->setDynamic(false);
        OB10B->setCollisionBitmask(10);
        OB10B->setContactTestBitmask(true);
        OB10->setPhysicsBody(OB10B);
        this->addChild(OB10);

        //OBS 11
        OB11 = Sprite::create("Niveau3/OBS3.png");
        OB11->setPosition(358, 72);
        auto OB11B = PhysicsBody::createBox(OB11->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB11B->setDynamic(false);
        OB11B->setCollisionBitmask(11);
        OB11B->setContactTestBitmask(true);
        OB11->setPhysicsBody(OB11B);
        this->addChild(OB11);

       //OBS 12
        OB12 = Sprite::create("Niveau3/OBS3.png");
        OB12->setPosition(120, 107);
        auto OB12B = PhysicsBody::createBox(OB12->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB12B->setDynamic(false);
        OB12B->setCollisionBitmask(12);
        OB12B->setContactTestBitmask(true);
        OB12->setPhysicsBody(OB12B);
        this->addChild(OB12);

        //OBS 13
        OB13 = Sprite::create("Niveau3/OBS3.png");
        OB13->setPosition(158, 107);
        auto OB13B = PhysicsBody::createBox(OB13->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB13B->setDynamic(false);
        OB13B->setCollisionBitmask(13);
        OB13B->setContactTestBitmask(true);
        OB13->setPhysicsBody(OB13B);
        this->addChild(OB13,1);

        //OBS 14
        OB14 = Sprite::create("Niveau3/OBS3.png");
        OB14->setPosition(238, 107);
        auto OB14B = PhysicsBody::createBox(OB14->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB14B->setDynamic(false);
        OB14B->setCollisionBitmask(14);
        OB14B->setContactTestBitmask(true);
        OB14->setPhysicsBody(OB14B);
        this->addChild(OB14);

        //OBS 15
        OB15 = Sprite::create("Niveau3/OBS3.png");
        OB15->setPosition(318, 107);
        auto OB15B = PhysicsBody::createBox(OB15->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB15B->setDynamic(false);
        OB15B->setCollisionBitmask(15);
        OB15B->setContactTestBitmask(true);
        OB15->setPhysicsBody(OB15B);
        this->addChild(OB15);

        //OBS 16
        OB16 = Sprite::create("Niveau3/OBS3.png");
        OB16->setPosition(120, 142);
        auto OB16B = PhysicsBody::createBox(OB16->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB16B->setDynamic(false);
        OB16B->setCollisionBitmask(16);
        OB16B->setContactTestBitmask(true);
        OB16->setPhysicsBody(OB16B);
        this->addChild(OB16);

        //OBS 17
        OB17 = Sprite::create("Niveau3/OBS3.png");
        OB17->setPosition(158, 142);
        auto OB17B = PhysicsBody::createBox(OB17->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB17B->setDynamic(false);
        OB17B->setCollisionBitmask(17);
        OB17B->setContactTestBitmask(true);
        OB17->setPhysicsBody(OB17B);
        this->addChild(OB17);

        //OBS 18
        OB18 = Sprite::create("Niveau3/OBS3.png");
        OB18->setPosition(198, 142);
        auto OB18B = PhysicsBody::createBox(OB18->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB18B->setDynamic(false);
        OB18B->setCollisionBitmask(18);
        OB18B->setContactTestBitmask(true);
        OB18->setPhysicsBody(OB18B);
        this->addChild(OB18);

        //OBS 19
        OB19 = Sprite::create("Niveau3/OBS3.png");
        OB19->setPosition(238, 142);
        auto OB19B = PhysicsBody::createBox(OB19->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB19B->setDynamic(false);
        OB19B->setCollisionBitmask(19);
        OB19B->setContactTestBitmask(true);
        OB19->setPhysicsBody(OB19B);
        this->addChild(OB19);

        //OBS 20
        OB20 = Sprite::create("Niveau3/OBS3.png");
        OB20->setPosition(278, 142);
        auto OB20B = PhysicsBody::createBox(OB20->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB20B->setDynamic(false);
        OB20B->setCollisionBitmask(20);
        OB20B->setContactTestBitmask(true);
        OB20->setPhysicsBody(OB20B);
        this->addChild(OB20);

        //OBS 21
        OB21 = Sprite::create("Niveau3/OBS3.png");
        OB21->setPosition(318, 142);
        auto OB21B = PhysicsBody::createBox(OB21->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB21B->setDynamic(false);
        OB21B->setCollisionBitmask(21);
        OB21B->setContactTestBitmask(true);
        OB21->setPhysicsBody(OB21B);
        this->addChild(OB21);

        //OBS 22
        OB22 = Sprite::create("Niveau3/OBS3.png");
        OB22->setPosition(358, 142);
        auto OB22B = PhysicsBody::createBox(OB22->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB22B->setDynamic(false);
        OB22B->setCollisionBitmask(22);
        OB22B->setContactTestBitmask(true);
        OB22->setPhysicsBody(OB22B);
        this->addChild(OB22);

        //OBS 23
        OB23 = Sprite::create("Niveau3/OBS3.png");
        OB23->setPosition(120, 177);
        auto OB23B = PhysicsBody::createBox(OB23->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB23B->setDynamic(false);
        OB23B->setCollisionBitmask(23);
        OB23B->setContactTestBitmask(true);
        OB23->setPhysicsBody(OB23B);
        this->addChild(OB23);

        //OBS 24
        OB24 = Sprite::create("Niveau3/OBS3.png");
        OB24->setPosition(158, 177);
        auto OB24B = PhysicsBody::createBox(OB24->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB24B->setDynamic(false);
        OB24B->setCollisionBitmask(24);
        OB24B->setContactTestBitmask(true);
        OB24->setPhysicsBody(OB24B);
        this->addChild(OB24);

        //OBS 25
        OB25 = Sprite::create("Niveau3/OBS3.png");
        OB25->setPosition(238, 177);
        auto OB25B = PhysicsBody::createBox(OB25->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB25B->setDynamic(false);
        OB25B->setCollisionBitmask(25);
        OB25B->setContactTestBitmask(true);
        OB25->setPhysicsBody(OB25B);
        this->addChild(OB25);

        //OBS 26
        OB26 = Sprite::create("Niveau3/OBS3.png");
        OB26->setPosition(318, 177);
        auto OB26B = PhysicsBody::createBox(OB26->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB26B->setDynamic(false);
        OB26B->setCollisionBitmask(26);
        OB26B->setContactTestBitmask(true);
        OB26->setPhysicsBody(OB26B);
        this->addChild(OB26);

        //OBS 27
        OB27 = Sprite::create("Niveau3/OBS3.png");
        OB27->setPosition(358, 177);
        auto OB27B = PhysicsBody::createBox(OB27->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB27B->setDynamic(false);
        OB27B->setCollisionBitmask(27);
        OB27B->setContactTestBitmask(true);
        OB27->setPhysicsBody(OB27B);
        this->addChild(OB27);

        //OBS 28
        OB28 = Sprite::create("Niveau3/OBS3.png");
        OB28->setPosition(198, 212);
        auto OB28B = PhysicsBody::createBox(OB28->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB28B->setDynamic(false);
        OB28B->setCollisionBitmask(28);
        OB28B->setContactTestBitmask(true);
        OB28->setPhysicsBody(OB28B);
        this->addChild(OB28);

        //OBS 29
        OB29 = Sprite::create("Niveau3/OBS3.png");
        OB29->setPosition(238, 212);
        auto OB29B = PhysicsBody::createBox(OB29->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB29B->setDynamic(false);
        OB29B->setCollisionBitmask(29);
        OB29B->setContactTestBitmask(true);
        OB29->setPhysicsBody(OB29B);
        this->addChild(OB29);

        //OBS 30
        OB30 = Sprite::create("Niveau3/OBS3.png");
        OB30->setPosition(278, 212);
        auto OB30B = PhysicsBody::createBox(OB30->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB30B->setDynamic(false);
        OB30B->setCollisionBitmask(30);
        OB30B->setContactTestBitmask(true);
        OB30->setPhysicsBody(OB30B);
        this->addChild(OB30);


        //OBS 31
        OB31 = Sprite::create("Niveau3/OBS3.png");
        OB31->setPosition(318, 212);
        auto OB31B = PhysicsBody::createBox(OB31->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB31B->setDynamic(false);
        OB31B->setCollisionBitmask(31);
        OB31B->setContactTestBitmask(true);
        OB31->setPhysicsBody(OB31B);
        this->addChild(OB31);

        //OBS 32
        OB32 = Sprite::create("Niveau3/OBS3.png");
        OB32->setPosition(358, 212);
        auto OB32B = PhysicsBody::createBox(OB32->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB32B->setDynamic(false);
        OB32B->setCollisionBitmask(32);
        OB32B->setContactTestBitmask(true);
        OB32->setPhysicsBody(OB32B);
        this->addChild(OB32);

        //OBS 33
        OB33 = Sprite::create("Niveau3/OBS3.png");
        OB33->setPosition(158, 247);
        auto OB33B = PhysicsBody::createBox(OB33->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB33B->setDynamic(false);
        OB33B->setCollisionBitmask(33);
        OB33B->setContactTestBitmask(true);
        OB33->setPhysicsBody(OB33B);
        this->addChild(OB33);

        //OBS 34
        OB34 = Sprite::create("Niveau3/OBS3.png");
        OB34->setPosition(198, 247);
        auto OB34B = PhysicsBody::createBox(OB34->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB34B->setDynamic(false);
        OB34B->setCollisionBitmask(34);
        OB34B->setContactTestBitmask(true);
        OB34->setPhysicsBody(OB34B);
        this->addChild(OB34);

        //OBS 35
        OB35 = Sprite::create("Niveau3/OBS3.png");
        OB35->setPosition(238, 247);
        auto OB35B = PhysicsBody::createBox(OB35->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB35B->setDynamic(false);
        OB35B->setCollisionBitmask(35);
        OB35B->setContactTestBitmask(true);
        OB35->setPhysicsBody(OB35B);
        this->addChild(OB35);

        //OBS 36
        OB36 = Sprite::create("Niveau3/OBS3.png");
        OB36->setPosition(278, 247);
        auto OB36B = PhysicsBody::createBox(OB36->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB36B->setDynamic(false);
        OB36B->setCollisionBitmask(36);
        OB36B->setContactTestBitmask(true);
        OB36->setPhysicsBody(OB36B);
        this->addChild(OB36);

        //OBS 37
        OB37 = Sprite::create("Niveau3/OBS3.png");
        OB37->setPosition(358, 247);
        auto OB37B = PhysicsBody::createBox(OB37->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB37B->setDynamic(false);
        OB37B->setCollisionBitmask(37);
        OB37B->setContactTestBitmask(true);
        OB37->setPhysicsBody(OB37B);
        this->addChild(OB37);

        //OBS 38
        OB38 = Sprite::create("Niveau3/OBS3.png");
        OB38->setPosition(158, 282);
        auto OB38B = PhysicsBody::createBox(OB38->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB38B->setDynamic(false);
        OB38B->setCollisionBitmask(38);
        OB38B->setContactTestBitmask(true);
        OB38->setPhysicsBody(OB38B);
        this->addChild(OB38);

        //OBS 39
        OB39 = Sprite::create("Niveau3/OBS3.png");
        OB39->setPosition(198, 282);
        auto OB39B = PhysicsBody::createBox(OB39->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB39B->setDynamic(false);
        OB39B->setCollisionBitmask(39);
        OB39B->setContactTestBitmask(true);
        OB39->setPhysicsBody(OB39B);
        this->addChild(OB39);


        //OBS 40
        OB40 = Sprite::create("Niveau3/OBS3.png");
        OB40->setPosition(238, 282);
        auto OB40B = PhysicsBody::createBox(OB40->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB40B->setDynamic(false);
        OB40B->setCollisionBitmask(40);
        OB40B->setContactTestBitmask(true);
        OB40->setPhysicsBody(OB40B);
        this->addChild(OB40);

        //OBS 41
        OB41 = Sprite::create("Niveau3/OBS3.png");
        OB41->setPosition(278, 282);
        auto OB41B = PhysicsBody::createBox(OB41->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB41B->setDynamic(false);
        OB41B->setCollisionBitmask(41);
        OB41B->setContactTestBitmask(true);
        OB41->setPhysicsBody(OB41B);
        this->addChild(OB41);

        //OBS 42
        OB42 = Sprite::create("Niveau3/OBS3.png");
        OB42->setPosition(318, 282);
        auto OB42B = PhysicsBody::createBox(OB42->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB42B->setDynamic(false);
        OB42B->setCollisionBitmask(42);
        OB42B->setContactTestBitmask(true);
        OB42->setPhysicsBody(OB42B);
        this->addChild(OB42);

        //OBS 43
        OB43 = Sprite::create("Niveau3/OBS3.png");
        OB43->setPosition(357, 282);
        auto OB43B = PhysicsBody::createBox(OB43->getContentSize() / 2, PhysicsMaterial(0.0f, 0.0f, 0.0f));
        OB43B->setDynamic(false);
        OB43B->setCollisionBitmask(43);
        OB43B->setContactTestBitmask(true);
        OB43->setPhysicsBody(OB43B);
        this->addChild(OB43);

    return true;
}

void Niveau3::GoToPauseScene(cocos2d::Ref* pSender)
{
    auto scene = PauseMenu::createScene();

    Director::getInstance()->pushScene(scene);
}
void Niveau3::Repeter(cocos2d::Ref* pSender)
{
    auto scene = Niveau1::createScene();

    Director::getInstance()->pushScene(scene);
}
void Niveau3::MoveBall(EventKeyboard::KeyCode Keycode, Event* event) {

    Vec2 _Location = Sprite3->getPosition();
    
    //DECLARATION DES ACTIONS:

    auto L40 = MoveBy::create(0.1, Point(-40, 0));
    auto L80 = MoveBy::create(0.1, Point(-80, 0));
    auto L120 = MoveBy::create(0.1, Point(-120, 0));
    auto L160 = MoveBy::create(0.1, Point(-160, 0));
    auto L200 = MoveBy::create(0.1, Point(-200, 0));
    auto L240 = MoveBy::create(0.1, Point(-240, 0));


    auto R40 = MoveBy::create(0.1, Point(40, 0));
    auto R80 = MoveBy::create(0.1, Point(80, 0));
    auto R120 = MoveBy::create(0.1, Point(120, 0));
    auto R160 = MoveBy::create(0.1, Point(160, 0));
    auto R200 = MoveBy::create(0.1, Point(200, 0));
    auto R240 = MoveBy::create(0.1, Point(240, 0));
    
    auto UP35 = MoveBy::create(0.1, Point(0, 35));
    auto UP70 = MoveBy::create(0.1, Point(0, 70));
    auto UP105 = MoveBy::create(0.1, Point(0, 105));
    auto UP140 = MoveBy::create(0.1, Point(0, 140));
    auto UP175 = MoveBy::create(0.1, Point(0, 175));
    auto UP210 = MoveBy::create(0.1, Point(0, 210));
    auto UP245 = MoveBy::create(0.1, Point(0, 245));

    auto DOWN35 = MoveBy::create(0.1, Point(0,-35));
    auto DOWN70 = MoveBy::create(0.1, Point(0,-70));
    auto DOWN105 = MoveBy::create(0.1, Point(0,-105));
    auto DOWN140 = MoveBy::create(0.1, Point(0,-140));
    auto DOWN175 = MoveBy::create(0.1, Point(0,-175));
    auto DOWN210 = MoveBy::create(0.1, Point(0,-210));
    auto DOWN245 = MoveBy::create(0.1, Point(0,-245));

    switch (Keycode) {

    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        if (_Location.x == 360 && _Location.y == 37) {
            Sprite3->runAction(L40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(358 - (x * (REC->getContentSize().width)), 37);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 72) {

            Sprite3->runAction(L240);
            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(358 - (x * (REC->getContentSize().width)), 72);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 142) {
            Sprite3->runAction(L240);

            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(358 - (x * (REC->getContentSize().width)), 142);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 212) {
            Sprite3->runAction(L160);

            for (int x = 0; x < 5; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(358 - (x * (REC->getContentSize().width)), 212);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 282) {
            Sprite3->runAction(L200);
            for (int x = 0; x < 6; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(358 - (x * (REC->getContentSize().width)), 282);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 320 && _Location.y == 212) {
            Sprite3->runAction(L120);
            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(318 - (x * (REC->getContentSize().width)), 212);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 280 && _Location.y == 212) {
            Sprite3->runAction(L80);

            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(278 - (x * (REC->getContentSize().width)), 212);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 280 && _Location.y == 247) {
            Sprite3->runAction(L120)
                ;
            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(278 - (x * (REC->getContentSize().width)), 247);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 280 && _Location.y == 282) {
            Sprite3->runAction(L120);

            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(278 - (x * (REC->getContentSize().width)), 282);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 240 && _Location.y == 37) {
            Sprite3->runAction(L80);

            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(238 - (x * (REC->getContentSize().width)), 37);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 240 && _Location.y == 282) {
            Sprite3->runAction(L80);

            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(238 - (x * (REC->getContentSize().width)), 282);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 200 && _Location.y == 282) {
            Sprite3->runAction(L40);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(198 - (x * (REC->getContentSize().width)), 282);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 177) {
            Sprite3->runAction(L40);
            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(158 - (x * (REC->getContentSize().width)), 177);
                addChild(REC, 0);
            }
        }
        break;

    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:

        if (_Location.x == 120 && _Location.y == 72) {
            Sprite3->runAction(R240);

            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(118 + (x * (REC->getContentSize().width)), 72);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 120 && _Location.y == 142) {
            Sprite3->runAction(R240);

            for (int x = 0; x < 7; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(118 + (x * (REC->getContentSize().width)), 142);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 120 && _Location.y == 177) {
            Sprite3->runAction(R40);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(118 + (x * (REC->getContentSize().width)), 177);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 37) {
            Sprite3->runAction(R80);
            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(158 + (x * (REC->getContentSize().width)), 37);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 247) {
            Sprite3->runAction(R120);

            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(158 + (x * (REC->getContentSize().width)), 247);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 282) {
            Sprite3->runAction(R200);

            for (int x = 0; x < 6; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(158 + (x * (REC->getContentSize().width)), 282);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 200 && _Location.y == 212) {
            Sprite3->runAction(R160);

            for (int x = 0; x < 5; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(198 + (x * (REC->getContentSize().width)), 212);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 200 && _Location.y == 282) {
            Sprite3->runAction(R160);

            for (int x = 0; x < 5; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(198 + (x * (REC->getContentSize().width)), 282);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 240 && _Location.y == 282) {
            Sprite3->runAction(R120);
            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(238 + (x * (REC->getContentSize().width)), 282);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 280 && _Location.y == 212) {
            Sprite3->runAction(R80);

            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(278 + (x * (REC->getContentSize().width)), 212);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 280 && _Location.y == 282) {
            Sprite3->runAction(R80);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(278 + (x * (REC->getContentSize().width)), 282);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 320 && _Location.y == 37) {
            Sprite3->runAction(R40);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(318 + (x * (REC->getContentSize().width)), 37);
                addChild(REC, 0);
            }
        }
        if (_Location.x == 320 && _Location.y == 212) {
            Sprite3->runAction(R40);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(318 + (x * (REC->getContentSize().width)), 212);
                addChild(REC, 0);
            }
        }


        break;

    case EventKeyboard::KeyCode::KEY_UP_ARROW:

        if (_Location.x == 160 && _Location.y == 37) {
            Sprite3->runAction(UP140);

            for (int x = 0; x < 5; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(158, 37 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }

        }
        if (_Location.x == 200 && _Location.y == 37) {
            Sprite3->runAction(UP35);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(198, 37 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 240 && _Location.y == 37) {
            Sprite3->runAction(UP245);

            for (int x = 0; x < 8; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(238, 37 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 320 && _Location.y == 37) {
            Sprite3->runAction(UP175);

            for (int x = 0; x < 6; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(318, 37 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 37) {
            Sprite3->runAction(UP35);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(358, 37 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 120 && _Location.y == 72) {
            Sprite3->runAction(UP105);

            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(120, 72 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 120 && _Location.y == 142) {
            Sprite3->runAction(UP35);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(120, 142 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 142) {
            Sprite3->runAction(UP140);

            for (int x = 0; x < 5; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(358, 142 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 200 && _Location.y == 212) {
            Sprite3->runAction(UP70);

            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(198, 212 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 280 && _Location.y == 212) {
            Sprite3->runAction(UP70);

            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(278, 212 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 212) {
            Sprite3->runAction(UP70);

            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(358, 212 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 247) {
            Sprite3->runAction(UP35);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(158, 247 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 280 && _Location.y == 247) {
            Sprite3->runAction(UP35);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(278, 247 + (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }


        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:

        if (_Location.x == 120 && _Location.y == 142) {
            Sprite3->runAction(DOWN70);
            
            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(120, 142 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 120 && _Location.y == 177) {
            Sprite3->runAction(DOWN105);

            for (int x = 0; x < 4; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(120, 177 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 177) {
            Sprite3->runAction(DOWN140);

            for (int x = 0; x < 5; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(158, 177 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 160 && _Location.y == 282) {
            Sprite3->runAction(DOWN35);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(158, 282 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 200 && _Location.y == 282) {
            Sprite3->runAction(DOWN70);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(198, 282 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 240 && _Location.y == 282) {
            Sprite3->runAction(DOWN245);

            for (int x = 0; x < 8; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(338, 282 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 280 && _Location.y == 247) {
            Sprite3->runAction(DOWN35);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(278, 247 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 280 && _Location.y == 282) {
            Sprite3->runAction(DOWN70);

            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(278, 282 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 320 && _Location.y == 212) {
            Sprite3->runAction(DOWN175);

            for (int x = 0; x < 6; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(318, 212 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 72) {
            Sprite3->runAction(DOWN35);

            for (int x = 0; x < 2; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(358 , 72 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 212) {
            Sprite3->runAction(DOWN70);

            for (int x = 0; x < 3; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(358, 212 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }
        if (_Location.x == 360 && _Location.y == 282) {
            Sprite3->runAction(DOWN140);

            for (int x = 0; x < 5; x++) {
                auto REC = Sprite::create("Niveau3/COLOR3.png");
                REC->setPosition(358, 282 - (x * (REC->getContentSize().height)));
                addChild(REC, 0);
            }
        }


        break;
    }

}

void Niveau3::Bravo() {
    auto Saute = JumpBy::create(2.0, Point(0, 0), 15, 5);
    Sprite3->runAction(Saute);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto Next = MenuItemImage::create("PauseScreen/Retry_Button.png", "PauseScreen/Menu_Button(Click).png",
        CC_CALLBACK_1(Niveau3::Repeter, this));
        auto MenuNext = Menu::create(Next, NULL);
        this->addChild(MenuNext, 6);

    auto Bravo = Sprite::create("Bravo3.png");
    Bravo->setPosition(Point((visibleSize.width / 2) +
    origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(Bravo, 5);
}

// DETECTION DE CONTACT AVEC LES OBSTACLES : 

bool Niveau3::onContactBegin(PhysicsContact& contact) {
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();
    static int x = 0;

    if (x != 43) {
        if ((1 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 1 == b->getCollisionBitmask()) {
            OB1->removeFromParent();
            x++;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((2 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 2 == b->getCollisionBitmask()) {
            OB2->removeFromParent();
            x++;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((3 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 3 == b->getCollisionBitmask()) {
            OB3->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((4 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 4 == b->getCollisionBitmask()) {
            OB4->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((5 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 5 == b->getCollisionBitmask()) {
            OB5->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((6 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 6 == b->getCollisionBitmask()) {
            OB6->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((7 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 7 == b->getCollisionBitmask()) {
            OB7->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((8 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 8 == b->getCollisionBitmask()) {
            OB8->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((9 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 9 == b->getCollisionBitmask()) {
            OB9->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((10 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 10 == b->getCollisionBitmask()) {
            OB10->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((11 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 11 == b->getCollisionBitmask()) {
            OB11->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((12 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 12 == b->getCollisionBitmask()) {
            OB12->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((13 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 13 == b->getCollisionBitmask()) {
            cocos2d::log("%d", x);
            OB13->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((14 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 14 == b->getCollisionBitmask()) {
            OB14->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((15 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 15 == b->getCollisionBitmask()) {
            OB15->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((16 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 16 == b->getCollisionBitmask()) {
            OB16->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((17 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 17 == b->getCollisionBitmask()) {
            OB17->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((18 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 18 == b->getCollisionBitmask()) {
            OB18->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((19 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 19 == b->getCollisionBitmask()) {
            OB19->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((20 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 20 == b->getCollisionBitmask()) {
            OB20->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((21 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 21 == b->getCollisionBitmask()) {
            OB21->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((22 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 22 == b->getCollisionBitmask()) {
            OB22->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((23 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 23 == b->getCollisionBitmask()) {
            OB23->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((24 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 24 == b->getCollisionBitmask()) {
            OB24->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((25 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 25 == b->getCollisionBitmask()) {
            OB25->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((26 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 26 == b->getCollisionBitmask()) {
            OB26->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((27 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 27 == b->getCollisionBitmask()) {
            OB27->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
       if ((28 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 28 == b->getCollisionBitmask()) {
            OB28->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((29 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 29 == b->getCollisionBitmask()) {
            OB29->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((30 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 30 == b->getCollisionBitmask()) {
            OB30->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((31 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 31 == b->getCollisionBitmask()) {
            OB31->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((32 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 32 == b->getCollisionBitmask()) {
            OB32->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((33 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 33 == b->getCollisionBitmask()) {
            OB33->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((34 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 34 == b->getCollisionBitmask()) {
            OB34->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((35 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 35 == b->getCollisionBitmask()) {
            OB35->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((36 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 36 == b->getCollisionBitmask()) {
            OB36->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((37 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 37 == b->getCollisionBitmask()) {
            OB37->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((38 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 38 == b->getCollisionBitmask()) {
            OB38->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((39 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 39 == b->getCollisionBitmask()) {
            OB39->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((40 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 40 == b->getCollisionBitmask()) {
            OB40->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((41 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 41 == b->getCollisionBitmask()) {
            OB41->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((42 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 42 == b->getCollisionBitmask()) {
            OB42->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }
        if ((43 == a->getCollisionBitmask()) && 0 == b->getCollisionBitmask() || (0 == a->getCollisionBitmask()) && 43 == b->getCollisionBitmask()) {
            OB43->removeFromParent();
            x = x + 1;
            cocos2d::log("%d", x);
            if (x == 43) {
                Bravo();
                x = 0;
            }
            return true;
        }

    }

    return 0;
}