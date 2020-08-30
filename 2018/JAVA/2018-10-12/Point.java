package lab4Interface;

public class Point {
	public Point(int inputX, int inputY) {
		x = inputX;
		y = inputY;
	}
	public String toString() {
		String msg;
		msg = "[" + x + "," + y + "] ";
		return msg;
	}
	public long betweenLength(Point other) {
		long result;
		double tempX = Math.abs(this.x-other.x);
		tempX *= tempX;
		double tempY = Math.abs(this.y-other.y);
		tempY *= tempY;
		result = (long) Math.sqrt(tempX+tempY);
		return result;
	}
	private int x, y ;
}