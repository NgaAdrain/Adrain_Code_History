package lab;	//전기컴퓨터공학부 정보컴퓨터공학전공 201524582 정희석
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Refactor -> Rename //해당변수의 이름을 한번에 바꿀수 있다!
// Refactor -> Extract Method //음영처리된 부분을 묶을수 있다 //METHOD
// Main //함수는 최대한 짧게 만드는 것이 바람직하다!
// ctrl + / : //선택된 행 주석처리!
// divide & conquer //연습!//
// 이해용이성 -> 생각의 흐름대로 짜는것 //
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
			if(!done) //이해용이성이 높다(UNDERSTANDABILITY, ANALIZEABILITY)
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
			case TOTALAREA: //수업시간에 수정하자! double형은 출력 안하는 건지!-> 출력해야한다!
				getTotalArea();
				break;
			default :
				System.out.println("Invalid Operation!") ;
				break;	
		}
		return true;
	}
	
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
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
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
	//MAIN//
	private static void addShape() {
		ShapeKind sh;
		sh = getShape();
		switch(sh) {
			case T: //개별로 구현하기 
				createTriangle(); 
				break;
			case C: //개별로 구현하기
				createCircle(); 
				break;
			case R: //개별로 구현하기
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
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
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
	
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
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
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//