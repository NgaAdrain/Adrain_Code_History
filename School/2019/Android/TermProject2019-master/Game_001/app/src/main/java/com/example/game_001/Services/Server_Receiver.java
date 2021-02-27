package com.example.game_001.Services;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

public class Server_Receiver extends BroadcastReceiver {
    Context context;

    @Override
    public void onReceive(Context context, Intent intent) {
        this.context = context;
        String mods =  intent.getExtras().getString("mod");
        String msg = intent.getExtras().getString("message");
        Intent button_intent = new Intent(context, ServerService.class);
        button_intent.putExtra("mod",mods);
        button_intent.putExtra("message",msg);
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O){
            this.context.startForegroundService(button_intent);
            //this.context.startForegroundService(msg_intent);
        }else{
            this.context.startService(button_intent);
            //this.context.startService(msg_intent);
        }
    }
}
