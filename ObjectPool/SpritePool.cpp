//
//  SpritePool.cpp
//  hhl
//
//  Created by guodi on 15/12/9.
//
//

#include "SpritePool.h"
SpritePool* SpritePool::instance = NULL;

//默认构造
SpritePool::SpritePool()
{
    
}
SpritePool::~SpritePool()
{
    cleanAllName();
}

//单例
SpritePool* SpritePool::getInstance()
{
    if (instance == NULL) {
        instance = new SpritePool();
    }
    return instance;
}

void SpritePool::init(string Str, string d)
{
    v_nameList.clear();
    splitString(Str, v_nameList, d);
}

//分割字符串
void SpritePool::splitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
        
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

//new
Sprite* SpritePool::create()
{
    //默认不加入sprite池
    Sprite* sp = Sprite::create();
    return sp;
}

Sprite* SpritePool::create(const std::string& name)
{
    //判断是否加入对象池
    if (checkName(name))
    {
        Sprite* sp = pool.reuse("sprite_"+name);
        if (sp == NULL)
        {
            sp = Sprite::create(name);
            pool.putin(sp, "sprite_"+name);
        }
        return sp;
    }
    else
    {
        Sprite* sp = Sprite::create(name);
        return sp;
    }
}

Sprite* SpritePool::create(const std::string& name, const Rect& rect)
{
    //判断是否加入对象池
    if (checkName(name))
    {
        Sprite* sp = pool.reuse("sprite_"+name);
        if (sp == NULL)
        {
            sp = Sprite::create(name, rect);
            pool.putin(sp, "sprite_"+name);
        }
        return sp;
    }
    else
    {
        Sprite* sp = Sprite::create(name, rect);
        return sp;
    }
}

Sprite* SpritePool::createWithSpriteFrame(SpriteFrame *spriteFrame)
{
    string spriteFrameName = spriteFrame->_textureFilename;
    //判断是否加入对象池
    if (checkName(spriteFrameName))
    {
        Sprite* sp = pool.reuse("spriteFrame_"+spriteFrameName);
        if (sp == NULL)
        {
            sp = Sprite::createWithSpriteFrame(spriteFrame);
            //CCLOG("reference==>%d",sp->getReferenceCount());
            pool.putin(sp, "spriteFrame_"+spriteFrameName);
        }
        //CCLOG("reference==>%d",sp->getReferenceCount());
        return sp;
    }
    else
    {
        Sprite* sp = Sprite::createWithSpriteFrame(spriteFrame);
        return sp;
    }
}

Sprite* SpritePool::createWithSpriteFrameName(const std::string& spriteFrameName)
{
    //判断是否加入对象池
    if (checkName(spriteFrameName))
    {
        Sprite* sp = pool.reuse("spriteFrame_"+spriteFrameName);
        if (sp == NULL)
        {
            sp = Sprite::createWithSpriteFrameName(spriteFrameName);
            pool.putin(sp, "spriteFrame_"+spriteFrameName);
        }
        return sp;
    }
    else
    {
        Sprite* sp = Sprite::createWithSpriteFrameName(spriteFrameName);
        return sp;
    }
}

Sprite* SpritePool::createWithTexture(Texture2D *texture)
{
    return NULL;
}

Sprite* SpritePool::createWithTexture(Texture2D *texture, const Rect& rect, bool rotated)
{
    return NULL;
}

//file name
bool SpritePool::checkName(string name)
{
    vector<string>::iterator it = std::find(v_nameList.begin(), v_nameList.end(), name);
    if (it != v_nameList.end())
        return true;
    else
        return false;
}

void SpritePool::addName(string name)
{
    if (name == "") return;
    v_mutex.lock();
    v_nameList.insert(v_nameList.begin(), name);
    v_mutex.unlock();
}

void SpritePool::removeName(string name)
{
    if (name == "") return;
    v_mutex.lock();
    vector<string>::iterator it = std::find(v_nameList.begin(), v_nameList.end(), name);
    if(it != v_nameList.end())
        v_nameList.erase(it);
    else
        CCLOG("Err:SpritePool::removeFile:查无此项!");
    v_mutex.unlock();
}

void SpritePool::cleanAllName()
{
    v_mutex.lock();
    v_nameList.clear();
    v_mutex.unlock();
}

void SpritePool::cleanFreeObjects()
{
    CCLOG("===>cleanFreeObjects");
    pool.cleanFreeObjects();
}

void SpritePool::cleanAllObjects()
{
    CCLOG("===>cleanAllObjects");
    pool.cleanAllObjects();
}