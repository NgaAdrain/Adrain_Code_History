package lab_2_class;

public class School {
	private String name;
	private int limit;
	private Student[] students;
	private int studentCount;
	
	public String toString() {
		String msg = "School Name: " + name + " Student Count: " + studentCount + "\n" ;
		for (int i = 0; i < studentCount ; i++) {
			msg += "\t" + students[i] + "\n";
		}
		return msg;
	}
	public School() {
		System.out.println(toString());
	}
	public School(String schoolName, int countStudent) {
		name = schoolName;
		limit = countStudent;
		students = new Student[limit];
		studentCount = 0;
	}
	public void removeAllStudent() {
		students = new Student[limit];
		studentCount = 0;
	}
	public void addStudent(Student newStudent) {
		students[studentCount] = newStudent;
		studentCount++;
	}
	public Student findStudent(String findStudentName, int findStudentYear) {
		Student result,input;
		input = new Student(findStudentName ,findStudentYear);
		result = null;
			for(int index = 0 ; index < studentCount; index++) {
				if(input.compareStudent(students[index]) == true)
					result = input;
			}
		return result;
	}
}

