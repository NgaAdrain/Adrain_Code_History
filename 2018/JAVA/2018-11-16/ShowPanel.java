package lab8Swing;
import javax.swing.JPanel;
import javax.swing.Action;
import javax.swing.ActionMap;
import javax.swing.JButton;

class ShowPanel extends JPanel{
	//define actions => Add, Remove First, Remove Last, Remove All, Quit
	public ShowPanel() {
	Action addAction = new ShowAction("Add");
	Action rFAction = new ShowAction("Remove First");
	Action rLAction = new ShowAction("Remove Last");
	Action rAAction = new ShowAction("Remove All");
	Action qAction = new ShowAction("Quit");
	add(new JButton(addAction));
	add(new JButton(rFAction));
	add(new JButton(rLAction));
	add(new JButton(rAAction));
	add(new JButton(qAction));
	ActionMap amap = getActionMap();
	amap.put("panel.Add",addAction);
	amap.put("panel.Remove First",rFAction);
	amap.put("panel.Remove Last",rLAction);
	amap.put("panel.Remove All",rAAction);
	amap.put("panel.Quit",qAction);
	}
}
