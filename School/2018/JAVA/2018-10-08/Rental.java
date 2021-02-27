package Lab_3;

public class Rental { //second class
	public Rental(Movie movieInfo, int day) {
		info = movieInfo;
		if(info.returnType() == Movie.CHILDREN) {
			if(day <=3)
				charges = info.returnType();
			else {
				charges = 1.5f + (day-3)*1.5f;
			}
		}
		else if(info.returnType() == Movie.REGULAR) {
			if(day <=2)
				charges = info.returnType();
			else {
				charges = info.returnType() + (day-2)*1.5f;
			}
		}
		else {
			charges = day*info.returnType();
		}
	}
	public String returnRentalInfo() {
		String output;
		output = "\t" + info.returnName() + ": " + charges + "\n";
		return output;
	}
	public float Outputcharge() {
		return charges;
	}
	private Movie info;
	private float charges;
}
