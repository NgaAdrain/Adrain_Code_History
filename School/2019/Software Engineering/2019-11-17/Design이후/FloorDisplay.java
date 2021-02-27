package mycode.Observer.elevatorlocation.after;

public class FloorDisplay implements ElevatorObserver {
	private ElevatorController controller ;
	public FloorDisplay(ElevatorController controller) {
		this.controller = controller ;
		this.controller.Attach(this);
	}
	public void update() {
		int curFloor = controller.getCurFloor() ;
		System.out.println("Floor Display: " + curFloor) ;
	}
}
