package com.example.chatservlet.Logi;

import dto.User;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "RoomServlet", value = "/RoomServlet")
public class RoomServlet extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session=request.getSession(false);
        if (session!=null){
            User user = (User) session.getAttribute("user");
            user.setRoom_no(request.getParameter("room_no"));
            session.setAttribute("user",user);
            response.sendRedirect("chat.jsp");
        }
    }
}
