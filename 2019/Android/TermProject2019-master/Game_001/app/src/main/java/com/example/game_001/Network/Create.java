package com.example.game_001.Network;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.pm.ActivityInfo;
import android.content.res.ColorStateList;
import android.graphics.Color;
import android.os.Bundle;
import android.os.IBinder;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.example.game_001.R;
import com.example.game_001.Services.ServerService;
import com.example.game_001.Services.Server_Receiver;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Create extends AppCompatActivity {
    private TextView sendchat;
    private EditText editchat;
    private Button sendBtn, createBtn, quitBtn, getmsg;
    private Intent sig;
    private String sendtxt;
    boolean serverOnOff = true;
    boolean services = true;
    private ServerService server;

    private ServiceConnection connection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            ServerService.LocalBinder binder = (ServerService.LocalBinder) service;
            server = binder.getService();
            services = true;
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {
            services = false;

        }
    };
    @Override
    protected void onStart(){
        super.onStart();
        Intent intents = new Intent(this,ServerService.class);
        bindService(intents,connection, Context.BIND_AUTO_CREATE);
    }

    class BtnOnClickListener implements Button.OnClickListener {
        @Override
        public void onClick(View view){
            final TextView sendchat = (TextView) findViewById(R.id.show_c);
            switch (view.getId()){
                case R.id.CreateRoomButton:
                    sig.putExtra("mod","open");
                    sendBroadcast(sig);
                    break;
                case R.id.send_c:
                    sig.putExtra("mod","send");
                    sendtxt = editchat.getText().toString();
                    sig.putExtra("message",sendtxt);
                    sendBroadcast(sig);
                    break;
                case R.id.QuitRoomButton_C:
                    sig.putExtra("mod","quit");
                    sendBroadcast(sig);
                    break;
                case R.id.get_c:
                    if(services){
                        String getmsg = server.toShowmsg();
                        sendchat.setText(getmsg);
                    }

                    break;
            }

        }
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
        setContentView(R.layout.activity_create_room);
        BtnOnClickListener onClickListener = new BtnOnClickListener();

        sig = new Intent(this, Server_Receiver.class);

        getmsg = (Button)findViewById(R.id.get_c);
        getmsg.setOnClickListener(onClickListener);

        sendBtn = (Button)findViewById(R.id.send_c);
        sendBtn.setOnClickListener(onClickListener);

        createBtn = (Button)findViewById(R.id.CreateRoomButton);
        createBtn.setOnClickListener(onClickListener);

        quitBtn = (Button)findViewById(R.id.QuitRoomButton_C);
        quitBtn.setOnClickListener(onClickListener);

        sendchat = (TextView)findViewById(R.id.show_c);
        editchat = (EditText)findViewById(R.id.edit_c);
    }

}
