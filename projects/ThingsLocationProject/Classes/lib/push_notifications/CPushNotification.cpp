
#include "CPushNotification.h"
#include "Utils.h"
#include "Log.h"

USING_NS_CC;

CPushNotification::CPushNotification()
: mPushId(0)
, mMessage("")
, mIconName("")
, mSoundName("")
, mTitle("")
, mUserData(0)
, mScheduleTime(0)
, mRepeatInterval(0)
{
    TRACE_ALLOC
}

CPushNotification::~CPushNotification()
{
    TRACE_DEALLOC
    
    CC_SAFE_RELEASE(mUserData);
}

void CPushNotification::initWithData(CValue* aData)
{
    CValueDictionary* dict = aData->toDictionary();
    
    CValue* message = CAST_TO_Value(dict->objectForKey("message"));
    mMessage = message->toString();
    
    CValue* sound_name = CAST_TO_Value(dict->objectForKey("sound_name"));
    mSoundName = sound_name->toString();
    
    CValue* icon_name = CAST_TO_Value(dict->objectForKey("icon_name"));
    mIconName = icon_name->toString();
    
    CValue* title = CAST_TO_Value(dict->objectForKey("title"));
    mTitle = title->toString();
    
    CValue* schedule_time = CAST_TO_Value(dict->objectForKey("schedule_time"));
    mScheduleTime = schedule_time->toLongLong();

    CValue* repeate_interval = CAST_TO_Value(dict->objectForKey("repeate_interval"));
    mRepeatInterval = repeate_interval->toFloat();
    
    CValue* push_id = CAST_TO_Value(dict->objectForKey("push_id"));
    mPushId = push_id->toInt();
    
    CValue* user_data = CAST_TO_Value(dict->objectForKey("user_data"));
    mUserData = user_data;
    utils::retainObject(mUserData);
}

CValue* CPushNotification::toValue()
{
    CValueDictionary* dict = CValueDictionary::dictionary();
    
    CValue* message = CValue::ValueFromString(mMessage);
    dict->setObject(message, "message");
    
    CValue* sound_name = CValue::ValueFromString(mSoundName);
    dict->setObject(sound_name, "sound_name");
    
    CValue* icon_name = CValue::ValueFromString(mIconName);
    dict->setObject(icon_name, "icon_name");
    
    CValue* title = CValue::ValueFromString(mTitle);
    dict->setObject(title, "title");
    
    CValue* schedule_time = CValue::ValueFromLongLong(mScheduleTime);
    dict->setObject(schedule_time, "schedule_time");
    
    CValue* repeate_interval = CValue::ValueFromFloat(mRepeatInterval);
    dict->setObject(repeate_interval, "repeate_interval");
    
    CValue* push_id = CValue::ValueFromInt(mPushId);
    dict->setObject(push_id, "push_id");
    
    if(mUserData)
    {
        CValue* user_data = mUserData;
        dict->setObject(user_data, "user_data");
    }

    
    return CValue::ValueFromDictionary(dict);
}

void CPushNotification::initWithData(const SPushData& aData)
{
    mMessage = aData.getMessage();
    mSoundName = aData.getSoundName();
    mIconName = aData.getIconName();
    mTitle = aData.getTitle();
    mScheduleTime = aData.getScheduleTime();
    mRepeatInterval = aData.getRepeatInterval();
    mPushId = aData.getPushId();
    mUserData = aData.getUserData();
    utils::retainObject(mUserData);
}

const std::string& CPushNotification::getMessage()
{
    return mMessage;
}

const std::string& CPushNotification::getSoundName()
{
    return mSoundName;
}

const std::string& CPushNotification::getIconName()
{
    return mIconName;
}

const std::string& CPushNotification::getTitle()
{
    return mTitle;
}

long long CPushNotification::getScheduleTime()
{
    return mScheduleTime;
}

int CPushNotification::getPushId()
{
    return mPushId;
}

float CPushNotification::getRepeatInterval()
{
    return mRepeatInterval;
}

void CPushNotification::setPushId(int aPushId)
{
    mPushId = aPushId;
}

CValue* CPushNotification::getUserData()
{
    return mUserData;
}