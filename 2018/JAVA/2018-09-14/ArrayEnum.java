package FirstLab; 
//전기컴퓨터공학부 정보컴퓨터공학전공 201524582 정희석 Lab_1 ArrayEnum실습

import java.util.Scanner; //배열의 동적할당 문제 해결하면 끝!
enum ArrOp {ADD,SUM,LIST,QUIT};
public class ArrayEnum {
	public static void main(String[] args) {
		int index = 0;
		Scanner scan = new Scanner(System.in);
		ArrOp op = ArrOp.LIST;
		System.out.println("본 프로그램은 정수를 받아 덧셈하는 프로그램입니다.");
		System.out.println("명령어는  ADD : 수를 추가, LIST : 입력한 수들의 목록");
		System.out.println("SUM : 입력한수를 더함, QUIT : 나가기 입니다.");
		System.out.println("입력 예시는 ADD 10 과같이 입력하시길 바랍니다.");
		int[] input_List = new int[10];
		do {
			
			final String oper = scan.next(); //바로 assign
			if(ArrOp.ADD == ArrOp.valueOf(oper))
				op = ArrOp.ADD;
			else if(ArrOp.SUM == ArrOp.valueOf(oper))
				op = ArrOp.SUM;
			else if(ArrOp.LIST == ArrOp.valueOf(oper))
				op = ArrOp.LIST;
			else
				op = ArrOp.QUIT;
			switch (op) {
				case ADD :
					final int inp = scan.nextInt();
					input_List[index] = inp;
					index++;
					break;
				case LIST : 
					printList(input_List);
					break;
				case SUM : 
					System.out.println(getSum(input_List));
					break;
				default : 
					break;
			}
		} while(op != ArrOp.QUIT);
		scan.close();
	}
	private static void printList(int[] input) {
		/*for(int count = 0; count < input.length ; count++){
			System.out.print(input[count] + " ");
			count++;
			}
		*/
		int count = 0;
		for(int v : input) { //for문에 array를 직접 넣는 방식	
			System.out.print(input[count] + " ");
			count++;
		}
		System.out.println();
	}
	private static int getSum(int[] input){
		int result = 0;
		int index = 0;
		/*for(int index = 0; index< input.length ; index++){
			result += input[index];
			index++;
		}
		*/
		for(int x : input) { //for문에 array를 직접 넣는 방식	
			result += input[index];
			index++;
		}
		return result;
	}
}
