package mycode.Observer.elevatorlocation.before;

public class ControlRoomDisplay {
	private ElevatorController controller ;
	public ControlRoomDisplay(ElevatorController controller) {
		this.controller = controller ;
	}
	public void update() {
		int curFloor = controller.getCurFloor() ;
		System.out.println("Control Room: " + curFloor) ;
	}
}
