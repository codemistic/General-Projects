package com.example.chatservlet.Logi;

import dto.User;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

@WebServlet(name = "LoginServlet", value = "/LoginServlet")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doGet(req, resp);
    }

    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        User user =new User();
        HttpSession session=request.getSession();
        user.setUsername(request.getParameter("username"));
        user.setPassword(request.getParameter("password"));
        session.setAttribute("user",user);
        if (auth(user)){
            response.sendRedirect("room.html");
        }else {
            response.sendRedirect("errlogin.jsp");
        }
    }

    private boolean auth(User user){
        boolean status = false;
        try{
            Class.forName("com.mysql.jdbc.Driver");
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "123456");
            PreparedStatement ps = connection.prepareStatement("SELECT * FROM users WHERE username = ?");
            ps.setString(1,user.getUsername());
            ResultSet rs = ps.executeQuery();
            while (rs.next()){
                if (user.getPassword().equalsIgnoreCase(rs.getString("password"))){
                    status = true;break;
                }
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return status;
    }


}
