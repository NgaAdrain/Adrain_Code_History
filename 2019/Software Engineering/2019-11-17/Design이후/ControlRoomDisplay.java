package mycode.Observer.elevatorlocation.after;

public class ControlRoomDisplay implements ElevatorObserver {
	private ElevatorController controller ;
	public ControlRoomDisplay(ElevatorController controller) {
		this.controller = controller ;
		this.controller.Attach(this);
	}
	public void update() {
		int curFloor = controller.getCurFloor() ;
		System.out.println("Control Room: " + curFloor) ;
	}
}
