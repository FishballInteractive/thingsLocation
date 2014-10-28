

#include "CNotificationCenter.h"

USING_NS_CC;

CNotificationCenter::CNotificationCenter()
{

}

CNotificationCenter::~CNotificationCenter()
{
    removeAllObserver();
}


void CNotificationCenter::notify(int aEvent, cocos2d::CCObject* aParam)
{
    std::map< int,std::set<INotificationObserver*>* >::iterator it = mObservers.find(aEvent);
    
    if(it != mObservers.end())
    {
        for( std::set<INotificationObserver*>::iterator setIt = it->second->begin(); setIt != it->second->end(); setIt++)
        {
            (*setIt)->handleNotification(this, aEvent, aParam);
        }
    }
}

void CNotificationCenter::addObserver(int aEvent, INotificationObserver* aObserver)
{
    std::map< int,std::set<INotificationObserver*>* >::iterator it = mObservers.find(aEvent);

    if(it != mObservers.end())
    {
        if(it->second->find(aObserver) != it->second->end())
        {
            return;
        }

        it->second->insert(aObserver);

        CCObject* castObject = dynamic_cast<CCObject*>(aObserver);

        if(castObject)
        {
            castObject->retain();
        }
    }
    else
    {
        std::set<INotificationObserver*>* items = new std::set<INotificationObserver*>;
        items->insert(aObserver);

        CCObject* castObject = dynamic_cast<CCObject*>(aObserver);

        if(castObject)
        {
            castObject->retain();
        }

        mObservers.insert(std::pair<int,std::set<INotificationObserver*>*>(aEvent,items));
    }
}

void CNotificationCenter::removeObserver(int aEvent, INotificationObserver* aObserver)
{
    std::map< int,std::set<INotificationObserver*>* >::iterator it = mObservers.find(aEvent);

    if(it != mObservers.end())
    {
        std::set<INotificationObserver*>* item = it->second;

        std::set<INotificationObserver*>::iterator findIt = item->find(aObserver);

        if(findIt != item->end())
        {
            item->erase(findIt);

            CCObject* castObject = dynamic_cast<CCObject*>(aObserver);

            if(castObject)
            {
                castObject->release();
            }
        }
    }

}

void CNotificationCenter::removeObserver(INotificationObserver* aObserver)
{
    std::map< int,std::set<INotificationObserver*>* >::iterator it;

    for(it = mObservers.begin(); it != mObservers.end(); it++)
    {
        for( std::set<INotificationObserver*>::iterator setIt = it->second->begin(); setIt != it->second->end(); setIt++)
        {
            if((*setIt) == aObserver)
            {
                CCObject* castObject = dynamic_cast<CCObject*>(aObserver);

                if(castObject)
                {
                    castObject->release();
                }

                it->second->erase(setIt);
                break;
            }
        }
    }
}

void CNotificationCenter::removeObserversByEvent(int aEvent)
{
    std::map< int,std::set<INotificationObserver*>* >::iterator it = mObservers.find(aEvent);

    if(it != mObservers.end())
    {
        for( std::set<INotificationObserver*>::iterator setIt = it->second->begin(); setIt != it->second->end(); setIt++)
        {
            CCObject* castObject = dynamic_cast<CCObject*>((*setIt));

            if(castObject)
            {
                castObject->release();
            }
        }

        it->second->clear();

        mObservers.erase(it);
    }
}

void CNotificationCenter::removeAllObserver()
{
    std::map< int,std::set<INotificationObserver*>* >::iterator it;

    for(it = mObservers.begin(); it != mObservers.end(); it++)
    {

        for( std::set<INotificationObserver*>::iterator setIt = it->second->begin(); setIt != it->second->end(); setIt++)
        {
            CCObject* castObject = dynamic_cast<CCObject*>((*setIt));

            if(castObject)
            {
                castObject->release();
            }
        }

        it->second->clear();

        delete it->second;
    }

    mObservers.clear();
}

