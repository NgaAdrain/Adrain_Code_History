import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

//Software Engineering Assignment #8 Code Refactoring
// �й� : 201524582
// �̸� : ����
// Refactoring�� �κп� ���� ������ �ּ� ó��.

public class ScoreReportMain {
	private static Scanner scanner = new Scanner(System.in) ;
	private List<Student> students = new ArrayList<>();

	public static void main(String[] args) {
		ScoreReportMain ui = new ScoreReportMain() ;

		boolean quit = false ;
		while ( ! quit ) {
			ui.showCommand() ;//���ο��� command ����� �����ִ� ������ ���� �� �ʿ䰡 �����Ƿ� modulize
			int command = ui.commandInput();//���ο��� command�� �Է� �޴� ������ ���� �� �ʿ䰡 �����Ƿ� modulize
			switch ( command ) {
			case 0: quit = true ; break ;
			case 1: ui.listStudents() ; break ;
			case 2: ui.addStudent() ; break ;//�Ű������� �����ϴ� �� ���� ���� modulize�ؼ� ������ �����ϰ� ��
			case 3: ui.addScore() ; break ;//�Ű������� �����ϴ� �� ���� ���� modulize�ؼ� ������ �����ϰ� ��
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
		String n1 = nameInput();//��� �ؼ� �̸� �Է��� �ް� �����Ƿ� modulize
		for ( Student st : students ) {
			final boolean isSameName = st.getName().equals(n1);
			final boolean isUnderFive = (st.getScores().size() < 5);
			if (isSameName) {
				if (isUnderFive) { // selection sort
					int i;
					int n = st.getScores().size();
					for (i = 0; i < n - 1; i++) {
						selectionSort(st, i, n);//Selection Sort�� ������ �����ϴ� module
					}
				}
				else { // bubble sort
					int n = st.getScores().size();
					for(int i=0; i < n; i++){
						for(int j=1; j < (n-i); j++){
							bubbleSort(st, j);//Bubble Sort�� ������ �����ϴ� module
						}
					}
				}
				int s = 0 ;
				scorePrint(st, s);//�л��� ������ ����ϴ� ���� sortStudentScore method�� ������ �ƴϹǷ� modulize
			}
		}
	}
	//
	private void scorePrint(Student st, int s) {//�л��� ������ ����ϴ� method
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
		String n1 = nameInput();//��� �ؼ� �̸� �Է��� �ް� �����Ƿ� modulize
		for ( Student st : students ) {
			final boolean isSameName = st.getName().equals(n1);//�˱⽱�� boolean type���� ����
			if (isSameName) {//
				st.getScores().clear();
				System.out.println("Score cleared");
			}
		}
	}
	//
	private void removeStudent() {//student ������ �� method
		String n1 = nameInput();//��� �ؼ� �̸� �Է��� �ް� �����Ƿ� modulize
		for ( Student st : students ) {
			final boolean isSameName = st.getName().equals(n1); //�˱⽱�� boolean type���� ����
			final boolean isExistSco = (st.getScores().size() > 0); //�˱⽱�� boolean type���� ����
			if (isSameName) {
				if (isExistSco) {
					System.out.println("The student has scores. Really want to remove the student?");
					final boolean isWant2Del = scanner.next().toUpperCase().equals("Y"); //�˱⽱�� boolean type���� ����
					if (isWant2Del) {
						deleteStd(st);//���� ������ modulize
					}
				}
				else {
					deleteStd(st);//���� ������ modulize
				}
				break ;
			}
		}
	}
	//
	private void deleteStd(Student st) {//�л� ���� ���� method
		st.getScores().clear();
		students.remove(st) ;
	}
	//
	private String nameInput() {//�̸� �Է� method
		System.out.println("Enter student name: ");
		String n1 = scanner.next() ;
		return n1;
	}
	//
	private void showStudentReport() {
		String n1 = nameInput();//��� �ؼ� �̸� �Է��� �ް� �����Ƿ� modulize
		for ( Student st : students ) {
			final boolean isSameName = st.getName().equals(n1);
			if (isSameName) {
				int s = 0 ;
				scorePrint(st, s);//�� �л��� ������ ����ϹǷ� modulize
			}
		}
	}
	//
	private void addStudent() {//�л��� �̸��� �޾� �л� object�� ����� method
			String n = nameInput();
			Student s = new Student(n) ;
			students.add(s) ;
	}
	//
	private void addScore() {//�л��� �̸��� �޾� �л� object�� ������ �Է��ϴ� method
		String n1 = nameInput();//��� �ؼ� �̸� �Է��� �ް� �����Ƿ� modulize
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
	private void listStudents() {//�л� list�� ����ϴ� method
		System.out.println("List of students");
		System.out.println("\tStudent Count: " + students.size());

		for ( Student student: students ) {
			studentPrint(student);//�� �л�(�� �л�)�� ������ ����ϹǷ� Modulize
		}
		System.out.println("End of list");

	}
	//
	private void studentPrint(Student student) {//�� �л� ������ ����ϴ� method
		System.out.println("\t\tName: " + student.getName() +
				"\tScore Count: " + student.getScores().size()) ;
		System.out.print("\t\tScore:");
		for ( Integer score: student.getScores() ) {
			System.out.print( " " + score) ;
		}
		System.out.println();
	}
	//
	private void showCommand() { //Command�� ����� �����ִ� method 
		System.out.println("\nSelect a command !");
		System.out.println("\t 0. Quit");
		System.out.println("\t 1. List students");
		System.out.println("\t 2. Add student");
		System.out.println("\t 3. Add scores");
		System.out.println("\t 4. Show student report");
		System.out.println("\t 5. Remove student");
		System.out.println("\t 6. Clear student scores");
		System.out.println("\t 7. Sort student scores");
		//�ܼ��� Command�� ��ϸ��� �����ֱ� ������ Ŀ�ǵ� �Էºκ��� �и��ؼ� modulize
	}
	//
	private int commandInput() { //command �Է¹޴� method
		int command = scanner.nextInt() ;
		return command ;
	}
	//
}