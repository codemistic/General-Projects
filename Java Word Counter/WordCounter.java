import java.awt.*;  
import javax.swing.*;  
import java.awt.event.*;  
public class WordCounter extends JFrame implements ActionListener{  
    JLabel label1,label2;  
    JTextArea text_area;  
    JButton button1;  
    JButton txtarea,text;  
    WordCounter(){  
        super("Word Counter");  
        label1=new JLabel("Characters: ");  
        label1.setBounds(50,50,100,20);  
        label2=new JLabel("Words: ");  
        label2.setBounds(50,80,100,20);  
          
        text_area=new JTextArea();  
        text_area.setBounds(50,110,300,200);  
          
        button1=new JButton("Count");  
        button1.setBounds(50,320, 80,30);//x,y,w,h  
        button1.addActionListener(this);  
      
        txtarea=new JButton("Color");  
        txtarea.setBounds(140,320, 110,30);//x,y,w,h  
        txtarea.addActionListener(this);  
  
        text=new JButton("Text Color");  
        text.setBounds(260,320, 110,30);//x,y,w,h  
        text.addActionListener(this);  
  
        add(label1);add(label2);add(text_area);add(button1);add(txtarea);add(text);  
          
        setSize(400,400);  
        setLayout(null);//using no layout manager  
        setVisible(true);  
        setDefaultCloseOperation(EXIT_ON_CLOSE);  
    }  
    public void actionPerformed(ActionEvent e){  
        if(e.getSource()==button1){  
        String para=text_area.getText();  
        label1.setText("Characters: "+para.length());  
        String words[]=para.split("\\s");  
        label2.setText("Words: "+words.length);  
        }else if(e.getSource()==txtarea){  
            Color c=JColorChooser.showDialog(this,"Choose Color",Color.BLACK);  
            text_area.setBackground(c);  
        }else if(e.getSource()==text){  
            Color c=JColorChooser.showDialog(this,"Choose Color",Color.BLACK);  
            text_area.setForeground(c);  
        }  
    }  
    public static void main(String[] args) {  
    	new WordCounter();
    	}
    }