package lab8Swing;

import java.awt.event.ActionEvent;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JOptionPane;

class ShowAction extends AbstractAction {
	public ShowAction(String actionName) {
		putValue(Action.NAME,actionName);
		putValue(Action.SHORT_DESCRIPTION,"Help for " + actionName);
	}
	public void actionPerformed(ActionEvent event) {
		if(event.getActionCommand() == "Quit") System.exit(0);
		final String cmd = "This button for " + event.getActionCommand();
		JOptionPane.showMessageDialog(null, cmd) ;
	}
}
