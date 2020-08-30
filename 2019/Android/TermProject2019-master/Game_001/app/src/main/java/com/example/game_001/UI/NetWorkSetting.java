package com.example.game_001.UI;

import android.Manifest;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

import com.example.game_001.Network.*;
import com.example.game_001.R;

public class NetWorkSetting extends AppCompatActivity {
    public Button Createbtn;
    public Button Participatebtn;
    protected void onCreate(Bundle savedInstanceState) {
        int permissionCheck = ContextCompat.checkSelfPermission(this, Manifest.permission.INTERNET);
//        PERMISSION
//
//
//
        super.onCreate(savedInstanceState);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
        setContentView(R.layout.activity_network);

        Createbtn = (Button) findViewById(R.id.CreateButton);
        Createbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(NetWorkSetting.this, Create.class);
                startActivity(intent);
            }
        });
        Participatebtn = (Button) findViewById(R.id.ParticipateButton);
        Participatebtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(NetWorkSetting.this, Participate.class);
                startActivity(intent);
            }
        });
    }
}
