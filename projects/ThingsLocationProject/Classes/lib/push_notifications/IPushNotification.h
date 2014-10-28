
#ifndef __IPushNotification__
#define __IPushNotification__

#include "cocos2d.h"
#include "CValue.h"

struct SPushData
{
    SPushData()
    {
        mMessage = "";
        mTitle = "";
        mSoundName = "";
        mIconName = "";
        mScheduleTime = 0.0f;
        mRepeatInterval = 0.0f;
        mPushId = -1;
        mUserData = NULL;
    }
    
    ~SPushData()
    {
        CC_SAFE_RELEASE(mUserData);
    }
    
    CC_SYNTHESIZE(std::string, mMessage, Message);
    CC_SYNTHESIZE(std::string, mTitle, Title);
    CC_SYNTHESIZE(std::string, mSoundName, SoundName);
    CC_SYNTHESIZE(std::string, mIconName, IconName);
    CC_SYNTHESIZE(long long, mScheduleTime, ScheduleTime);
    CC_SYNTHESIZE(float, mRepeatInterval, RepeatInterval);
    CC_SYNTHESIZE(int, mPushId, PushId);
    CC_SYNTHESIZE_RETAIN(CValue*, mUserData, UserData);
};

class IPushNotification
{
public:
    virtual ~IPushNotification() {};
    
    virtual void initWithData(CValue* aData) = 0;
    
    virtual CValue* toValue() = 0;
    
    virtual void initWithData(const SPushData& aData) = 0;
    
    virtual const std::string& getMessage() = 0;
    
    virtual const std::string& getSoundName() = 0;
    
    virtual const std::string& getIconName() = 0;
    
    virtual const std::string& getTitle() = 0;
    
    virtual long long getScheduleTime() = 0;
     
    virtual int getPushId() = 0;
    
    virtual float getRepeatInterval() = 0;
    
    virtual void setPushId(int aPushId) = 0;
    
    virtual CValue* getUserData() = 0;
};

#endif /* defined(__IPushNotification__) */
