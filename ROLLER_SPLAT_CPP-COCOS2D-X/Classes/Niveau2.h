#ifndef __GAME_SCENEB_H__
#define __GAME_SCENEB_H__

#include "cocos2d.h"

class Niveau2 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    cocos2d::EventListenerKeyboard* _2ndListner;
    
    
    cocos2d::Sprite* Sprite2;


    virtual bool init();

    cocos2d::PhysicsWorld* sceneWorld;

    void SetPhysicsWorld(cocos2d::PhysicsWorld* world)
    {
        sceneWorld = world;
    };
   
    bool onContactBegin(cocos2d::PhysicsContact& contact);

    CREATE_FUNC(Niveau2);

    void GoToTheNextLevel(cocos2d::Ref* pSender);
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

};

#endif 
