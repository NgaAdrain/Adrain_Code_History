package com.example.game_001.Services;

import android.app.Service;
import android.content.Intent;
import android.os.Binder;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.os.Messenger;
import android.provider.ContactsContract;
import android.renderscript.ScriptGroup;

import com.example.game_001.UI.MainActivity;

import java.io.BufferedInputStream;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

public class ClientService extends Service {
    private final int PORT = 50109;
    private final String IP = "192.168.0.13";
    private Socket socket;
    private DataOutputStream dataout;
    private DataInputStream datain;
    private String sendstr = "";//아마 내가 입력한 text
    private String showstr = null;
    private SocketThread clientThread;
    private GetThread joinThread;
    private SendThread sendThread;
    private IBinder binder = new LocalBinderC();

    public class LocalBinderC extends Binder {
        public ClientService getService() { return ClientService.this; }
    }

    @Override
    public IBinder onBind(Intent intent) {
        return binder;
    }

    public String toShowmsg(){
        return showst r;
    }
/*
    서버 오픈 -> accept대기
    클라이언트 접근 -> 서버에서 허가내용을 전송
    클라이언트
    DataInputStream, DataOutputStream => binary data input/output
    readUTF, writeUTF => string을 binary로 변환 => 한글사용가능!

 */
    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        String mode = intent.getExtras().getString("mod");
        String msg = intent.getExtras().getString("message");
        if((MainActivity.connection == true )&& (MainActivity.serverMode == true))
            //server가 열려있고, 이미 server에 연결된 상태라면 mode를 일부러 fail로 연결
            mode = "fail";
        switch (mode){
            case "join"://서버에 접속을 시도
                if(MainActivity.connection == true) break;//만약 서버가 열린상태라면 break
                clientThread = new SocketThread(IP,PORT);//접속하기 위한 socket thread class 객체 생성, 서버에 접속하는것
                clientThread.start();//실행
                MainActivity.connection = true;//connection은 ture
                MainActivity.serverMode = false;//server는 열린 상태가 아님

              break;
            case "send"://activity에 있는 text를 보내서 연결된 server에 보낸다
                if(MainActivity.connection == false) break;
                //연결된 상태가 아니라는 에러 텍스트 출력
                sendstr = msg;//text를 받는 부분
                MainActivity.my_Score = Integer.parseInt(sendstr);
                //send 버튼이 눌린다면 보낸다음 바로 끄는 방식 or send버튼이 눌리면 send하는 함수가 호출되는 방식
                sendThread = new SendThread();//join하는 순간 send를 위한 thread를 생성함
                sendThread.start();//Thread start
                break;
            case "quit"://client thread를 종료시킴
                sendstr = msg;
                sendThread = new SendThread();//join하는 순간 send를 위한 thread를 생성함
                sendThread.start();//Thread start
                if(clientThread != null){//
                    clientThread.close();
                    clientThread = null;
                    MainActivity.connection = false;
                }
                break;
//            case "data":
//                break;
            case "fail":
                break;
        }
        return START_STICKY;//super.onStartCommand(intent, flags, startId);
    }

    private class SocketThread extends Thread{
        private boolean isOpen= false;
        private boolean isConnected = false;
        private String ipAddr;
        private int portNum;
        //private DataInputStream input;

        public SocketThread(String ip, int port){
            ipAddr = ip;
            portNum = port;

        }//객체를 생성해서 ip와 port번호를 받아온다
        @Override
        public void run(){
            try {
                socket = new Socket(ipAddr, portNum);//소켓 접속시도
                this.isConnected = true;//연결상태
                joinThread = new GetThread();// datainput을 위한 thread class 객체
                joinThread.start();
                //input = new DataInputStream(socket.getInputStream());
                //DatainputStream을 위한 thread를 따로 만들것인가, 아니면 내부에 그냥 DIS만 만들것이냐
                //String check = input.readUTF();
                //192.168.7.45 connection established
                //set NIckName

            } catch (IOException e) {
                //e.printStackTrace();
                //Server Closed!
            }
        }
        public void close(){
            joinThread.stopThread();//thread를 종료
            joinThread = null;//thread객체를 null로 만듬
            try {
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            //아마 다른 자료를 보고 좀더 보충필요

        }
    }

    private class SendThread extends Thread{
        //send 즉 text를 전송하는 thread
        //private String sending = "";

        public SendThread(){
            try {
                dataout = new DataOutputStream(socket.getOutputStream());
                //dataout = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        @Override
        public void run(){
            try {
                dataout.writeUTF(sendstr);//전송
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private class GetThread extends Thread{
        //private DataInputStream getmsg;
        //get 즉 서버로부터 text를 얻는 class
        private boolean runningStatus = true;
        public GetThread(){
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
                     MainActivity.opposite_Score = Integer.parseInt(showstr);
                    //implements
                    //receive 구현
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
