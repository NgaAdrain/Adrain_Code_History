package ballclient;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;


public class ClientFrame extends JFrame{
	public ClientFrame() {
	setSize(DEFAULT_WIDTH,DEFAULT_HEIGHT);
	setTitle("Ball Client");
	//file메뉴생성//
	JMenu fileMenu = new JMenu("File");
	JMenuItem openItem = fileMenu.add(new FileAction("Open"));
	JMenuItem closeItem = fileMenu.add(new FileAction("Close"));
	JMenuItem exitItem = fileMenu.add(new FileAction("Exit"));
	//ball메뉴생성//
	JMenu ballMenu = new JMenu("Ball");
	JMenuItem add1Item = ballMenu.add(new BallAction("Add1"));
	JMenuItem add2Item = ballMenu.add(new BallAction("Add2"));
	JMenuBar menuBar = new JMenuBar();
	setJMenuBar(menuBar);
	menuBar.add(fileMenu);
	menuBar.add(ballMenu);
	//하단 버튼생성//
	buttonPanel = new JPanel();
	JButton ConnectButton = new JButton("Connect");
	JButton DisconnectButton = new JButton("Disconnect");
	buttonPanel.add(ConnectButton);
	buttonPanel.add(DisconnectButton);
	add(buttonPanel, BorderLayout.SOUTH);
	ConnectButton.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent event) {
			ClientMain.Connect();
			}	
		});
	DisconnectButton.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent event) {
			ClientMain.DisConnect();
			}
		});
	}
	
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
	private class FileAction extends AbstractAction{
		private String action;
		public FileAction(String name) {super(name); action = name;}
		public void actionPerformed(ActionEvent e) {
			switch(action) {
			case "Open":
				ClientMain.Send("Show");;
				//server화면 표시
				break;
			case "Close":
				ClientMain.Send("Reset");
				//server화면 숨김 & ball소거 & 일련번호 초기화
				break;
			case "Exit":
				try {
				ClientMain.Send("Exit");
				System.exit(0);
				}catch ( NullPointerException e1 ) {System.exit(0); System.out.println("Server Closed Now"); }
				break;
			default:
				break;
			}
			
		}
	}
	
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//	
	private class BallAction extends AbstractAction{
		private String action;
		public BallAction(String name) {super(name);action = name;}
		public void actionPerformed(ActionEvent e) {
			switch(action) {
			case "Add1":
				ClientMain.Send("Add1");
				//server에 공을 1개 생성하도록 코드를 보냄
				break;
			case "Add2":
				ClientMain.Send("Add2");
				//server에 공을 2개 보내도록 명령을 보냄
				break;
			default:
				break;
			}
		}
	}
	
	private static final int DEFAULT_WIDTH = 450;
	private static final int DEFAULT_HEIGHT = 350;
	private JPanel buttonPanel;

}

