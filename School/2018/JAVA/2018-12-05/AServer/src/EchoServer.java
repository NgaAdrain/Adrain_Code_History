import java.io.*;								//201524582 정희석
import java.net.*;								//Echo Server main
import java.util.*;

public class EchoServer {
	public static void main(String[] args ) {
		try {
		ServerSocket s = new ServerSocket(8086); // port num : 8086
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
				out.println("Hi! " + line); 
				if ( line.trim().equals("Disconnected") ) {done = true; System.out.println(line);} //client와 연계해야함!
				else{
					System.out.println("Read: " + line);
					System.out.println("Write: Hi! " + line);
				}
			}
		}
		finally { incoming.close(); }
		}catch (IOException e) { e.printStackTrace(); }
	}
}
