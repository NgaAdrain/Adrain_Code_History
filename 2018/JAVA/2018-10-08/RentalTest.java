package Lab_3;  //전기컴퓨터공학부 정보컴퓨터공학전공 201524582 정희석
				//실습 3 Class MovieRental
public class RentalTest {
	public static void main(String[] args) {
	Customer customer1 = new Customer("David");
	Movie movie1 = new Movie("Madagascar", Movie.CHILDREN);
	Rental rental1 = new Rental(movie1, 6); // 6 day rental
	Movie movie2 = new Movie("Star Wars", Movie.NEW_RELEASE);
	Rental rental2 = new Rental(movie2, 2); // 2 day rental
	Movie movie3 = new Movie("Gone with the Wind", Movie.REGULAR);
	Rental rental3 = new Rental(movie3, 8); // 8 day rental
		
	customer1.addRental(rental1);
	customer1.addRental(rental2);
	customer1.addRental(rental3);
	System.out.println(customer1.getReport()) ;
	}
}
