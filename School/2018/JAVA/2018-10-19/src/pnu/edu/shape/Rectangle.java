package pnu.edu.shape;

public class Rectangle implements AreaComputable {
	private int x_len, y_len;
	public Rectangle(int x_length,int y_length) {
		x_len = x_length;
		y_len = y_length;	
	}
	public String toString() {
		String msg;
		msg = "[ Rectangle "+ x_len + " " + y_len + " " + (float) getSize() + "]";
		return msg;
	}
	public int compareTo(AreaComputable other) {
		if ( !(other instanceof Rectangle) ) return 2 ;
		Rectangle otherRectangle = (Rectangle) other ;
		int returnValue = 0 ;
		if ( getSize() < otherRectangle.getSize() ) returnValue = 3 ;
		if ( getSize() == otherRectangle.getSize() ) returnValue = 0 ;
		if ( getSize() > otherRectangle.getSize() ) returnValue = 1 ;
		return returnValue ;
	}
	public boolean equal(AreaComputable other)
	{
		if ( !(other instanceof Rectangle) ) return false ;
		Rectangle otherRectangle = (Rectangle) other ;
		return (x_len == otherRectangle.x_len && y_len == otherRectangle.y_len);
	}
	public double getSize() {
		double result;
		result = x_len * y_len;	
		result = Math.round(result);
		return result;
	}
	
}
