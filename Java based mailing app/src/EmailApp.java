
public class EmailApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Email first = new Email("Computer", "Crafter");
		first.changeEmailAddress("CC@gmail.com");
		first.changePassword("1231241gdsgagjagk");
		first.setMailboxCapacity(1500);
		System.out.println(first.toString());
	}

}
