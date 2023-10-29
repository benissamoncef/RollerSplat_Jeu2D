#ifndef __GAME_SCENEA_H__
#define __GAME_SCENEA_H__

#include "cocos2d.h"

class Niveau1 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    cocos2d::EventListenerKeyboard* _2ndListner;


    cocos2d::Sprite* Sprite1;

    virtual bool init();
    
    CREATE_FUNC(Niveau1);
    
    void Bravo();
    void GoToTheNextLevel(cocos2d::Ref* pSender);
    void GoToPauseScene(Ref* pSender);
    void GoToGameOverScene(Ref* pSender);
    void MoveBall(cocos2d::EventKeyboard::KeyCode KeyCode2, cocos2d::Event* event);


};

#endif 
