package Lab_3;

public class Movie { //final class
	public Movie(String name, float inputType) {
		movieName = name;
		chargeType = inputType;
	}
	public float returnType() {
		return chargeType;
	}
	static public final float CHILDREN = 1.5f;
	static public final float REGULAR = 2;
	static public final float NEW_RELEASE = 3;
	public String returnName() {
		return movieName;
	}
	private String movieName;
	private final float chargeType;
}
