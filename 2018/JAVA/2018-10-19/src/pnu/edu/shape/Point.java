package pnu.edu.shape;

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
	public double betweenLength(Point other) {
		double result;
		double tempX = Math.abs(this.x-other.x);
		tempX *= tempX;
		double tempY = Math.abs(this.y-other.y);
		tempY *= tempY;
		result = Math.sqrt(tempX+tempY);
		return result;
	}
	private int x, y ;
}