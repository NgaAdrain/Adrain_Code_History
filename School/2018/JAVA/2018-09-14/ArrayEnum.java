package FirstLab; 
//������ǻ�Ͱ��к� ������ǻ�Ͱ������� 201524582 ���� Lab_1 ArrayEnum�ǽ�

import java.util.Scanner; //�迭�� �����Ҵ� ���� �ذ��ϸ� ��!
enum ArrOp {ADD,SUM,LIST,QUIT};
public class ArrayEnum {
	public static void main(String[] args) {
		int index = 0;
		Scanner scan = new Scanner(System.in);
		ArrOp op = ArrOp.LIST;
		System.out.println("�� ���α׷��� ������ �޾� �����ϴ� ���α׷��Դϴ�.");
		System.out.println("��ɾ��  ADD : ���� �߰�, LIST : �Է��� ������ ���");
		System.out.println("SUM : �Է��Ѽ��� ����, QUIT : ������ �Դϴ�.");
		System.out.println("�Է� ���ô� ADD 10 ������ �Է��Ͻñ� �ٶ��ϴ�.");
		int[] input_List = new int[10];
		do {
			
			final String oper = scan.next(); //�ٷ� assign
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
		for(int v : input) { //for���� array�� ���� �ִ� ���	
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
		for(int x : input) { //for���� array�� ���� �ִ� ���	
			result += input[index];
			index++;
		}
		return result;
	}
}
