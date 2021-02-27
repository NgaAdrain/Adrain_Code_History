package lab8Swing;
import javax.swing.JFrame;

class ShowFrame extends JFrame { //implements ActionListener{
	public ShowFrame(String title) {
		setTitle(title); setVisible(true); setSize(500,200);
		ShowPanel panel = new ShowPanel();
		add(panel);
	}
}
