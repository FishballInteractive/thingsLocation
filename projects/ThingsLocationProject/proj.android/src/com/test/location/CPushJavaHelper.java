package com.test.location;

import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.support.v4.app.NotificationCompat;


public class CPushJavaHelper
{
	static void nativeRegisterPush(String aMessage, int aTime, int aPushId)
	{
		NotificationManager notificationManager = (NotificationManager)
				ThingsLocationProject.inst.getSystemService(Context.NOTIFICATION_SERVICE);

        PendingIntent contentIntent = PendingIntent.getActivity(ThingsLocationProject.inst, 0,
                new Intent(ThingsLocationProject.inst, ThingsLocationProject.class), 0);

        NotificationCompat.Builder mBuilder =
                new NotificationCompat.Builder(ThingsLocationProject.inst)
        .setSmallIcon(R.drawable.icon)
        .setContentTitle("Things Location")
        .setStyle(new NotificationCompat.BigTextStyle()
        .bigText(aMessage))
        .setContentText(aMessage);
       
        mBuilder.setContentIntent(contentIntent);
        notificationManager.notify(aPushId, mBuilder.build());
	}
}
