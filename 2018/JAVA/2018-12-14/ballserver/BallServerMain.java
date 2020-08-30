package ballserver;			//201524582 Á¤Èñ¼®
							//Ball Server main
import javax.swing.JFrame;

public class BallServerMain {
	public static JFrame frame;
	public static void main(String[] args ) {
		frame = new BallServerFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		BallServerFrame.OpenServer();
	}
	public static void SetVisibility(boolean onOff) {
		frame.setVisible(onOff);
	}
		}
