<%@ page import="com.example.chatservlet.Chat.Display" %>
<%@ page import="dto.User" %>
<%@ page import="dto.Message" %>
<%@ page import="java.util.List" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%--
  Created by IntelliJ IDEA.
  User: utkar
  Date: 05-10-2022
  Time: 20:54
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>Chat App</title>
  <link rel="stylesheet" type="text/css" href="chatstyle.css">
  <link href="https://fonts.googleapis.com/css2?family=Jost:wght@500&display=swap" rel="stylesheet">
</head>
<body>

<%
  HttpSession s=request.getSession(false);
  if (s!=null){
    User user = (User) s.getAttribute("user");
    String room_no = user.getRoom_no();
    Display display = new Display();
    List<Message> messages = display.show(room_no);

    request.setAttribute("info",messages);
  }
%>
<div class="main">
  <c:forEach items="${info}" var="message">
    <p>${message.date}</p>
    <p>${message.username}</p>
    <p>${message.message}</p><hr/>
  </c:forEach>
</div>

<% response.setIntHeader("Refresh",30);%>


<%@include file="ChattingScreen.html" %>


</body>
</html>
