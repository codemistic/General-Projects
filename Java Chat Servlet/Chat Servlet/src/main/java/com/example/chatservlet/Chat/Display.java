package com.example.chatservlet.Chat;

import dto.Message;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class Display {
    public List<Message> show(String room_no) {
        List<Message> result = new ArrayList<>();
        try{
            Class.forName("com.mysql.jdbc.Driver");
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "123456");
            PreparedStatement ps = connection.prepareStatement("SELECT * FROM chatdata WHERE room_no =? ORDER BY sno DESC");
            ps.setString(1,room_no);
            ResultSet rs = ps.executeQuery();
            while (rs.next()) {
                String username = rs.getString("username");
                String date = rs.getString("date");
                String message = rs.getString("message");
                Message m = new Message(room_no,username,date,message);
                result.add(m);
            }

        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return result;
    }
    public boolean insert(String room_no,String username,String date,String message) {
        boolean status = false;
        try{
            Class.forName("com.mysql.jdbc.Driver");
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "123456");
            PreparedStatement ps = connection.prepareStatement("INSERT INTO chatdata (room_no, username, message, date) VALUES (?,?,?,?)");
            ps.setString(1,room_no);
            ps.setString(2,username);
            ps.setString(3,message);
            ps.setString(4,date);

            if (ps.executeUpdate()>0){
                status = true;
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return status;
    }
}
