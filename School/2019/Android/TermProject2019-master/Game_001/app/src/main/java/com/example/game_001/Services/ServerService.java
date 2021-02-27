package com.example.game_001.Services;

import android.app.Service;
import android.content.Intent;
import android.os.Binder;
import android.os.IBinder;

import com.example.game_001.UI.MainActivity;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerService extends Service {
    private final int PORT = 50765;
    private Socket socket;
    private ServerSocket serverSocket;
    private ServerThread serverThread;
    private SendThread sendThread;
    private ReceiveThread receiveThread;
    private DataInputStream datain;
    private DataOutputStream dataout;
    private String showstr = "default";// 내가 받은 text
    private String sendstr = null;// 내가 activity에서 입력한 text
    private IBinder binder = new LocalBinder();

    public class LocalBinder extends Binder {
        public ServerService getService(){
            return ServerService.this;
        }
    }

    @Override
    public IBinder onBind(Intent intent) {
       return binder;
    }

    public String toShowmsg(){
        return showstr;
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        String mode = intent.getExtras().getString("mod");
        String msg = intent.getExtras().getString("message");
        if((MainActivity.connection == true )&& (MainActivity.serverMode == false))
            mode = "fail";
        switch (mode){
            case "open":
                if((MainActivity.connection == true )&& (MainActivity.serverMode == true))
                    mode = "fail";
                MainActivity.connection = true;
                MainActivity.serverMode = true;
                serverThread = new ServerThread(PORT);
                showstr = "opened";
                serverThread.start();
                MainActivity.connection = true;
                MainActivity.serverMode = true;

                break;
            case "send":
                if(MainActivity.connection == false) break;
                sendstr = msg;
                sendThread = new SendThread();
                sendThread.start();
                break;
            case "quit":
                if(serverThread != null){
                    serverThread.close();
                    serverThread = null;
                    MainActivity.connection = false;
                    MainActivity.serverMode = false;
                }
                break;
//            case "data":
//                break;
            case "fail":
                break;
        }
        return START_STICKY;//super.onStartCommand(intent, flags, startId);
    }

    private class ServerThread extends Thread{
        private int port;
        private boolean isConnected = false;
        private boolean isOpen = false;

        ServerThread(int portnums){
            port = portnums;
        }

        @Override
        public void run(){
            try {
                serverSocket = new ServerSocket(port);
                socket = serverSocket.accept();
                showstr = "connected";
                this.isConnected = true;
                receiveThread = new ReceiveThread();
                receiveThread.start();

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        public void close(){
            receiveThread.stopThread();//thread를 종료
            receiveThread = null;//thread객체를 null로 만듬
            try {
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            //아마 다른 자료를 보고 좀더 보충필요

        }
    }

    private class SendThread extends Thread{
        public SendThread(){
            try {
                dataout = new DataOutputStream(socket.getOutputStream());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        @Override
        public void run(){
            try {
                dataout.writeUTF(sendstr);//전송
                showstr = "sended";
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }

    private class ReceiveThread extends Thread{
        private boolean runningStatus = true;
        public ReceiveThread(){
            try {
                datain = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
                //datainputstream
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        @Override
        public void run(){
            try {
                while (runningStatus) {
                    showstr = datain.readUTF().toString();

                }
            }catch(Exception e){
                e.printStackTrace();
            }
        }
        public void stopThread(){
            try {
                datain.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            runningStatus = false;
        }
    }


}
