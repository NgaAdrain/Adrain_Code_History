package mycode.Observer.elevatorlocation.before;

public class FloorDisplay {
	private ElevatorController controller ;
	public FloorDisplay(ElevatorController controller) {
		this.controller = controller ;
	}
	public void update() {
		int curFloor = controller.getCurFloor() ;
		System.out.println("Floor Display: " + curFloor) ;
	}
}
