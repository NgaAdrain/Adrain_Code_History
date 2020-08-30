import java.awt.*;
import java.awt.Desktop.Action;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.AbstractAction;

class BallFrame extends JFrame{
	public BallFrame() {
		setSize(DEFAULT_WIDTH,DEFAULT_HEIGHT);
		setTitle("BallBounceThread");
		JMenu speedMenu = new JMenu("Speed");
		JMenuItem fasterItem = speedMenu.add(new SpeedAction("Faster",true));
		JMenuItem slowerItem = speedMenu.add(new SpeedAction("Slower",false));
		speedMenu.add(fasterItem);
		speedMenu.add(slowerItem);
		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		menuBar.add(speedMenu);
		
		panel = new BallPanel();
		add(panel,BorderLayout.CENTER);
		JPanel buttonPanel = new JPanel();
		addButton(buttonPanel, "Add1", new ActionListener() {
			public void actionPerformed(ActionEvent event) {addOneBall(DELAY);}
		});//1개씩 생성하도록해야함
		addButton(buttonPanel, "Add2", new ActionListener() {public void actionPerformed(ActionEvent event) {addTwoBall(DELAY);}
		});//2개씩 생성하도록해야함
		addButton(buttonPanel, "Close", new ActionListener() {public void actionPerformed(ActionEvent event) {System.exit(0);}
		});
		add(buttonPanel, BorderLayout.SOUTH);
	}
	public void setDelay(boolean speed) {if(speed = true) DELAY--; else DELAY++;}
	public void addButton(Container c, String title, ActionListener listener) {
		JButton button = new JButton(title);
		c.add(button);
		button.addActionListener(listener);
	}
	// Add Bounce Ball
	public void addOneBall(int speed) {//여기 수정해야함
		Ball b = new Ball(DELAY);
		panel.add(b);
		Runnable r = new BallRunnable(b, panel);
		Thread t = new Thread(r);
		t.start();
	}
	public void addTwoBall(int speed) {//여기 수정해야함
		Ball b = new Ball(DELAY);
		panel.add(b);
		Runnable r = new BallRunnable(b, panel);
		Thread t = new Thread(r);
		t.start();
		Ball b1 = new Ball(DELAY,50,50);
		panel.add(b1);
		Runnable r1 = new BallRunnable(b1, panel);
		Thread t1 = new Thread(r1);
		t1.start();
	}
	private BallPanel panel;
	private class SpeedAction extends AbstractAction{
		public SpeedAction(String name, boolean input) {super(name); speed = input;}
		public void actionPerformed(ActionEvent e) {
			if(speed == true) DELAY++; 
			else DELAY--;
		}
		private boolean speed = true;
	}
	public static final int DEFAULT_WIDTH = 450;
	public static final int DEFAULT_HEIGHT = 350;
	public static final int STEPS = 1000000000;//공의 움직임 수 
	public int DELAY = 1;//공의 속도 조절 => final 해제해야함!
}


//// Action만들어야됨!

