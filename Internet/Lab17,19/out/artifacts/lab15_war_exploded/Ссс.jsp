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
</body>
</html>
