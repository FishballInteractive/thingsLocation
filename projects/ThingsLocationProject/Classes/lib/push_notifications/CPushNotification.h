
#ifndef __CPushNotification__
#define __CPushNotification__

#include "IPushNotification.h"

class CPushNotification
    : public cocos2d::CCObject
    , public IPushNotification
{
public:
    CPushNotification();
    
    virtual ~CPushNotification();
    
    virtual void initWithData(CValue* aData);
    
    virtual CValue* toValue();
    
    virtual void initWithData(const SPushData& aData);
    
    virtual const std::string& getMessage();
    
    virtual const std::string& getSoundName();
    
    virtual const std::string& getIconName();
    
    virtual const std::string& getTitle();
    
    virtual long long getScheduleTime();
    
    virtual int getPushId();
    
    virtual float getRepeatInterval();
    
    virtual void setPushId(int aPushId);
    
    virtual CValue* getUserData();
    
private:
    std::string mMessage;
    
    std::string mTitle;
    
    std::string mSoundName;
    
    std::string mIconName;
    
    float mScheduleTime;
    
    float mRepeatInterval;
    
    int mPushId;
    
    CValue* mUserData;
};

#endif /* defined(__CPushNotification__) */
