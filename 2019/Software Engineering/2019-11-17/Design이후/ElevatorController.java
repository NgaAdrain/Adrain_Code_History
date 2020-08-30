package mycode.Observer.elevatorlocation.after;

public class ElevatorController extends ElevatorSubject{
	private int curFloor = 1;
	
	public void gotoFloor(int destination) {
		curFloor = destination ;
		super.Notify();
	}
	public int getCurFloor() {
		return curFloor ;
	}
}
