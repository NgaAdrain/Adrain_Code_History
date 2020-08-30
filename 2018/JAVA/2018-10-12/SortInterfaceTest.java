package lab4Interface;  // 201524582 전기컴퓨터공학부 정보컴퓨터공학전공 정희석
						// problem! 3항이상의 다항sort불가!
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

enum OperationKind {ADD_C, ADD_L, LIST, CLEAR, SORT_A, SORT_D, QUIT, INVALID} ;
enum SortKind {ASCENDING, DESCENDING} ;
public class SortInterfaceTest {
	private static Scanner scanner = new Scanner(System.in);
	private static List<MyComparable> comparableList = new ArrayList<MyComparable>() ;
	private static List<MyComparable> newList = new ArrayList<MyComparable>() ;
	public static void main(String[] args) {
		while ( true ) {
			final OperationKind op = getOperation() ;
			if ( op == OperationKind.QUIT ) {
				System.out.println("Bye") ;
				break;
			}
			if ( op == OperationKind.INVALID ) {
				System.out.println("Invalid Operation!") ;
				continue ;
			}
			switch ( op ) {
			case ADD_L : {
				final Line newLine = createLine() ;
				System.out.println(newLine) ;
				break ;
			}
			case ADD_C : {
				final Circle newCircle = createCircle() ;
				System.out.println(newCircle) ;
				break ;
			}
			case SORT_A: // LineFirst , CircleLast
				newList = new ArrayList<MyComparable>() ;
				sortList(comparableList, SortKind.ASCENDING) ;
				comparableList = newList;
				break ;
			case SORT_D: // CircleFirst, LineLast
				newList = new ArrayList<MyComparable>() ;
				sortList(comparableList, SortKind.DESCENDING) ;
				comparableList = newList;
				break ;
			case CLEAR:	
				comparableList.clear() ;
				break ;
			case LIST:
				System.out.println(comparableList) ;
				break ;
			}
		}
	}
	private static OperationKind getOperation() {
		System.out.print("Enter Operation String! ") ;
		final String operation = scanner.next() ;
		OperationKind kind = OperationKind.INVALID ;
		if ( operation.equalsIgnoreCase("ADDL"))
			kind = OperationKind.ADD_L ;
		if ( operation.equalsIgnoreCase("ADDC"))
			kind = OperationKind.ADD_C ;
		else if ( operation.equalsIgnoreCase("LIST"))
			kind = OperationKind.LIST ;
		else if ( operation.equalsIgnoreCase("SORTA"))
			kind = OperationKind.SORT_A ;
		else if ( operation.equalsIgnoreCase("SORTD"))
			kind = OperationKind.SORT_D ;
		else if ( operation.equalsIgnoreCase("CLEAR"))
			kind = OperationKind.CLEAR ;
		else if ( operation.equalsIgnoreCase("QUIT"))
			kind = OperationKind.QUIT ;
		return kind ;
	}
	private static Circle createCircle() {
		final int x = scanner.nextInt() ;
		final int y = scanner.nextInt() ;
		final int radius = scanner.nextInt() ;
		final Circle newCircle = new Circle(new Point(x, y), radius) ;
		comparableList.add(newCircle) ;
		return newCircle ;
	}
	private static Line createLine() {
		final int x1 = scanner.nextInt() ;
		final int y1 = scanner.nextInt() ;
		final int x2 = scanner.nextInt() ;
		final int y2 = scanner.nextInt() ;
		final Line newLine = new Line(new Point(x1, y1), new Point(x2, y2)) ;
		comparableList.add(newLine) ;
		return newLine ;
	}
	
	private static void sortList(final List<MyComparable> comparableList, final SortKind sortKind) {
			switch(sortKind) {
				case ASCENDING : //Line First, Circle Last; // u = Circle, v = Line ==> return -2
					for(MyComparable u : comparableList) {
						for(MyComparable v : comparableList) {
							if(u.compareTo(v) == -2) { //ordered u = Circle - v = Line
								newList.add(v);
								newList.add(u);
								break;
							}
							else if(u.compareTo(v) == 0 || u.compareTo(v) == 2) {
								continue;
							}
							
							else {
								newList.add(u);
								break;
							}
						}
					}
					break;
				case DESCENDING : //Line Last, Circle First; // u =Line, v = Circle ==> return 2
					for(MyComparable u : comparableList) {
						for(MyComparable v : comparableList) {
							if(u.compareTo(v) == 2) { //ordered Line - Circle
								newList.add(v);
								newList.add(u);
								break;
							}
							else if(u.compareTo(v) == 0 || u.compareTo(v) == -2) {
								continue;
							}
							else {
								newList.add(u);
								break;
							}
						}
						break;
					}
			}
	}
}