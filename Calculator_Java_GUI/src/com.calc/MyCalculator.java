package mypack4;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class MyCalculator implements ActionListener
{
    JFrame f;
    JLabel l1,l2,l3;
    JTextField t1,t2,t3;
    JButton b1,b2,b3,b4,b5;
    public void actionPerformed(ActionEvent e)
    {
        if(e.getSource()==b1)
        {
            int a=Integer.parseInt(t1.getText());
            int b=Integer.parseInt(t2.getText());
            int c=a+b;
            t3.setText(Integer.toString(c));
        }
        else if(e.getSource()==b2)
        {
            int a=Integer.parseInt(t1.getText());
            int b=Integer.parseInt(t2.getText());
            int c=a-b;
            t3.setText(Integer.toString(c));
        }
        else if(e.getSource()==b3)
        {
            int a=Integer.parseInt(t1.getText());
            int b=Integer.parseInt(t2.getText());
            int c=a*b;
            t3.setText(Integer.toString(c));
        }
        else if(e.getSource()==b4)
        {
            int a=Integer.parseInt(t1.getText());
            int b=Integer.parseInt(t2.getText());
            int c=a/b;
            t3.setText(Integer.toString(c));
        }
        else if(e.getSource()==b5)
        {
            int a=Integer.parseInt(t1.getText());
            int b=Integer.parseInt(t2.getText());
            int c=a%b;
            t3.setText(Integer.toString(c));
        }
    }
    MyCalculator()
    {      //f.setBackground(Color.green);
        f=new JFrame("Calculator Application");
        l1=new JLabel("Input 1:");
        l2=new JLabel("Input 2:");
        l3=new JLabel("Output :");
        t1=new JTextField(10);
        t2=new JTextField(10);
        t3=new JTextField(10);
        b1=new JButton("ADD");
        b2=new JButton("SUB");
        b3=new JButton("MUL");
        b4=new JButton("DIV");
        b5=new JButton("%");
        f.add(l1);
        f.add(t1);
        f.add(l2);
        f.add(t2);
        f.add(l3);
        f.add(t3);
        f.add(b1);
        f.add(b2);
        f.add(b3);
        f.add(b4);
        f.add(b5);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        f.setSize(400,400);
        f.setLayout(new FlowLayout());
        f.setVisible(true);
        f.pack();

    }

    public static void main(String[] args)
    {
        new MyCalculator();

    }

}