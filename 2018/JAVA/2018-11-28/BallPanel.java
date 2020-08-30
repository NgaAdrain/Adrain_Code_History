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
		for (Ball b : balls) {g2.fill(b.getShape());}
	}
	private List<Ball> balls = new ArrayList <Ball>();
}