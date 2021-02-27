package pnu.edu.editor;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import pnu.edu.shape.*;

public class EditorTest {
	private static Scanner scanner = new Scanner(System.in);
	public static Circle createCircle() {
		  final int x = scanner.nextInt() ;
		  final int y = scanner.nextInt() ;
		  final int radius = scanner.nextInt() ;
		  final Circle newCircle = new Circle(new Point(x, y), radius) ;
		  return newCircle ;
		 }
	public static Line createLine() {
		  final int x1 = scanner.nextInt() ;
		  final int y1 = scanner.nextInt() ;
		  final int x2 = scanner.nextInt() ;
		  final int y2 = scanner.nextInt() ;
		  final Line newLine = new Line(new Point(x1, y1), new Point(x2, y2)) ;
		  return newLine ;
		 }
	public static Rectangle createRectangle() {
		  final int x = scanner.nextInt() ;
		  final int y = scanner.nextInt() ;
		  final Rectangle newRectangle = new Rectangle(x,y);
		  return newRectangle;
		 }
	private static OperationKind getOperation() {
		  System.out.print("Enter Operation String! ") ;
		  final String operation = scanner.next() ;
		  OperationKind kind = OperationKind.INVALID ;
		  if ( operation.equalsIgnoreCase("ADDL"))
			  kind = OperationKind.ADD_L ;
		  if ( operation.equalsIgnoreCase("ADDC"))
			  kind = OperationKind.ADD_C ;
		  if ( operation.equalsIgnoreCase("ADDR"))
			  kind = OperationKind.ADD_R ;
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
}	
