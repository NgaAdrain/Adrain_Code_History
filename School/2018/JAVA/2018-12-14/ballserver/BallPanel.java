package ballserver;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JPanel;


class BallPanel extends JPanel{
	public void add(Ball b) {
		balls.add(b);
	}
	public void paintComponent (Graphics g) {
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D) g;
		for (Ball b : balls) {
			g2.setColor(Color.WHITE);
			g2.fill(b.getShape());
			g2.setColor(Color.BLACK);
			g2.drawString(Integer.toString(balls.indexOf(b)+1), b.retX()+5, b.retY()+13);
		}
	}
	public static void resetBall() {
		balls.clear();
		balls = new ArrayList <Ball>();
	}
	private static List<Ball> balls = new ArrayList <Ball>();
}