package ballserver;

import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;

class Ball{
	public Ball(int count) { this.count = count + "";
	}
	public Ball(int count,int x, int y) {
		this.count = count + "";
		this.x = x; this.y = y;
	}
	public void move(Rectangle2D bounds) { // java.awt.geom.Rectangle2D
		x += dx*radio; y += dy*radio;
		if (x < bounds.getMinX()) { x = bounds.getMinX(); dx = -dx; }
		if (x + XSIZE >= bounds.getMaxX()) { x = bounds.getMaxX() - XSIZE; dx= -dx; }
		if (y < bounds.getMinY()) { y = bounds.getMinY(); dy = -dy; }
		if (y + YSIZE >= bounds.getMaxY()) { y = bounds.getMaxY() - YSIZE; dy = -dy; }
		}
	public String retCount(){return count;}
	public int retX() {return (int) x;}
	public int retY() {return (int) y;}
	public Ellipse2D getShape() {Ellipse2D shape = new Ellipse2D.Double(x,y,XSIZE,YSIZE); 
		return shape;}
	private static final int XSIZE = 15;
	private static final int YSIZE = 15;
	private static String count;
	private double x = 0;//시작점x좌표
	private double y = 0;//시작점 y좌표
	private double dx = 5; //x축움직임
	private double dy = 5; //y축움직임
	private double radio = 1;
	
}