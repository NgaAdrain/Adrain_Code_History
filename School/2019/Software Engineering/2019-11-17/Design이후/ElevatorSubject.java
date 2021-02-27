package mycode.Observer.elevatorlocation.after;

import java.util.ArrayList;
import java.util.List;

public class ElevatorSubject {
	public void Attach(ElevatorObserver observer) {
		observers.add(observer);
	}
	public void Detach(ElevatorObserver observer) {
		observers.remove(observer);
	}
	public void Notify() {
		for(ElevatorObserver ob:observers) {
			ob.update();
		}
	}
	private List<ElevatorObserver> observers = new ArrayList<ElevatorObserver>();
	//List는 Interface ArrayList가 구현되어있는 것!
}
