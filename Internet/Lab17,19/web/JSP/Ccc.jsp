<%@ page import="task6.CBean" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>task6.Ccc</title>
</head>
<body>

<%
    CBean cBean = (CBean)pageContext.getServletContext().getAttribute("atrCbean");
    if (cBean != null) {
%>
<p>Type: <%= "Context"%></p>
<p>Value1: <%= cBean.getValue1()%></p>
<p>Value2: <%= cBean.getValue2()%></p>
<p>Value3: <%= cBean.getValue3()%></p>
<%
    }
%>



<!--lab16-->
<%

    CBean cBeanRequest = (CBean)request.getAttribute("atrCbeanRequest");
    String oldReq = (String)pageContext.getServletContext().getAttribute("oldReq");
    String newReq = (String)pageContext.getServletContext().getAttribute("newReq");
    if (oldReq != null || newReq != null) {
%>
<p>Type: <%= "Request"%></p>
<p>Value1: <%= cBeanRequest != null ? cBeanRequest.getValue1() : "null"%></p>
<p>Value2: <%= cBeanRequest != null ? cBeanRequest.getValue2() : "null"%></p>
<p>Value3: <%= cBeanRequest != null ? cBeanRequest.getValue3() : "null"%></p>
<%
    }

    CBean cBeanSession = (CBean)session.getAttribute(session.getId());
    if (oldReq != null || newReq != null) {
%>
<p>Type: <%= "Session"%></p>
<p>Value1: <%= cBeanSession != null ? cBeanSession.getValue1() : "null"%></p>
<p>Value2: <%= cBeanSession != null ? cBeanSession.getValue2() : "null"%></p>
<p>Value3: <%= cBeanSession != null ? cBeanSession.getValue3() : "null"%></p>
<p>Session: <%= request.getSession().getId()%></p>
<%
    }
%>


</body>
</html>
