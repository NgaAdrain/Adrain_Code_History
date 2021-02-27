package lab;

public class Circle extends Shape {
	private int radius,x,y;
	public Circle() { // java�� �⺻������ 0���� initialize�Ѵ�!
//		this.x = 0;
//		this.y = 0;
//		this.radius = 0;
	}
	
	public Circle(int x, int y, int radius){
		this.x = x;
		this.y = y;
		this.radius = radius;
	}
	
	public double getArea() { //�����ð��� �ٽ� Ȯ���غ���!
		double result;
		result = radius * radius * Math.PI;
		result = Math.floor(result*10000d)/10000d; //�������� floor���� round �ݿø� ceil �ø�!!!!
		//result = Double.parseDouble(String.format("%.4f", result)); //�ڸ��� ���ϴ� ��!
		return result;
	}
	
	public boolean IsComparable(Shape other) { //print c �� ���
		if ( !(other instanceof Circle) ) return false ;
		else return true;
	}
	
	public String toString() {
		String msg;
		msg =  "Circle " + x + " " + y + " " + getArea();
		return msg;
	}
}
