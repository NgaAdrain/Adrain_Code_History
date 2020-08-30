package mycode.Observer.elevatorlocation.before;

public class ElevatorController {
	private int curFloor = 1;
	private ElevatorDisplay elevatorDisplay ;
	private FloorDisplay floorDisplay ;
	private ControlRoomDisplay controlRoomDisplay ;
	
	public void gotoFloor(int destination) {
		curFloor = destination ;
		elevatorDisplay.update();
		floorDisplay.update() ;
		controlRoomDisplay.update() ;
	}
	public int getCurFloor() {
		return curFloor ;
	}
	public void setElevatorDisplay(ElevatorDisplay elevatorDisplay) {
		this.elevatorDisplay = elevatorDisplay;
	}
	public void setFloorDisplay(FloorDisplay floorDisplay) {
		this.floorDisplay = floorDisplay;
	}
	public void setControlRoomDisplay(ControlRoomDisplay controlRoomDisplay) {
		this.controlRoomDisplay = controlRoomDisplay;
	}
}
