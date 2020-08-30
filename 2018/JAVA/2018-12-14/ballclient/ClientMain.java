package ballclient; //201524582 정희석
					//BallClientMain
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

import javax.swing.JFrame;

public class ClientMain {
	private static Socket s;
	private static PrintWriter p;
	private static ClientFrame frame;
	public static void main(String[] args) {
			frame = new ClientFrame();
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.setVisible(true);
	}
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
	public static void Connect() {
		try { 
			s = new Socket("localhost", 8587);
			String msg = "Try to connect " + s.getInetAddress() + " " + s.getPort();
			System.out.println(msg);
			InputStream inStream = s.getInputStream();
			Scanner in = new Scanner(inStream);
			String line = in.nextLine();
			System.out.println(msg);
			}catch ( IOException e ) { System.out.println("Server Closed Now"); e.printStackTrace(); }
	}
	
	public static void DisConnect() {
		try{
			try {
				p = new PrintWriter(s.getOutputStream(), true);
				String msg = "Disconnected";
				p.println(msg);
			}finally{s.close();}
		}
		catch(IOException e) { e.printStackTrace();}
	}
	
	public static void Send(String msg) {
		try {
			p = new PrintWriter(s.getOutputStream(), true);
			p.println(msg);//Add1, Add2를 보냄  //서버에서 받아서 공을 생성하는 식으로 실행 
		}catch ( IOException e ) { System.out.println("Server Closed Now"); e.printStackTrace(); }
	}

	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
}
