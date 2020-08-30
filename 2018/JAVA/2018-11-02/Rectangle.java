package lab;

public class Rectangle extends Shape {
	public Rectangle() {
		super.setValue(0,0);
	}
	public Rectangle(int len, int height){
		super.setValue(len, height);
	}
	public double getArea() {
		double result;
		result = (super.getLen() * super.getHigh());
		return result;
	}
	
	public boolean IsComparable(Shape other) { //print r ¿¡ »ç¿ë
		if ( !(other instanceof Rectangle) ) return false ;
		else return true;
	}
	
	public String toString() {
			String msg;
			msg =  "Rectangle " + super.getLen() + " " + super.getHigh() + " " + (int) getArea();
			return msg;
	}
}
