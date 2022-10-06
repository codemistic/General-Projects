package com.example.chatservlet.Chat;

import dto.Message;
import dto.User;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import java.util.List;

@WebServlet(name = "ChattingServlet", value = "/ChattingServlet")
public class ChattingServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out=response.getWriter();
        Display display = new Display();
        String room_no = request.getParameter("room_no");
        List<Message> messages = null;
        messages = display.show(room_no);

        for (Message message: messages){
            out.print("[ "+message.getDate()+" ] "+ message.getUsername());
            out.print("<br>"+message);
        }
        request.getRequestDispatcher("chat.jsp").include(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session=request.getSession(false);
        if (session!=null){
            User user = (User) session.getAttribute("user");

       Display display = new Display();
       String room_no = user.getRoom_no();
        String username = user.getUsername();
        Date d = new Date();
        String date = d.toString();
        String message = request.getParameter("message");

        display.insert(room_no,username,date,message);

        }
        response.sendRedirect("chat.jsp");
    }

}
