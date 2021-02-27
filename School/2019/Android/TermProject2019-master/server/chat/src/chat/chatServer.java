package chat;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class chatServer {
	private static Socket socket = null;
	private static ServerSocket server = null;
	private static DataInputStream streamInput = null;
	private static DataOutputStream streamOutput = null;
	private static String yourscore = "100";
	private static boolean  connectState = false; 
	private ServerThread serverThread;
	
	public chatServer(int port) {
		try {
			System.out.println("Bomdomg to port " + port + ",please wait....");
			server = new ServerSocket(port);//소캣생성
			System.out.println("Server started: " + server);
			System.out.println("Waiting for a client ....");
			socket = server.accept();//기다린다, 요청이 오면 시작주소를 넘겨줌
			System.out.println("Client accepted: " + socket);
			streamOutput = new DataOutputStream(socket.getOutputStream());
			streamOutput.writeUTF(yourscore);
			open();
			System.out.println("opened");
			boolean done = false;
			while(!done) {
				String line = streamInput.readUTF().toString();
				yourscore = line;
				System.out.println(line);
				done = line.equals(".bye");
			}
			socket.close();
		} catch (IOException e) {
			System.out.println("server disconnected");
			try {
				server.close();
				connectState = false;
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}finally {
			try {
				socket.close();
				streamInput.close();
				streamOutput.close();
				connectState = false;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	public void open() throws IOException {
		streamInput = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
		System.out.println("wait for message.....");
		//streamInput.read();
	}
	public void close() {
		if(socket != null)
			try {
				socket.close();
			}catch(IOException e) {
				e.printStackTrace();
			}
		if(streamInput != null)
			try {
				streamInput.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	
	public static void main(String[] args) {
		chatServer server = null;
		while(true) {
			if(args.length != 1)
				System.out.println("Usage: java ChatServer port");
			else
				System.out.println("make server");
				System.out.println("port: " + Integer.parseInt(args[0]));
				server = new chatServer(Integer.parseInt(args[0]));
		}
	}
	
	
	
	
	
	
	
	
	
	
	public class ServerThread extends Thread{
		private int PORT = 50765;
		
		ServerThread(int portnums){
			PORT = portnums;
		}
		
		@Override
		public void run() {
			try {
				System.out.println("Bomdomg to port " + PORT + ",please wait....");
				server = new ServerSocket(PORT);
				System.out.println("Server started: " + server);
				System.out.println("Waiting for a client ....");
				socket = server.accept();
				System.out.println("Client accepted: " + socket);
				streamOutput = new DataOutputStream(socket.getOutputStream());
				streamOutput.writeUTF(yourscore);
				
			}catch (IOException e){
				
			}

		}
		public void close() {
			
		}
	}
	
	public class InputThread extends Thread{
		private boolean isConnect = false;
		private String getScore = null;
		public InputThread() {
			try {
                streamInput = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
                isConnect = true;
            } catch (IOException e) {
                e.printStackTrace();
            }
		}
		@Override
		public void run() {
			try {
                while (isConnect) {
                    getScore = streamInput.readUTF().toString();
                }
            }catch(Exception e){
                e.printStackTrace();
            }
		}
		
	}
	
	public class OutputThread extends Thread{
		public String sendScore = null;
		public void OutputTread() {
			try {
                streamOutput = new DataOutputStream(socket.getOutputStream());
            } catch (IOException e) {
                e.printStackTrace();
            }
		}
		@Override
		public void run() {
			try {
				streamOutput.writeUTF(sendScore);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
	}

}
