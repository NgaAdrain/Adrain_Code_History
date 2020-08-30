package com.example.game_001.Services;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
//수업예제참고
public class BGM_Receiver extends BroadcastReceiver {
    Context context;
    @Override
    public void onReceive(Context context, Intent intent) {
        this.context = context;
        String get_status = intent.getExtras().getString("IsPlaying");
        Intent service_intent = new Intent(context, BackgroundMusic.class);
        service_intent.putExtra("IsPlaying",get_status);
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O){
            this.context.startForegroundService(service_intent);
        }else{
            this.context.startService(service_intent);
        }
    }
}
