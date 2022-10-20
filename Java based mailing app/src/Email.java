import java.util.Random;
import java.util.Scanner;

public class Email {

	private String firstName;
	private String lastName;
	private int mailboxCapacity = 1000;
	private String email;
	private String password;
	private int defaultPasswordLength = 8;
	private String department;
	private String alternateEmail;
	private String companySuff = "comcraf.com";
	
	//Constructor for first+last name
	
	public Email(String firstName, String lastName) {
		this.firstName = firstName;
		this.lastName = lastName;
		
		//Get department
		
		this.department = getDepartment();
		
		//Generate random pswd
		
		this.password = randomPassword(defaultPasswordLength);
		System.out.println("Your password is "+this.password);
		
		//Generate email address
		
		this.email = this.firstName.toLowerCase()+"."+this.lastName.toLowerCase()+"@"+this.department+this.companySuff;
		
	}
	
	//Ask for department
	
	private String getDepartment() {
		System.out.println("Welcome, "+this.firstName+"\nEnter a department code for your department: \n0 for General\n1 for Sales\n2 for Development\n3 for Accounting\n");
		@SuppressWarnings("resource")
		Scanner dec = new Scanner(System.in);
		int choice = dec.nextInt();
		if (choice==1) {
			return "sales.";
		} else if (choice==2) {
			return "development.";
		} else if (choice==3) {
			return "accounting.";
		} else if (choice==0) {
			return "general.";
		} else {
			return "";
		}
	}
	
	//Generate random pswd
	
	private String randomPassword(int length) {
		Random random = new Random();
		String field = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()";
		String pswd = "";
		for (int i=0; i<length; i++) {
			int randomInteger = random.nextInt(field.length());
			pswd = pswd + field.charAt(randomInteger);
		}
		return pswd;
	}
	
	//Set mailbox capacity
	
	public void setMailboxCapacity(int capacity) {
		this.mailboxCapacity = capacity;
		System.out.println("Changed mailbox capacity to "+this.mailboxCapacity+"mb.");
	}
	
	//Set alternate email
	
	public void changeEmailAddress(String alt) {
		this.alternateEmail = alt;
		System.out.println("Added alternate email: "+this.alternateEmail);
	}
	
	//Change pswd
	
	public void changePassword(String pswd) {
		this.password = pswd;
		System.out.println("Password successfully changed to " + this.password);
	}
	
	public int getMailboxCapacity() {
		return this.mailboxCapacity;
	}
	
	public String getAlternateEmail() {
		return this.alternateEmail;
	}
	
	public String getPassword() {
		return this.password;
	}
	
	public String toString() {
		return ("----------\nNAME: "+this.firstName+" "+this.lastName+"\nDEPARTMENT: "+this.department+"\nCOMPANY EMAIL: "+this.email+"\nMAILBOX CAPACITY: "+this.mailboxCapacity+"mb \nALTERNATE EMAIL: "+this.alternateEmail+"\n----------");
	}
}
