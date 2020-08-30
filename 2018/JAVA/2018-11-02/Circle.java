package lab;

public class Circle extends Shape {
	private int radius,x,y;
	public Circle() { // java는 기본적으로 0으로 initialize한다!
//		this.x = 0;
//		this.y = 0;
//		this.radius = 0;
	}
	
	public Circle(int x, int y, int radius){
		this.x = x;
		this.y = y;
		this.radius = radius;
	}
	
	public double getArea() { //수업시간에 다시 확인해보기!
		double result;
		result = radius * radius * Math.PI;
		result = Math.floor(result*10000d)/10000d; //버림연산 floor버림 round 반올림 ceil 올림!!!!
		//result = Double.parseDouble(String.format("%.4f", result)); //자릿수 정하는 법!
		return result;
	}
	
	public boolean IsComparable(Shape other) { //print c 에 사용
		if ( !(other instanceof Circle) ) return false ;
		else return true;
	}
	
	public String toString() {
		String msg;
		msg =  "Circle " + x + " " + y + " " + getArea();
		return msg;
	}
}
