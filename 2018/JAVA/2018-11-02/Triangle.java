package lab;

public class Triangle extends Shape {
	public Triangle() {
		super.setValue(0,0);
	}
	public Triangle(int len, int height){
		super.setValue(len, height);
	}
	public double getArea() {
		double result;
		result = (super.getLen() * super.getHigh());
		result = Math.round(result/2);
		return result;
	}
	
	public boolean IsComparable(Shape other) { //print t ¿¡ »ç¿ë
		if ( !(other instanceof Triangle) ) return false ;
		else return true;
	}

	public String toString() {
		String msg;
		msg =  "Triangle " + super.getLen() + " " + super.getHigh() + " " + (int) getArea();
		return msg;
	}
}
