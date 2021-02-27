package mycode.Observer.elevatorlocation.after;

public class Client {
	public static void main(String[] args) {
		ElevatorController controller = new ElevatorController() ;

		ElevatorDisplay elevatorDisplay = new ElevatorDisplay(controller) ;
		FloorDisplay floorDisplay = new FloorDisplay(controller) ;
		ControlRoomDisplay controlRoomDisplay = new ControlRoomDisplay(controller) ;
		
		controller.gotoFloor(5) ;
		controller.gotoFloor(10) ;	
	}
}