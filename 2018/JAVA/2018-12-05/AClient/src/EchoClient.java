import java.io.*;										//201524582  정희석
import java.net.*;    //에코클라이언트
import java.util.*; 
import javax.swing.JFrame;

public class EchoClient {
	private static Socket s;
	private static PrintWriter p;
	private static TextAreaFrame frame;
	public static void main(String[] args) {
		frame = new TextAreaFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
	public static void Connect() {
		try { 
			s = new Socket("localhost", 8086);
			String msg = "Try to connect " + s.getInetAddress() + " " + s.getPort();
			frame.Receive(msg);
			InputStream inStream = s.getInputStream();
			Scanner in = new Scanner(inStream);
			String line = in.nextLine();
			frame.Receive(line);
			}catch ( IOException e ) { frame.Receive("Server Closed Now"); e.printStackTrace(); }
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
			p.println(msg);
			InputStream inStream = s.getInputStream();
			Scanner in = new Scanner(inStream);
			String line = in.nextLine();
			line = "Receive: " + line;
			frame.Receive(line);
		}catch ( IOException e ) { frame.Receive("Server Closed Now"); e.printStackTrace(); }
	}
}

