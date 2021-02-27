package lab;	//������ǻ�Ͱ��к� ������ǻ�Ͱ������� 201524582 ����
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Refactor -> Rename //�ش纯���� �̸��� �ѹ��� �ٲܼ� �ִ�!
// Refactor -> Extract Method //����ó���� �κ��� ������ �ִ� //METHOD
// Main //�Լ��� �ִ��� ª�� ����� ���� �ٶ����ϴ�!
// ctrl + / : //���õ� �� �ּ�ó��!
// divide & conquer //����!//
// ���ؿ��̼� -> ������ �帧��� ¥�°� //
enum OperationKind {ADD,PRINT,PRINTALL,REMOVEALL,TOTALAREA,QUIT,INVALID} ;
enum ShapeKind {T,C,R,INVALID}; //T:Triangle C:Circle R:Rectangle
public class Editor {
	private static Scanner scanner = new Scanner(System.in);
	private static List<Shape> shapeList = new ArrayList<Shape>();
	public static void main(String[] args) {
		//boolean done = true;
		while ( true ){
			final OperationKind op = getOperation();
			final boolean done = execute(op);
			if(!done) //���ؿ��̼��� ����(UNDERSTANDABILITY, ANALIZEABILITY)
				break;
		}
	}

	private static boolean execute(final OperationKind kind) {
		if ( kind == OperationKind.QUIT ) {
			System.out.println("Bye") ;
			return false;
		}
		switch ( kind ) {
			case ADD : 
				addShape();
				break;
			case PRINT : 
				printShape();
				break;
			case PRINTALL:
				printAll(); // refactor -> extract 
				break;
			case REMOVEALL: 
				remove();
				break;
			case TOTALAREA: //�����ð��� ��������! double���� ��� ���ϴ� ����!-> ����ؾ��Ѵ�!
				getTotalArea();
				break;
			default :
				System.out.println("Invalid Operation!") ;
				break;	
		}
		return true;
	}
	
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//
	//OPERATION//
	public static OperationKind getOperation() {
		OperationKind op = OperationKind.INVALID;
		final String inputOper = scanner.next();
		if(inputOper.equalsIgnoreCase("ADD"))
			op = OperationKind.ADD;
		else if(inputOper.equalsIgnoreCase("PRINT"))
			op = OperationKind.PRINT;
		else if(inputOper.equalsIgnoreCase("PRINTALL"))
			op = OperationKind.PRINTALL;
		else if(inputOper.equalsIgnoreCase("REMOVEALL"))
			op = OperationKind.REMOVEALL;
		else if(inputOper.equalsIgnoreCase("TOTALAREA"))
			op = OperationKind.TOTALAREA;
		else if(inputOper.equalsIgnoreCase("QUIT"))
			op = OperationKind.QUIT;
		return op;
	}
	
	public static ShapeKind getShape() {
		ShapeKind op = ShapeKind.INVALID;
		final String inputOper = scanner.next();
		if(inputOper.equalsIgnoreCase("R"))
			op = ShapeKind.R;
		else if(inputOper.equalsIgnoreCase("C"))
			op = ShapeKind.C;
		else if(inputOper.equalsIgnoreCase("T"))
			op = ShapeKind.T;
		return op;
	}
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//
	//MAIN//
	private static void addShape() {
		ShapeKind sh;
		sh = getShape();
		switch(sh) {
			case T: //������ �����ϱ� 
				createTriangle(); 
				break;
			case C: //������ �����ϱ�
				createCircle(); 
				break;
			case R: //������ �����ϱ�
				createRectangle(); 
				break;
			default:
				System.out.println("INVALID OPERATION!");
				break;
		}
	}
	
	private static void printShape() {
		ShapeKind sh;
		sh = getShape();
		switch(sh) {
			case T:
			printTriangle();
				break;
			case C:
			printCircle();
				break;
			case R:
			printRectangle();
				break;
			default:
				System.out.println("INVALID OPERATION!");
				break;
			}
	}
	
	private static void printAll() {
		for(Shape x : shapeList)
			System.out.println(x);
	}
	
	private static void remove() {
		int count = 0;
		for(Shape x : shapeList)
			count++;
		System.out.println(count);
		shapeList.clear();
	}

	private static void getTotalArea() {
		double totalArea = 0;
		boolean decision = false;
		final Circle compareCircle = new Circle();
		for(Shape x : shapeList) {
			totalArea += x.getArea();
			if(x.IsComparable(compareCircle))
				decision = true;
		}
		if(decision == true)	
			System.out.println(totalArea);
		else
			System.out.println((int)totalArea); 
	}
	//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//
		//ADDSHAPE//
	private static void createTriangle() {
		final int len = scanner.nextInt();
		final int height = scanner.nextInt();
		scanner.nextLine();
		Triangle returnTriangle = new Triangle(len,height);
		System.out.println(returnTriangle);
		shapeList.add(returnTriangle);
	}
	
	private static void createCircle() {
		final int x = scanner.nextInt();
		final int y = scanner.nextInt();
		final int radius = scanner.nextInt();
		scanner.nextLine();
		Circle returnCircle = new Circle(x,y,radius);
		System.out.println(returnCircle);
		shapeList.add(returnCircle);
	}
	
	private static void createRectangle() {
		final int len = scanner.nextInt();
		final int height = scanner.nextInt();
		scanner.nextLine();
		Rectangle returnRectangle = new Rectangle(len,height);
		System.out.println(returnRectangle);
		shapeList.add(returnRectangle);
	}
	
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//
	//PRINTSHAPE//
	private static void printRectangle() {
		int count = 0;
		final Rectangle compareRectangle = new Rectangle();
		for(Shape x : shapeList) {
			if(x.IsComparable(compareRectangle)) {
				System.out.println(x);
				count++;
			}
		}
		if(count == 0)
			System.out.println("NONE");
	}
	
	private static void printCircle() {
		int count = 0;
		final Circle compareCircle = new Circle();
		for(Shape x : shapeList) {
			if(x.IsComparable(compareCircle)) {
				System.out.println(x);
				count++;
			}
		}
		if(count == 0)
			System.out.println("NONE");
	}
	
	private static void printTriangle() {
		int count = 0;
		final Triangle compareTriangle = new Triangle();
		for(Shape x : shapeList) {
			if(x.IsComparable(compareTriangle)) {
				System.out.println(x);
				count++;
			}
		}
		if(count == 0)
			System.out.println("NONE");
	}
}
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�//