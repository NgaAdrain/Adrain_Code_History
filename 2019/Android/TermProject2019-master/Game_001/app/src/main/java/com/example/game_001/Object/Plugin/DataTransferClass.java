package com.example.game_001.Object.Plugin;

import com.example.game_001.UI.MainActivity;

public class DataTransferClass { //데이터 전달 plugin
    public static String ReceiveNSend(int input_Score){
        //서버 또는 클라이언트로부터 score전송 받는 object자리 //MainActivity.opposite_Score = (SERVER Service OF CLIENT Service) .receive();
        //if(MainActivity.serverMode && MainActivity.connection) MainActivity.opposite_Score = (CLIENT Service) .receive();
        //else if(!MainActivity.serverMode && MainActivity.connection) MainActivity.opposite_Score = (Server Service) .receive();
        String result;
        //MainActivity.my_Score = input_Score;
        result = "";
        result += MainActivity.opposite_Score;//1인용
        //서버 또는 클라이언트로 score전송 하는 object자리 //(SERVER Service OF CLIENT Service) .send(input_Score);
        return result;
    }
    public static String Decide(int input_Score){//상대의 플레이 상태 추가
        if(input_Score > MainActivity.opposite_Score)
            return "You Win! Your Score : " + input_Score + "Opposite Score : " + MainActivity.opposite_Score;
        else
            return "You Lose! Your Score : " + input_Score + "Opposite Score : " + MainActivity.opposite_Score;
    }
    public static void quit(){
        MainActivity.opposite_Score = 0;
        MainActivity.connection = false;
    }
    public static void reset(){
        MainActivity.opposite_Score = 0;
    }
}
