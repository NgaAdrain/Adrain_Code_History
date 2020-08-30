package lab;

abstract class Shape { // �ϳ��� ������ �ٸ� object�� ���� �ٸ��ǹ̷� �ؼ��Ǹ� �ٶ������� ���Ѵ�!
	public Shape() {} // java�� �⺻������ 0���� initialize�Ѵ�!
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
	
	public abstract String toString(); // toString�� ������ �ʵ��� �ϱ� ����
	public abstract double getArea(); //circ�� circulate�� circle�� ȥ���� �ü� �����Ƿ� 
	public abstract boolean IsComparable(Shape other);
	
	private int len, height ; //line, circle�� ��ǥ ���. -> sub class���� ���� ���
}

