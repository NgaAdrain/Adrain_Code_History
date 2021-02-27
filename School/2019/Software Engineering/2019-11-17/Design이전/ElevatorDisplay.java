package mycode.Observer.elevatorlocation.before;

public class ElevatorDisplay  {
	private ElevatorController controller ;
	public ElevatorDisplay(ElevatorController controller) {
		this.controller = controller ;
	}
	public void update() {
		int curFloor = controller.getCurFloor() ;
		System.out.println("Elevator Display: " + curFloor) ;
	}
}
