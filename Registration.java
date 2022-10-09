import java.awt.*;

import javax.swing.JComboBox;

import java.awt.event.*;

public class Registration extends Frame implements WindowListener,ActionListener
{

//Globally Declared
TextField t1,t2,t3,t4,t5,t6,t8,t9;
Button b;
Label l1,l2,l3,l4,l5,l6,l7,l8,l9,title;
Frame f;

Registration()
{

f = new Frame("Frame 1");
f.setSize(1650,1080);
f.setBackground(Color.LIGHT_GRAY);

//Title for title
title = new Label("Registration Form");
title.setFont(new Font("Arial", Font.BOLD, 30));
title.setSize(300, 30);
title.setBounds(300, 50, 300,30);
f.add(title);

//Lable for Name
l1=new Label("Name:");
l1.setBounds(250,100,150,30);
l1.setFont(new Font("Roboto", Font.PLAIN, 20));
t1=new TextField();
t1.setBounds(400,100,400,30);
t1.setFont(new Font("Arial", Font.PLAIN, 20));

//Lable for Roll.no
l2=new Label("Roll.no.:");
l2.setBounds(250,140,150,30);
l2.setFont(new Font("Arial", Font.PLAIN, 20));
t2=new TextField();
t2.setBounds(400,140,400,30);
t2.setFont(new Font("Arial", Font.PLAIN, 20));

//Lable for Course
l3=new Label("Course:");
l3.setBounds(250,180,150,30);
l3.setFont(new Font("Arial", Font.PLAIN, 20));
t3=new TextField();
t3.setBounds(400,180,400,30);
t3.setFont(new Font("Arial", Font.PLAIN, 20));

//Lable for Branch
l4=new Label("Branch:");
l4.setBounds(250,220,150,30);
l4.setFont(new Font("Arial", Font.PLAIN, 20));
t4=new TextField();
t4.setBounds(400,220,400,30);
t4.setFont(new Font("Arial", Font.PLAIN, 20));

//Label for Contact
l5=new Label("Contact No.:");
l5.setBounds(250,260,150,30);
l5.setFont(new Font("Arial", Font.PLAIN, 20));
t5=new TextField();
t5.setBounds(400,260,400,30);
t5.setFont(new Font("Arial", Font.PLAIN, 20));

//Label for Email
l6=new Label("Email:");
l6.setBounds(250,300,150,30);
l6.setFont(new Font("Arial", Font.PLAIN, 20));
t6=new TextField();
t6.setBounds(400,300,400,30);
t6.setFont(new Font("Arial", Font.PLAIN, 20));

//Label for City
l7=new Label("City:");
l7.setBounds(250,340,150,30);
l7.setFont(new Font("Arial", Font.PLAIN, 20));
//t7=new TextField();
//t7.setBounds(400,340,400,30);         
String country[]={"Lucknow",
        "Kanpur",
        "Ghaziabad",
        "Agra",
        "Meerut",
        "Varanasi",
        "Prayagraj",
        "Bareilly",
        "Moradabad",
        "Aligarh"};        
JComboBox<String> cb=new JComboBox<String>(country);    
cb.setBounds(400,340,400,30); 
cb.setFont(new Font("Arial", Font.PLAIN, 15));   
f.add(cb);        


//Label for Username
l8=new Label("Username:");
l8.setBounds(250,380,150,30);
l8.setFont(new Font("Arial", Font.PLAIN, 20));
t8=new TextField();
t8.setBounds(400,380,400,30);
t8.setFont(new Font("Arial", Font.PLAIN, 20));

//Label for Password
l9=new Label("Passwoard:");
l9.setBounds(250,420,150,30);
l9.setFont(new Font("Arial", Font.PLAIN, 20));
t9=new TextField();
t9.setEchoChar('*');
t9.setBounds(400,420,400,30);
t9.setFont(new Font("Arial", Font.PLAIN, 20));

//Submit button
b=new Button("Submit:");
b.setBounds(400,480,150,30);
b.setFont(new Font("Arial", Font.BOLD, 20));

f.add(l1);
f.add(t1);
f.add(l2);
f.add(t2);
f.add(l3);
f.add(t3);
f.add(l4);
f.add(t4);
f.add(l5);
f.add(t5);
f.add(l6);
f.add(t6);
f.add(l7);
f.add(l8);
f.add(t8);
f.add(l9);
f.add(t9);
f.add(b);
 

f.setLayout(null);
f.setVisible(true);
f.addWindowListener (this); 
b.addActionListener(this);
}

public void windowClosing(WindowEvent e)
{
f.dispose();
}

public void actionPerformed(ActionEvent e) 
{
create_frame2();	
}
public static void main(String args[])
{
new Registration();
}

@Override
public void windowOpened(WindowEvent e){}
@Override
public void windowClosed(WindowEvent e){}
@Override
public void windowIconified(WindowEvent e){}
@Override
public void windowDeiconified(WindowEvent e) {}
@Override
public void windowActivated(WindowEvent e) {}
@Override
public void windowDeactivated(WindowEvent e) {}



public void create_frame2()	
{
Frame f2 = new Frame("Frame 2");

Label l=new Label("Your Form Has Been Submited Successfully!");
l.setFont(new Font("Ariel", Font.BOLD, 20));
l.setAlignment(Label.CENTER);

f2.setBackground(Color.pink);
f2.setSize(1650,1080);
f2.add(l);
f2.setVisible(true);  


}



}







