package pnu.edu.editor;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import pnu.edu.shape.*;

enum OperationKind {ADD_C, ADD_L,ADD_R, LIST, CLEAR, SORT_A, SORT_D, QUIT, INVALID} ;
enum SortKindOperator {ASCENDING, DESCENDING} ;
public class Editor {
	 private static Scanner scanner = new Scanner(System.in);
	 private static List<AreaComputable> comparableList = new ArrayList<AreaComputable>() ;
	 private static List<AreaComputable> newList = new ArrayList<AreaComputable>() ;
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
			  		  final Line newLine = EditorTest.createLine() ;
			  		  comparableList.add(newLine) ;
			  		  System.out.println(newLine) ;
			  		  break ;
			  	  }
			  	  case ADD_C : {
			  		  final Circle newCircle = EditorTest.createCircle() ;
			  		  comparableList.add(newCircle) ;
			  		  System.out.println(newCircle) ;
			  		  break ;
			  	  }
			  	  case ADD_R : {
			  		  final Rectangle newRectangle =  EditorTest.createRectangle();
			  		  comparableList.add(newRectangle) ;
			  		  System.out.println(newRectangle) ;
			  		  break ;
			  	  }
			  	  case SORT_A:
			  		  newList = new ArrayList<AreaComputable>() ;
			  		  newList.addAll(SortKind.sortList(comparableList, SortKindOperator.ASCENDING)) ;
			  		  comparableList = newList;
			  		  break ;
			  	  case SORT_D: 
			  		  newList = new ArrayList<AreaComputable>() ;
			  		  newList.addAll(SortKind.sortList(comparableList, SortKindOperator.DESCENDING)) ;
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
