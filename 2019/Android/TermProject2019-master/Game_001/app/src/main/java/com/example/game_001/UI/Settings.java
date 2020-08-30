package com.example.game_001.UI;

import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.CompoundButton;
import android.widget.Switch;
import android.widget.Toast;

import com.example.game_001.R;
import com.example.game_001.Services.BGM_Receiver;
import com.example.game_001.Services.BackgroundMusic;
import com.example.game_001.UI.MainActivity;
public class Settings extends AppCompatActivity {
    //private boolean check = false;//
    private Switch bgmSwitch, effSwitch;
    Context currentContext;
    PendingIntent pendingIntent;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
        setContentView(R.layout.activity_settings);
        bgmSwitch = (Switch) findViewById(R.id.bgmOnOff);
        effSwitch = (Switch) findViewById(R.id.effectOnOff);
        final Intent i = new Intent(this, BGM_Receiver.class);
        if(MainActivity.bgmStatus)
            bgmSwitch.setChecked(true);
        else
            bgmSwitch.setChecked(false);
        bgmSwitch.setOnCheckedChangeListener(
                new CompoundButton.OnCheckedChangeListener() {
                        @Override
                        public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                            Toast inform;
                            if(bgmSwitch.isChecked()){
                                i.putExtra("IsPlaying","run");
                                sendBroadcast(i);
                                //startService(i);//new Intent(Settings.this, BackgroundMusic.class));
                                inform = Toast.makeText(Settings.this, "Music On" , Toast.LENGTH_SHORT);
                                MainActivity.bgmStatus = true;//
                            }
                            else  {
                                i.putExtra("IsPlaying","stop");
                                sendBroadcast(i);
                                //startService(i);//new Intent(Settings.this, BackgroundMusic.class));
                                inform = Toast.makeText(Settings.this, "Music Off", Toast.LENGTH_SHORT);
                                MainActivity.bgmStatus = false;//
                            }
                            inform.show();
                        }
                }
        );
        //effSwitch
    }
//    public void onBackPressed(){
//
//    }
}
