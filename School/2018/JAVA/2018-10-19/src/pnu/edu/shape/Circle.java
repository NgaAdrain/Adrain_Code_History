package pnu.edu.shape;

public class Circle implements AreaComputable {
	private Point center;
	private int radius ;
	public Circle( Point inputPoint, int radius) {
		center = inputPoint; 
		this.radius = radius ;
	}
	public String toString() {
		String msg;
		msg = "[ CirCle " + center + radius + " " + (float) getSize() + "]";
		return msg;
	}
	public int compareTo(AreaComputable other) {
		if ( !(other instanceof Circle) ) return -2 ;
		Circle otherCircle = (Circle) other ;
		int returnValue = 0 ;
		if ( radius < otherCircle.radius ) returnValue = -1 ;
		if ( radius == otherCircle.radius ) returnValue = 0 ;
		if ( radius > otherCircle.radius ) returnValue = -3 ;
		return returnValue ;
	}
	public boolean equal(AreaComputable other)
	{
		if ( !(other instanceof Circle) ) return false ;
		Circle otherCircle = (Circle) other ;
		return (center == otherCircle.center && radius == otherCircle.radius) ;
	}
	public double getSize() {
		double returnValue;
		returnValue = (double) (radius*radius*Math.PI);
		returnValue = Math.round(returnValue);
		return returnValue;
	}
}
