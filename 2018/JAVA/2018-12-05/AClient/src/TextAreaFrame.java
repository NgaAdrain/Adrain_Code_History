import java.awt.*;							//201524582 ¡§»ÒºÆ
import java.awt.event.*;					//client¿« UI
import javax.swing.*;
public class TextAreaFrame extends JFrame {
	public TextAreaFrame() {
		setTitle("EchoClient");
		setSize(1000, 600);
		textArea = new JTextArea(80, 40);
		scrollPane = new JScrollPane(textArea);
		add(scrollPane, BorderLayout.CENTER);
		buttonPanel = new JPanel();
		JButton ConnectButton = new JButton("Connect");
		JButton DisconnectButton = new JButton("Disconnect");
		JButton helloWorldButton = new JButton("hello World");
		JButton SendButton = new JButton("Send");
		JButton ClearButton = new JButton("Clear");
		JButton QuitButton = new JButton("Quit");
		buttonPanel.add(ConnectButton);
		buttonPanel.add(DisconnectButton);
		buttonPanel.add(helloWorldButton);
		buttonPanel.add(SendButton);
		buttonPanel.add(ClearButton);
		buttonPanel.add(QuitButton);
		ConnectButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				EchoClient.Connect();
			}
		});
		DisconnectButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				EchoClient.DisConnect();
			}
		});
		helloWorldButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				msg = "hello World";
			}
		});
		SendButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				textArea.append("Send: "+ msg + "\n");
				EchoClient.Send(msg);
			}
		});
		ClearButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				textArea.setText(null);
			}
		});
		QuitButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				System.exit(0);
			}
		});
		add(buttonPanel, BorderLayout.SOUTH);
	}
	public void ReceiveMsg(String msg) {
		textArea.append("Receive: "+ msg +"\n");
	}
	public void Receive(String msg) {
		textArea.append(msg + "\n");
	}
	
	public static final int DEFAULT_WIDTH = 300;
	public static final int DEFAULT_HEIGHT = 300;
	private JTextArea textArea;
	private JScrollPane scrollPane;
	private JPanel buttonPanel;
	private String msg;
}