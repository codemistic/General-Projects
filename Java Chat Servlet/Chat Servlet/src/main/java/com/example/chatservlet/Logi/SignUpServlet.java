package com.example.chatservlet.Logi;

import dto.User;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

@WebServlet(name = "SignUpServlet", value = "/SignUpServlet")
public class SignUpServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        User user = new User(username,password);
        if(add(user)){
            response.sendRedirect("successSignup.jsp");
        }else {
            response.sendRedirect("errorSignUp.jsp");
        }

    }

    private boolean add(User user){
        boolean status = false;
        try{
            Class.forName("com.mysql.jdbc.Driver");
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "123456");
            PreparedStatement ps = connection.prepareStatement("INSERT INTO users (username, password) VALUES (?,?)");
            ps.setString(1,user.getUsername());
            ps.setString(2,user.getPassword());

            if (ps.executeUpdate()>0){
                status = true;
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return status;
    }
}
