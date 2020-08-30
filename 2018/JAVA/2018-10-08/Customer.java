package Lab_3;

public class Customer { //Master class
	public Customer(String name) {
		userName = name;
		point = 0;
		totalcharge = 0;
	}
	public void addRental(Rental rentalInfo) {
		totalrental[index++] = rentalInfo;
		point++;
		totalcharge += rentalInfo.Outputcharge();
	}
	public String getReport() {
		String output;
		output = "Charge for " + userName + "\n";
		for(int index = 0 ; index < point; index++)
			output += totalrental[index].returnRentalInfo();
		output += "Total Charge: " + totalcharge+"\n";
		output += "You Earned "+ point + " points";
		return output;
	}
	private final int RENTAL_LIMIT = 3;
	private String userName;
	private int index=0;
	private Rental[] totalrental = new Rental[RENTAL_LIMIT];
	private int point;
	private float totalcharge;
}
