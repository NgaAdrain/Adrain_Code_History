import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;

class Ball{
	public Ball(int speed) {
		if(speed == 0) radio += speed; 
		else if(speed >0) radio = speed; 
		else radio /= -speed; 
	}
	public Ball(int speed,int x, int y) {
		if(speed == 0) radio += speed; 
		else if(speed >0) radio = speed; 
		else radio /= -speed; 
		this.x = x; this.y = y;
	}
	public void move(Rectangle2D bounds) { // java.awt.geom.Rectangle2D
		x += dx*radio; y += dy*radio;
		if (x < bounds.getMinX()) { x = bounds.getMinX(); dx = -dx; }
		if (x + XSIZE >= bounds.getMaxX()) { x = bounds.getMaxX() - XSIZE; dx= -dx; }
		if (y < bounds.getMinY()) { y = bounds.getMinY(); dy = -dy; }
		if (y + YSIZE >= bounds.getMaxY()) { y = bounds.getMaxY() - YSIZE; dy = -dy; }
		}
	public Ellipse2D getShape() {return new Ellipse2D.Double(x,y,XSIZE,YSIZE);}
	private static final int XSIZE = 15;
	private static final int YSIZE = 15;
	private double x = 0;//시작점x좌표
	private double y = 0;//시작점 y좌표
	private double dx = 1; //x축움직임
	private double dy = 1; //y축움직임
	private double radio = 1;
}