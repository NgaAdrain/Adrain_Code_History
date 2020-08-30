package mycode.Observer.elevatorlocation.after;

public class ElevatorDisplay implements ElevatorObserver {
	private ElevatorController controller ;
	public ElevatorDisplay(ElevatorController controller) {
		this.controller = controller ;
		this.controller.Attach(this);
	}
	public void update() {
		int curFloor = controller.getCurFloor() ;
		System.out.println("Elevator Display: " + curFloor) ;
	}
}
