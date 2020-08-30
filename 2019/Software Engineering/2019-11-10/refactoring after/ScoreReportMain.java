import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

//Software Engineering Assignment #8 Code Refactoring
// 학번 : 201524582
// 이름 : 정희석
// Refactoring한 부분에 대한 설명은 주석 처리.

public class ScoreReportMain {
	private static Scanner scanner = new Scanner(System.in) ;
	private List<Student> students = new ArrayList<>();

	public static void main(String[] args) {
		ScoreReportMain ui = new ScoreReportMain() ;

		boolean quit = false ;
		while ( ! quit ) {
			ui.showCommand() ;//메인에서 command 목록을 보여주는 동작을 직접 할 필요가 없으므로 modulize
			int command = ui.commandInput();//메인에서 command를 입력 받는 동작을 직접 할 필요가 없으므로 modulize
			switch ( command ) {
			case 0: quit = true ; break ;
			case 1: ui.listStudents() ; break ;
			case 2: ui.addStudent() ; break ;//매개변수로 구분하는 것 보다 각각 modulize해서 동작을 수행하게 함
			case 3: ui.addScore() ; break ;//매개변수로 구분하는 것 보다 각각 modulize해서 동작을 수행하게 함
			case 4: ui.showStudentReport() ; break ;
			case 5: ui.removeStudent() ; break ;
			case 6: ui.clearStudentScores() ; break ;
			case 7: ui.sortStudentScores() ; break ;
			case -1: ui.init() ; break ;//for test
			default: System.out.println("Wrong Input!");break ;
			}
		}
		System.out.println("Bye");
	}
	
	private void sortStudentScores() {
		String n1 = nameInput();//계속 해서 이름 입력을 받고 있으므로 modulize
		for ( Student st : students ) {
			final boolean isSameName = st.getName().equals(n1);
			final boolean isUnderFive = (st.getScores().size() < 5);
			if (isSameName) {
				if (isUnderFive) { // selection sort
					int i;
					int n = st.getScores().size();
					for (i = 0; i < n - 1; i++) {
						selectionSort(st, i, n);//Selection Sort를 실제로 수행하는 module
					}
				}
				else { // bubble sort
					int n = st.getScores().size();
					for(int i=0; i < n; i++){
						for(int j=1; j < (n-i); j++){
							bubbleSort(st, j);//Bubble Sort를 실제로 수행하는 module
						}
					}
				}
				int s = 0 ;
				scorePrint(st, s);//학생의 점수를 출력하는 것은 sortStudentScore method의 역할이 아니므로 modulize
			}
		}
	}
	//
	private void scorePrint(Student st, int s) {//학생의 점수를 출력하는 method
		for ( Integer i: st.getScores()) {
			System.out.print(i + " ");
			s += i ;
		}
		System.out.println("Sum: " + s);
	}
	//
	private void bubbleSort(Student st, int j) {// Bubble Sort Algorithm
		int temp;
		if(st.getScores().get(j-1) > st.getScores().get(j)){
			//swap the elements!
			temp = st.getScores().get(j-1);
			st.getScores().set(j-1, st.getScores().get(j));
			st.getScores().set(j, temp);
		}
	}
	//
	private void selectionSort(Student st, int i, int n) {//Selection Sort Algorithm 
		int j;
		int minIndex;
		int tmp;
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
	// For Test
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
	//
	private void clearStudentScores() {
		String n1 = nameInput();//계속 해서 이름 입력을 받고 있으므로 modulize
		for ( Student st : students ) {
			final boolean isSameName = st.getName().equals(n1);//알기쉽게 boolean type으로 만듬
			if (isSameName) {//
				st.getScores().clear();
				System.out.println("Score cleared");
			}
		}
	}
	//
	private void removeStudent() {//student 삭제의 논리 method
		String n1 = nameInput();//계속 해서 이름 입력을 받고 있으므로 modulize
		for ( Student st : students ) {
			final boolean isSameName = st.getName().equals(n1); //알기쉽게 boolean type으로 만듬
			final boolean isExistSco = (st.getScores().size() > 0); //알기쉽게 boolean type으로 만듬
			if (isSameName) {
				if (isExistSco) {
					System.out.println("The student has scores. Really want to remove the student?");
					final boolean isWant2Del = scanner.next().toUpperCase().equals("Y"); //알기쉽게 boolean type으로 만듬
					if (isWant2Del) {
						deleteStd(st);//실제 동작을 modulize
					}
				}
				else {
					deleteStd(st);//실제 동작을 modulize
				}
				break ;
			}
		}
	}
	//
	private void deleteStd(Student st) {//학생 정보 삭제 method
		st.getScores().clear();
		students.remove(st) ;
	}
	//
	private String nameInput() {//이름 입력 method
		System.out.println("Enter student name: ");
		String n1 = scanner.next() ;
		return n1;
	}
	//
	private void showStudentReport() {
		String n1 = nameInput();//계속 해서 이름 입력을 받고 있으므로 modulize
		for ( Student st : students ) {
			final boolean isSameName = st.getName().equals(n1);
			if (isSameName) {
				int s = 0 ;
				scorePrint(st, s);//각 학생의 점수를 출력하므로 modulize
			}
		}
	}
	//
	private void addStudent() {//학생의 이름을 받아 학생 object를 만드는 method
			String n = nameInput();
			Student s = new Student(n) ;
			students.add(s) ;
	}
	//
	private void addScore() {//학생의 이름을 받아 학생 object의 점수를 입력하는 method
		String n1 = nameInput();//계속 해서 이름 입력을 받고 있으므로 modulize
		for ( Student st : students ) {
			final boolean isSameName = st.getName().equals(n1);
			if (isSameName) {
				System.out.println("Enter scores( -1 for quit): ") ;
				while ( true ) {
					int n2 = scanner.nextInt() ;
					if ( n2 == -1 ) break ;
					st.getScores().add(n2) ;
				}
			}
		}
	}
	//
	private void listStudents() {//학생 list를 출력하는 method
		System.out.println("List of students");
		System.out.println("\tStudent Count: " + students.size());

		for ( Student student: students ) {
			studentPrint(student);//각 학생(한 학생)의 정보를 출력하므로 Modulize
		}
		System.out.println("End of list");

	}
	//
	private void studentPrint(Student student) {//한 학생 정보를 출력하는 method
		System.out.println("\t\tName: " + student.getName() +
				"\tScore Count: " + student.getScores().size()) ;
		System.out.print("\t\tScore:");
		for ( Integer score: student.getScores() ) {
			System.out.print( " " + score) ;
		}
		System.out.println();
	}
	//
	private void showCommand() { //Command의 목록을 보여주는 method 
		System.out.println("\nSelect a command !");
		System.out.println("\t 0. Quit");
		System.out.println("\t 1. List students");
		System.out.println("\t 2. Add student");
		System.out.println("\t 3. Add scores");
		System.out.println("\t 4. Show student report");
		System.out.println("\t 5. Remove student");
		System.out.println("\t 6. Clear student scores");
		System.out.println("\t 7. Sort student scores");
		//단순히 Command의 목록만을 보여주기 때문에 커맨드 입력부분은 분리해서 modulize
	}
	//
	private int commandInput() { //command 입력받는 method
		int command = scanner.nextInt() ;
		return command ;
	}
	//
}