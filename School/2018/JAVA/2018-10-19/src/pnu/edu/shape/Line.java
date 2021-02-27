package pnu.edu.shape;
public class Line implements AreaComputable {
	public Line(Point point_1, Point point_2) {
		point1 = point_1;
		point2 =  point_2;
	}
	public String toString() {
		String msg;
		msg = "[ Line "+ point1 + point2 + (float) getSize() + "]";
		return msg;
	}
	private Point point1, point2 ;

	public int compareTo(AreaComputable other) {
		if ( !(other instanceof Line) ) return 2 ;
		Line otherLine = (Line) other ;
		int returnValue = 0 ;
		if ( getSize() < otherLine.getSize() ) returnValue = 3 ;
		if ( getSize() == otherLine.getSize() ) returnValue = 0 ;
		if ( getSize() > otherLine.getSize() ) returnValue = 1 ;
		return returnValue ;
	}
	public boolean equal(AreaComputable other)
	{
		if ( !(other instanceof Line) ) return false ;
		Line otherLine = (Line) other ;
		return (point1 == otherLine.point1 && point2 == otherLine.point2);
	}
	public double getSize() {
		double returnValue ;
		returnValue = point1.betweenLength(point2);
		returnValue = Math.round(returnValue);
		return returnValue;
	}
}