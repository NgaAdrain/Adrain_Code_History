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
	//file�޴�����//
	JMenu fileMenu = new JMenu("File");
	JMenuItem openItem = fileMenu.add(new FileAction("Open"));
	JMenuItem closeItem = fileMenu.add(new FileAction("Close"));
	JMenuItem exitItem = fileMenu.add(new FileAction("Exit"));
	//ball�޴�����//
	JMenu ballMenu = new JMenu("Ball");
	JMenuItem add1Item = ballMenu.add(new BallAction("Add1"));
	JMenuItem add2Item = ballMenu.add(new BallAction("Add2"));
	JMenuBar menuBar = new JMenuBar();
	setJMenuBar(menuBar);
	menuBar.add(fileMenu);
	menuBar.add(ballMenu);
	//�ϴ� ��ư����//
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
	
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//
	private class FileAction extends AbstractAction{
		private String action;
		public FileAction(String name) {super(name); action = name;}
		public void actionPerformed(ActionEvent e) {
			switch(action) {
			case "Open":
				ClientMain.Send("Show");;
				//serverȭ�� ǥ��
				break;
			case "Close":
				ClientMain.Send("Reset");
				//serverȭ�� ���� & ball�Ұ� & �Ϸù�ȣ �ʱ�ȭ
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
	
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//	
	private class BallAction extends AbstractAction{
		private String action;
		public BallAction(String name) {super(name);action = name;}
		public void actionPerformed(ActionEvent e) {
			switch(action) {
			case "Add1":
				ClientMain.Send("Add1");
				//server�� ���� 1�� �����ϵ��� �ڵ带 ����
				break;
			case "Add2":
				ClientMain.Send("Add2");
				//server�� ���� 2�� �������� ����� ����
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

