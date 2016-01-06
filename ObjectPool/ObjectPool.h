//
//  ObjectPool.h
//  hhl
//
//  Created by guodi on 15/12/9.
//
//

#ifndef __hhl__ObjectPool__
#define __hhl__ObjectPool__

#include <iostream>
#include <vector>
#include "cocos2d.h"
#include <algorithm>
#include <mutex>

using namespace std;
USING_NS_CC;

//模版
template <typename T>
class ObjectPool : public Ref
{
public:
    ObjectPool()
    {
        Director::getInstance()->getScheduler()->schedule(SEL_SCHEDULE(&ObjectPool::autoFreeObjects), (Ref*)this, 1, false);
    }
    ~ObjectPool()
    {
        cleanAllObjects();
    }
    
    //申请
    T* reuse(string classID)
    {
        array_map::const_iterator it_used = dict_used.find(classID);
        array_map::const_iterator it_free = dict_free.find(classID);
        if(it_used != dict_used.end() && it_free != dict_free.end())
        {
            __Array* arr = it_free->second;
            if(arr->count() != 0)
            {
                T* t = (T*)arr->getObjectAtIndex(0);
                //CCLOG("reference==>%d",(Ref*)t->getReferenceCount());
                mutex_used.lock();
                it_used->second->addObject(t);
                mutex_used.unlock();
                //CCLOG("reference==>%d",(Ref*)t->getReferenceCount());
                mutex_free.lock();
                arr->removeObjectAtIndex(0);
                mutex_free.unlock();
                //CCLOG("reference==>%d",(Ref*)t->getReferenceCount());
                return t;
            }
        }
        return NULL;
    }

    //回收
    void unuse(T *t, string classID)
    {
        array_map::const_iterator it_used = dict_used.find(classID);
        array_map::const_iterator it_free = dict_free.find(classID);
        if(it_used != dict_used.end() && it_free != dict_free.end())
        {
            //CCLOG("reference==>%d",(Ref*)t->getReferenceCount());
            mutex_free.lock();
            it_free->second->addObject(t);
            mutex_free.unlock();
            //CCLOG("reference==>%d",(Ref*)t->getReferenceCount());
            mutex_used.lock();
            it_used->second->fastRemoveObject(t);
            mutex_used.unlock();
            //CCLOG("reference==>%d",(Ref*)t->getReferenceCount());
        }
    }
    
    //添加到使用队列
    void putin(T* t, string classID)
    {
        array_map::const_iterator it_used = dict_used.find(classID);
        if(it_used != dict_used.end())
        {
            it_used->second->addObject(t);
        }
        else
        {
            //CCLOG("reference==>%d",(Ref*)t->getReferenceCount());
            //dict_used add new
             __Array* array_used = __Array::create();
            mutex_used.lock();
            array_used->retain();
            array_used->addObject(t);
            mutex_used.unlock();
            dict_used.insert(array_map::value_type(classID, array_used));
            //CCLOG("reference==>%d",(Ref*)t->getReferenceCount());
            //dict_free add new
            __Array* array_free = __Array::create();
            array_free->retain();
            dict_free.insert(array_map::value_type(classID, array_free));
            //CCLOG("reference==>%d",(Ref*)t->getReferenceCount());
        }
    }
    
    //自动清理内存
    void autoFreeObjects(float dt)
    {
        for(array_map::const_iterator it = dict_free.begin(); it != dict_free.end(); it++)
        {
            CCLOG("free_dict: classID = %s, count = %zd",it->first.c_str(), it->second->count());
        }
        for(array_map::const_iterator it = dict_used.begin(); it != dict_used.end(); it++)
        {
            CCLOG("used_dict: classID = %s, count = %zd",it->first.c_str(), it->second->count());
            Ref* ref;
            CCARRAY_FOREACH(it->second, ref)
            {
                if(ref->getReferenceCount() == 1)
                {
                    T* t = (T*)ref;
                    unuse(t, it->first);
                }
            }
        }
    }
    
    //清理空闲池
    void cleanFreeObjects()
    {
        for(array_map::const_iterator it = dict_free.begin(); it != dict_free.end(); it++)
        {
            it->second->removeAllObjects();
            it->second->release();
        }
        //dict clean
        dict_free.clear();
    }
    
    //清理对象池所有对象
    void cleanAllObjects()
    {
        //clean array
        for(array_map::const_iterator it = dict_free.begin(); it != dict_free.end(); it++)
        {
            it->second->removeAllObjects();
            it->second->release();
        }
        for(array_map::const_iterator it = dict_used.begin(); it != dict_used.end(); it++)
        {
            it->second->removeAllObjects();
            it->second->release();
        }
        //clean dict
        dict_free.clear();
        dict_used.clear();
    }
    
protected:
    //dict<classID, array> 结构
    typedef std::unordered_map<string, __Array*> array_map;
    array_map dict_free, dict_used;
    //mutex
    mutex mutex_free, mutex_used;
};

#endif /* defined(__hhl__ObjectPool__) */
