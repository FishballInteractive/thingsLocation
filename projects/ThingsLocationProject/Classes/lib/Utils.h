
#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>
#include <vector>
#include <list>
#include "cocos2d.h"


USING_NS_CC;

#define VALUE_WITH_PROTOBUF(x,name,nameValue) \
name = x->nameValue(); \


namespace utils
{
    
template<typename T> T* createObject()
{
    T* object = new T();
    if(object)
    {
        object->autorelease();
    }
    
    return object;
}

template <typename T> void retainObject(T* aObject)
{
    CCObject* obj = dynamic_cast<CCObject*>(aObject);
    if(obj)
    {
        obj->retain();
    }
}

template <typename T> void releaseObject(T* aObject)
{
    CCObject* obj = dynamic_cast<CCObject*>(aObject);
    if(obj)
    {
        obj->release();
    }
}

template <typename T> void autoreleaseObject(T* aObject)
{
    CCObject* obj = dynamic_cast<CCObject*>(aObject);
    if(obj)
    {
        obj->autorelease();
    }
}

int hash(std::string const& key);

std::string stringWithFormat(const char * pszFormat, ...);

std::string valueToString(const int aValue);

std::string valueToString(const unsigned aValue);

std::string valueToString(const float aValue);

std::string valueToString(const double aValue);

std::string valueToString(const long long aValue);
    
CCRect cutRectByRect(const CCRect& aMainRect, const CCRect& aCutRect);
    
short byteToShort(unsigned const char* aByte);
    
unsigned int byteToInt8(unsigned const char* aByte);
    
int byteToInt(unsigned const char* aByte);
    
unsigned char* intToByte(int aValue);
    
unsigned char* shortToByte(short aValue);
    
bool splitWithForm(const char* pStr, std::vector<std::string>& strs);
    
ccColor3B ccColor3BFromString(const char* pszContent);
    
double clockTick();

double nowTime();

long long nowTimeInMs();

} // end namespace utils
    
#endif