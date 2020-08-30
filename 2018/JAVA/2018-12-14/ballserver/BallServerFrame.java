package ballserver;

import java.awt.BorderLayout;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class BallServerFrame extends JFrame {
	public BallServerFrame() {
		//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
		//여기 수정//
			setSize(DEFAULT_WIDTH,DEFAULT_HEIGHT);
			setTitle("BallBounceThread");
			panel = new BallPanel();
			add(panel,BorderLayout.CENTER);
			JPanel textPanel = new JPanel();
			textarea = new JTextArea(1,5);
			textarea.setEditable(false);
			textarea.setText("0");
			textPanel.add(textarea);
			textPanel.add(new JLabel("개"));
			add(textPanel, BorderLayout.SOUTH);
		}
		
	public static void OpenServer() {
		try {
		ServerSocket s = new ServerSocket(8587); // port num : 8587
		Socket incoming = s.accept( ); 
		InetAddress clientAddress = incoming.getInetAddress() ;
		System.out.printf("Connected from %s[%s] \n ",
		clientAddress.getHostName(), clientAddress.getHostAddress()) ;
		try {
			InputStream inStream = incoming.getInputStream();
			OutputStream outStream = incoming.getOutputStream();
			Scanner in = new Scanner(inStream);
			PrintWriter out = new PrintWriter(outStream, true /* autoFlush */);
			out.println( "Connection Established." );
			boolean done = false;
			while ( !done && in.hasNextLine() ) {
				String line = in.nextLine(); 
				if ( line.trim().equals("Disconnected") ) {done = true; incoming.close();} //client와 연계해야함!
				switch(line) {
				case "Show":
					BallServerMain.SetVisibility(true);
					break;
				case "Reset":
					BallServerMain.SetVisibility(false);
					ballCount = 0;
					BallPanel.resetBall();
					textarea.setText("");
					textarea.append(Integer.toString(ballCount));
					break;
				case "Add1":
					addOneBall();
					break;
				case "Add2":
					addTwoBall();
					break;
				case "Exit":
					incoming.close();
					System.exit(0);
					break;
				default:
					break;
				}
			}
		}
		finally { incoming.close();}
		}catch (IOException e) { OpenServer();}
	}
	
	public static void addOneBall() {
		Ball b = new Ball(ballCount++);
		panel.add(b);
		Runnable r = new BallRunnable(b, panel);
		Thread t = new Thread(r);
		t.start();
		//여기만 손보면 끝//
		//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
		textarea.setText("");
		textarea.append(Integer.toString(ballCount));
		//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
	}
	
	public static void addTwoBall() {
		Ball b = new Ball(ballCount++);
		panel.add(b);
		Runnable r = new BallRunnable(b, panel);
		Thread t = new Thread(r);
		t.start();
		Ball b1 = new Ball(ballCount++,50,50);
		panel.add(b1);
		Runnable r1 = new BallRunnable(b1, panel);
		Thread t1 = new Thread(r1);
		t1.start();
		//여기만 손보면 끝//
		//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
		textarea.setText("");
		textarea.append(Integer.toString(ballCount));
		//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
	}
	
	public void SetCount(int count) {
		ballCount = count;
	}
	
	private static JTextArea textarea;	
	private static BallPanel panel;
	private static int ballCount = 0;
	private static final int DEFAULT_WIDTH = 1000;
	private static final int DEFAULT_HEIGHT = 500;
}
