package lab;

abstract class Shape { // 하나의 변수가 다른 object에 따라서 다른의미로 해석되면 바람직하지 못한다!
	public Shape() {} // java는 기본적으로 0으로 initialize한다!
	public Shape(int len, int height) {
		this.len = len;
		this.height = height;
	}
	
	public void setValue(int len, int height) {
		this.len = len;
		this.height = height;
	}
	
	public int getLen() {
		return len;
	}
	
	public int getHigh() {
		return height;
	}
	
	public abstract String toString(); // toString을 빼먹지 않도록 하기 위함
	public abstract double getArea(); //circ는 circulate랑 circle의 혼동이 올수 있으므로 
	public abstract boolean IsComparable(Shape other);
	
	private int len, height ; //line, circle은 좌표 사용. -> sub class에서 따로 사용
}

