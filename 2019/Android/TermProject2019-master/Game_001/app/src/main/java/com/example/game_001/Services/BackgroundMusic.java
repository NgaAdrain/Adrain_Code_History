package com.example.game_001.Services;

import android.app.Service;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.IBinder;

import com.example.game_001.R;


public class BackgroundMusic extends Service {
    //@androidx.annotation.Nullable
    private MediaPlayer bgm;
    int startID;
    boolean isRunning = false;
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        String isPlaying = intent.getExtras().getString("IsPlaying");

        assert isPlaying != null;
        switch (isPlaying) {
            case "run":
                startId = 1;
                break;
            case "stop":
                startId = 0;
                break;
            default:
                startId = 0;
                break;
        }
        if(!this.isRunning){
            bgm = MediaPlayer.create(this, R.raw.car);
            bgm.setLooping(true);
            bgm.start();
            this.isRunning = true;
            this.startID = 0;
        }
        else if(this.isRunning && startId == 0) {

            bgm.stop();
            bgm.reset();
            bgm.release();
            this.isRunning = false;
            this.startID = 0;
        }
        else if(!this.isRunning && startId == 0) {

            this.isRunning = false;
            this.startID = 0;

        }
        else if(this.isRunning && startId == 1){

            this.isRunning = true;
            this.startID = 1;
        }
        else {
        }
        return START_STICKY;//super.onStartCommand(intent, flags, startId);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        //bgm.stop();
        //bgm.release();
    }
//
//    public void onStart(){
//        if(!bgm.isPlaying()){
//            bgm.start();
//            bgm.setLooping(true);
//        }
//    }
//
//    public void onStop(){
//        if(bgm.isLooping()||bgm.isPlaying()){
//            bgm.stop();
//        }
//    }
//
//    public void onPause(){
//        if(bgm.isLooping()||bgm.isPlaying())
//            bgm.pause();
//    }
//
//    public void onResume(){
//        if(!bgm.isLooping()||!bgm.isPlaying()){
//            bgm.start();
//            bgm.setLooping(true);
//        }
//    }
}
