package pnu;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.InputMismatchException;


public class RectangleManager {
	private ArrayList<MyRectangle> rectangles = new ArrayList<MyRectangle>() ;
	private Scanner scannerObject ;
	public RectangleManager(Scanner scanner) {
		scannerObject = scanner;
	}
	public static void main(String[] args) {
		Scanner scannerObject = new Scanner(System.in) ;
		RectangleManager manager = new RectangleManager(scannerObject) ;
		while ( true ) {
			System.out.println("Enter a command: [create width height, zoom id ratio or quit]") ;
			final String command = scannerObject.next() ;
			if ( command.equalsIgnoreCase("create")) { manager.create() ; }
			else if ( command.equalsIgnoreCase("zoom")) { manager.zoom() ; }
			else if ( command.equalsIgnoreCase("showAll")) { manager.showAll() ; }
			if ( command.equalsIgnoreCase("quit")) { System.out.println("Bye") ; break ; }
			}
		scannerObject.close();
	}
	
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//
	//main method//
	void create() {
		try {
			final int width = scannerObject.nextInt();
			final int length = scannerObject.nextInt();
			if(width<0||length<0) throw new InvalidRectangleException(width,length) ;
			MyRectangle tmp = new MyRectangle(width,length);
			rectangles.add(tmp);
			System.out.println(tmp);
		}
		catch(InvalidRectangleException eMinus) {
			System.out.println(eMinus);//�Ʒ� �ڵ�� ���� �۵�!
			//System.out.println("�簢���� ���̿� ���̴� ����̾�� �մϴ�. " + eMinus.getWidth() + " " + eMinus.getHeight());
		}
		catch(InputMismatchException e) { // nextInt���� throw�ϴ� ���� ����!
			System.out.println("�Էµ� ������ ������ ���� �ʽ��ϴ�.");
		}
	}
	
	void zoom() {
		try {
			int index = scannerObject.nextInt();
			int ratio = scannerObject.nextInt();
			MyRectangle after = new MyRectangle(ratio*rectangles.get(index).getWide(),ratio*rectangles.get(index).getHeight());
			System.out.println("Before: " + rectangles.get(index));
			System.out.println("After: " + after);
			rectangles.add(index,after);
			rectangles.remove(index+1);			
		}
		catch(IndexOutOfBoundsException e) {//�迭 index�� �ƴ� �κ��� ȣ���� ��  throw�ϴ� ���� ����
			System.out.println("�������� �ʴ� �迭�� ���Ҹ� �����߽��ϴ�." + e);
		}
	}
	
	void showAll() {
		for(MyRectangle x : rectangles) 
			System.out.println(x);
	}
}

//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//
//User-defined exception//
class InvalidRectangleException extends Exception {
	private int width, height ;
	public InvalidRectangleException(int width, int height) {
		this.width = width ; this.height = height ;
	}
	public String toString() {
		String msg = "�簢���� ���̿� ���̴� ����̾�� �մϴ�. "+ width + " " + height; 
		return msg;
	}
	public int getWidth() { return width; }
	public int getHeight() { return height; }
}