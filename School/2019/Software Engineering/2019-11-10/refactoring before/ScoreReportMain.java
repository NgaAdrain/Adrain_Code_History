import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ScoreReportMain {
	private static Scanner scanner = new Scanner(System.in) ;
	private List<Student> students = new ArrayList<>();

	public static void main(String[] args) {
		ScoreReportMain ui = new ScoreReportMain() ;

		boolean quit = false ;
		while ( ! quit ) {
			int command = ui.showCommand() ;
			switch ( command ) {
			case 0: quit = true ; break ;
			case 1: ui.listStudents() ; break ;
			case 2: ui.add("student") ; break ;
			case 3: ui.add("scores") ; break ;
			case 4: ui.showStudentReport() ; break ;
			case 5: ui.removeStudent() ; break ;
			case 6: ui.clearStudentScores() ; break ;
			case 7: ui.sortStudentScores() ; break ;
			case -1: ui.init() ; break ;
			default: break ;
			}
		}
		System.out.println("Bye");
	}
	private void sortStudentScores() {
		System.out.println("Enter student name: ");
		String n1 = scanner.next() ;
		for ( Student st : students ) {
			if ( st.getName().equals(n1)) {
				if ( st.getScores().size() < 5 ) { // selection sort
					int i, j, minIndex, tmp;
					int n = st.getScores().size();
					for (i = 0; i < n - 1; i++) {
						minIndex = i;
						for (j = i + 1; j < n; j++)
							if (st.getScores().get(j) < st.getScores().get(minIndex))
								minIndex = j;
						if (minIndex != i) {
							tmp = st.getScores().get(i);
							st.getScores().set(i, st.getScores().get(minIndex));
							st.getScores().set(minIndex, tmp);
						}
					}
				}
				else { // bubble sort
					int n = st.getScores().size();
					int temp = 0;
					for(int i=0; i < n; i++){
						for(int j=1; j < (n-i); j++){
							if(st.getScores().get(j-1) > st.getScores().get(j)){
								//swap the elements!
								temp = st.getScores().get(j-1);
								st.getScores().set(j-1, st.getScores().get(j));
								st.getScores().set(j, temp);
							}
						}
					}
				}
				int s = 0 ;
				for ( Integer i: st.getScores()) {
					System.out.print(i + " ");
					s += i ;
				}
				System.out.println("Sum: " + s);
			}
		}
	}
	private void init() {
		Student james = new Student("James") ;
		james.getScores().add(20) ;
		james.getScores().add(10) ;

		Student brown = new Student("Brown") ;
		brown.getScores().add(30) ;
		brown.getScores().add(10) ;
		brown.getScores().add(20) ;
		brown.getScores().add(60) ;
		brown.getScores().add(50) ;

		students.add(james) ;
		students.add(brown) ;
	}
	private void clearStudentScores() {
		System.out.println("Enter student name: ");
		String n1 = scanner.next() ;
		for ( Student st : students ) {
			if ( st.getName().equals(n1)) {
				st.getScores().clear();
				System.out.println("Score cleared");
			}
		}
	}
	private void removeStudent() {
		System.out.println("Enter student name: ");
		String n1 = scanner.next() ;
		for ( Student st : students ) {
			if ( st.getName().equals(n1)) {
				if ( st.getScores().size() > 0 ) {
					System.out.println("The student has scores. Really want to remove the student?");
					if ( scanner.next().equals("Y") ) {
						st.getScores().clear();
					}
				}
				else {
					st.getScores().clear();
				}
				students.remove(st) ;
				break ;
			}
		}
	}
	private void showStudentReport() {
		System.out.println("Enter student name: ");
		String n1 = scanner.next() ;
		for ( Student st : students ) {
			if ( st.getName().equals(n1)) {
				int s = 0 ;
				for ( Integer i: st.getScores()) {
					System.out.print(i + " ");
					s += i ;
				}
				System.out.println("Sum: " + s);
			}
		}
	}
	private void add(String kind) {
		if ( kind.equals("student") ) {
			System.out.println("Enter student name: ");
			String n = scanner.next() ;
			Student s = new Student(n) ;
			students.add(s) ;
		}
		else {
			System.out.println("Enter student name: ");
			String n1 = scanner.next() ;
			for ( Student st : students ) {
				if ( st.getName().equals(n1)) {
					System.out.println("Enter scores( -1 for quit): ") ;
					while ( true ) {
						int n2 = scanner.nextInt() ;
						if ( n2 == -1 ) break ;

						st.getScores().add(n2) ;
					}
				}
			}
		}
	}
	private void listStudents() {
		System.out.println("List of students");
		System.out.println("\tStudent Count: " + students.size());

		for ( Student student: students ) {
			System.out.println("\t\tName: " + student.getName() +
					"\tScore Count: " + student.getScores().size()) ;
			System.out.print("\t\tScore:");
			for ( Integer score: student.getScores() ) {
				System.out.print( " " + score) ;
			}
			System.out.println();
		}
		System.out.println("End of list");

	}
	private int showCommand() {
		System.out.println("\nSelect a command !");
		System.out.println("\t 0. Quit");
		System.out.println("\t 1. List students");
		System.out.println("\t 2. Add student");
		System.out.println("\t 3. Add scores");
		System.out.println("\t 4. Show student report");
		System.out.println("\t 5. Remove student");
		System.out.println("\t 6. Clear student scores");
		System.out.println("\t 7. Sort student scores");
		
		int command = scanner.nextInt() ;
		return command ;
	}
}