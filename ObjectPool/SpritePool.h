//
//  SpritePool.h
//  hhl
//
//  Created by guodi on 15/12/9.
//
//

#ifndef __hhl__SpritePool__
#define __hhl__SpritePool__

#include <stdio.h>
#include "ObjectPool.h"
#include <iostream>
#include "cocos2d.h"
#include <mutex>

using namespace std;
USING_NS_CC;

class SpritePool
{
public:
    SpritePool();
    ~SpritePool();
    
    //单例
    static SpritePool* getInstance();
    void init(string Str, string d);
    //file name
    bool checkName(string name);
    void addName(string name);
    void removeName(string name);
    void cleanAllName();
    
    //new
    Sprite* create();
    Sprite* create(const std::string& name);
    Sprite* create(const std::string& filename, const Rect& rect);
    Sprite* createWithSpriteFrame(SpriteFrame *spriteFrame);
    Sprite* createWithSpriteFrameName(const std::string& spriteFrameName);
    Sprite* createWithTexture(Texture2D *texture);
    Sprite* createWithTexture(Texture2D *texture, const Rect& rect, bool rotated=false);
    
    //clean
    void cleanFreeObjects();
    void cleanAllObjects();
    
private:
    void splitString(const std::string& s, std::vector<std::string>& v, const std::string& c);
    
private:
    //文件名列表
    vector<string> v_nameList;
    //单例
    static SpritePool* instance;
    //锁
    mutex v_mutex;
    //对象池
    ObjectPool<cocos2d::Sprite> pool;
};

#endif /* defined(__hhl__SpritePool__) */
