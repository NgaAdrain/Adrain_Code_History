package lab4Interface;

public class Circle implements MyComparable {
	private Point center;
	private int radius ;
	public Circle( Point inputPoint, int radius) {
		center = inputPoint; 
		this.radius = radius ;
	}
	public String toString() {
		String msg;
		msg = "[" + center + radius + " " + getSize() + "]";
		return msg;
	}
	public int compareTo(MyComparable other) {
		if ( !(other instanceof Circle) ) return -2 ;
		Circle otherCircle = (Circle) other ;
		int returnValue = 0 ;
		if ( radius < otherCircle.radius ) returnValue = -1 ;
		if ( radius == otherCircle.radius ) returnValue = 0 ;
		if ( radius > otherCircle.radius ) returnValue = -3 ;
		return returnValue ;
	}
	public boolean equal(MyComparable other)
	{
		if ( !(other instanceof Circle) ) return false ;
		Circle otherCircle = (Circle) other ;
		return (center == otherCircle.center && radius == otherCircle.radius) ;
	}
	public long getSize() {
		long returnValue;
		returnValue = (long) (radius*radius*Math.PI);
		return returnValue;
	}
}
