//
//  СNativeWindows_ios.m
//  Settlers
//
//  Created by Kirill_Mag on 26.12.13.
//
//

#include "CPushNotificationHelper_ios.h"
#include "Log.h"
#include "utils/ExtensionUtils_ios.h"

CPushNotificationHelper_ios::CPushNotificationHelper_ios()
{
    TRACE_ALLOC
    
#ifdef __IPHONE_8_0
    if ([[UIDevice currentDevice].systemVersion doubleValue] >= 8.0)
    {
        UIUserNotificationSettings* notificationSettings =
        [UIUserNotificationSettings settingsForTypes:
         UIUserNotificationTypeAlert |
         UIUserNotificationTypeBadge |
         UIUserNotificationTypeSound categories:nil];

        [[UIApplication sharedApplication]
         registerUserNotificationSettings:notificationSettings];
    }
#endif
}

CPushNotificationHelper_ios::~CPushNotificationHelper_ios()
{
    TRACE_DEALLOC
}

IPushNotificationHelper* IPushNotificationHelper::create()
{
    return new CPushNotificationHelper_ios();
}

void CPushNotificationHelper_ios::registrationPushNotification(IPushNotification* aNotification)
{
    NSString* message = [NSString stringWithUTF8String:aNotification->getMessage().c_str()];
    NSString* sound = UILocalNotificationDefaultSoundName;
    NSString* icon_name = nil;
    
    if(aNotification->getSoundName() != "")
    {
        sound = [NSString stringWithUTF8String:aNotification->getSoundName().c_str()];
    }
    
    if(aNotification->getIconName() != "")
    {
        icon_name = [NSString stringWithUTF8String:aNotification->getIconName().c_str()];
    }
    
    UILocalNotification *notification = [[UILocalNotification alloc] init];
    
    notification.fireDate = [NSDate dateWithTimeIntervalSinceNow:aNotification->getScheduleTime()];
    notification.alertBody = message;
    notification.repeatInterval = 0;
    notification.timeZone = [NSTimeZone defaultTimeZone];
    notification.soundName = sound;
    notification.alertLaunchImage = icon_name;
    notification.applicationIconBadgeNumber =  [[UIApplication sharedApplication] applicationIconBadgeNumber] + 1;
   
    
    NSString* str = [[NSNumber numberWithInt:aNotification->getPushId()] stringValue];
    
    id user_data = nil;
    if(aNotification->getUserData())
    {
        user_data = EUNSObjectFromCValue(aNotification->getUserData());
    }

    NSMutableDictionary *infoDict = nil;
    
    if(user_data)
    {
        infoDict = [NSMutableDictionary dictionaryWithObjectsAndKeys: str, @"id",user_data,@"user_data", nil];
    }
    else
    {
        infoDict = [NSMutableDictionary dictionaryWithObjectsAndKeys: str, @"id", nil];
    }
        
    notification.userInfo = infoDict;

    [[UIApplication sharedApplication] scheduleLocalNotification:notification];

    
    [notification release];
}

void CPushNotificationHelper_ios::unregistrationAllPushNotification()
{
    [[UIApplication sharedApplication] cancelAllLocalNotifications];
}

void CPushNotificationHelper_ios::unregistrationPushNotification(IPushNotification* aNotification)
{
    int push_id = aNotification->getPushId();
    
    unregistrationPushNotification(push_id);
}

std::vector<int> CPushNotificationHelper_ios::getActivePushNotification()
{
    std::vector<int> push_ids;
    
    UIApplication *app                = [UIApplication sharedApplication];
    NSArray *oldNotifications         = [app scheduledLocalNotifications];
    
    for (UILocalNotification *aNotif in oldNotifications)
    {
        push_ids.push_back([[aNotif.userInfo objectForKey:@"id"] integerValue]);
    }
    
    return push_ids;
}

void CPushNotificationHelper_ios::startServerPush()
{
    [UIApplication sharedApplication].applicationIconBadgeNumber = 0;
    [[UIApplication sharedApplication] registerForRemoteNotificationTypes:
     (UIRemoteNotificationTypeSound | UIRemoteNotificationTypeAlert)];
}

void CPushNotificationHelper_ios::resume()
{
    [UIApplication sharedApplication].applicationIconBadgeNumber = 0;
}

void CPushNotificationHelper_ios::unregistrationPushNotification(int aPushId)
{
    int push_id = aPushId;
    
    UIApplication *app                = [UIApplication sharedApplication];
    NSArray *oldNotifications         = [app scheduledLocalNotifications];
    
    NSString* push_id_str = [NSString stringWithFormat:@"%d", push_id];
    
    for (UILocalNotification *aNotif in oldNotifications)
    {
        if([[aNotif.userInfo objectForKey:@"id"] isEqualToString: push_id_str])
        {
            [app cancelLocalNotification:aNotif];
        }
    }
}