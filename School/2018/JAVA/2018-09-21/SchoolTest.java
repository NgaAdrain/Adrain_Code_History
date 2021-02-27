package lab_2_class;
import java.util.Scanner;

enum OperationKind { ADD, LIST, CLEAR, FIND, QUIT, INVALID};
	
public class SchoolTest {
	private static Scanner scanner = new Scanner(System.in);
	
	public static void main(String[] args) {
		final School pnu = new School("PNU",100);
		System.out.println("This Program is Controlling School Student Program");
		System.out.println("Operation List is [ADD,LIST,CLEAR,FIND,QUIT,INVALID]");
		System.out.println("and Operation's UpperCase or LowerCase can be ignored");
		while (true) {
			final OperationKind op = getOperation();
			if ( op == OperationKind.QUIT) {
				System.out.println("Bye");
				break;
			}
			if ( op == OperationKind.INVALID) {
				System.out.println("Invalid Operation!");
				continue;
			}
			switch (op) {
			case ADD :{
				System.out.println("We are recommand input fomation [Name Year]");
				Student newStudent = createStudent();
				pnu.addStudent(newStudent);
				break;
			}
			case FIND :
				System.out.println("We are recommand input fomation [Name Year]");
				findStudent(pnu);
				break;
			case CLEAR : 
				pnu.removeAllStudent();
				break;
			case LIST: System.out.println(pnu);
				break;
			}
		}
	}
	private static OperationKind getOperation() {
		System.out.print("Enter Operation String! : ");
		final String operation = scanner.next();
		OperationKind kind = OperationKind.INVALID;
		if( operation.equalsIgnoreCase("ADD"))
			kind = OperationKind.ADD;
		else if (operation.equalsIgnoreCase("LIST"))
			kind = OperationKind.LIST;
		else if (operation.equalsIgnoreCase("FIND"))
			kind = OperationKind.FIND;
		else if (operation.equalsIgnoreCase("CLEAR"))
			kind = OperationKind.CLEAR;
		else if (operation.equalsIgnoreCase("QUIT"))
			kind = OperationKind.QUIT;
		return kind;
	}
	private static void findStudent(final School school) {
		final String studentName = scanner.next();
		final int schoolYear = scanner.nextInt();
		Student foundStudent =  school.findStudent(studentName,schoolYear);
		if ( foundStudent != null) 
			System.out.println(foundStudent);
		else
			System.out.println("Student Not found with name " + studentName + " and year "+ schoolYear);	
	}
	private static Student createStudent() {
		final String studentName = scanner.next();
		final int schoolYear = scanner.nextInt();
		return new Student(studentName, schoolYear);
	}
	
}

