package lab_2_class;
public class Student {
	private String name;
	private int year;
	public Student(String inputName, int inputYear) {
		name = inputName;
		year = inputYear;
	}
	public String toString(){
		String msg = "["+ name +", "+ year +"ÇĞ³â]";
		return msg;
	}
	public boolean compareStudent(Student input) {
		boolean result;
		if((input.name.equals(name) ) && (input.year == year)) {
			result = true;
		}
		else
			result = false;
		return result;
	}
}
