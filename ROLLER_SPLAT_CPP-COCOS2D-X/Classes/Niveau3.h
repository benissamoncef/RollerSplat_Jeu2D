#ifndef __GAME_SCENEC_H__
#define __GAME_SCENEC_H__

#include "cocos2d.h"

class Niveau3 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    cocos2d::EventListenerKeyboard* _2ndListner;
    cocos2d::Sprite* Sprite3;

    virtual bool init();

    cocos2d::PhysicsWorld* sceneWorld;
    void SetPhysicsWorld(cocos2d::PhysicsWorld* world)
    {
        sceneWorld = world;
    };
   
    bool onContactBegin(cocos2d::PhysicsContact& contact);

    CREATE_FUNC(Niveau3);

    void Repeter(cocos2d::Ref* pSender);
    void Bravo();
    void GoToPauseScene(Ref* pSender);
    void GoToGameOverScene(Ref* pSender);
    void MoveBall(cocos2d::EventKeyboard::KeyCode KeyCode2, cocos2d::Event* event);

    //Les obstacles :
    cocos2d::Sprite* OB1;
    cocos2d::Sprite* OB2;
    cocos2d::Sprite* OB3;
    cocos2d::Sprite* OB4;
    cocos2d::Sprite* OB5;
    cocos2d::Sprite* OB6;
    cocos2d::Sprite* OB7;
    cocos2d::Sprite* OB8;
    cocos2d::Sprite* OB9;
    cocos2d::Sprite* OB10;
    cocos2d::Sprite* OB11;
    cocos2d::Sprite* OB12;
    cocos2d::Sprite* OB13;
    cocos2d::Sprite* OB14;
    cocos2d::Sprite* OB15;
    cocos2d::Sprite* OB16;
    cocos2d::Sprite* OB17;
    cocos2d::Sprite* OB18;
    cocos2d::Sprite* OB19;
    cocos2d::Sprite* OB20;
    cocos2d::Sprite* OB21;
    cocos2d::Sprite* OB22;
    cocos2d::Sprite* OB23;
    cocos2d::Sprite* OB24;
    cocos2d::Sprite* OB25;
    cocos2d::Sprite* OB26;
    cocos2d::Sprite* OB27;
    cocos2d::Sprite* OB28;
    cocos2d::Sprite* OB29;
    cocos2d::Sprite* OB30;
    cocos2d::Sprite* OB31;
    cocos2d::Sprite* OB32;
    cocos2d::Sprite* OB33;
    cocos2d::Sprite* OB34;
    cocos2d::Sprite* OB35;
    cocos2d::Sprite* OB36;
    cocos2d::Sprite* OB37;
    cocos2d::Sprite* OB38;
    cocos2d::Sprite* OB39;
    cocos2d::Sprite* OB40;
    cocos2d::Sprite* OB41;
    cocos2d::Sprite* OB42;
    cocos2d::Sprite* OB43;
};

#endif 
