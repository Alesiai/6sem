<%--
  Created by IntelliJ IDEA.
  User: krayn
  Date: 4/17/2022
  Time: 5:46 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="jspclass.*" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>$Title$</title>
    <%! String name = null;
      Regimex r = new Regimex();
      Integer n = r.GetHOUR();
      Integer d = r.GetDAY();
      String table = null;

      protected String PrintTable(Integer count){
        Regimex r1 = new Regimex();
        table = "<table>";
        table+="<tr> <td>" + r1.GetDATE() + "</td>";
        table += " <td>" + r1.GetDayOfWeek() + "</td></tr>";

        for(int i = 1;i < count;i++){
          table += "<tr> <td>" + r1.AddDay(1) + "</td>";
          table += " <td>" + r1.GetDayOfWeek() + "</td></tr>";
        }

        table+="</table>";
        return table;
      }
    %>
  </head>
  <body>
    <%=r.Salutation(n)%>

    <%=PrintTable(7)%>
    <br/>

    <form>
      <input type="submit" name = "T5" value="press5"/>
    </form>

    <% if("press5".equals(request.getParameter("T5"))){ %>
      <%if ((n >= 0) && (n <= 6)){%>
        <%@ include file="night.jsp" %>
      <%}else if ((n > 6) && (n <= 12)){%>
        <%@ include file="morning.jsp" %>
      <%}else if ((n > 12) && (n <= 17)){%>
        <%@ include file="afternoon.jsp" %>
      <%}else{%>
        <%@ include file="evening.jsp" %>
      <%}%>
    <%}%>

    <br/>

    <form>
      <input type="submit" name = "T6" value="press6"/>
    </form>

    <% if("press6".equals(request.getParameter("T6"))) { %>
      <%if ((n >= 0) && (n <= 6)){%>
        <jsp:include page="night.jsp" />
      <%}else if ((n > 6) && (n <= 12)){%>
        <jsp:include page="morning.jsp" />
      <%}else if ((n > 12) && (n <= 17)){%>
        <jsp:include page="afternoon.jsp" />
      <%}else{%>
        <jsp:include page="evening.jsp" />
      <%}%>
    <%}%>

    <br/>

    <form>
      <input type="submit" name = "T7" value="press7"/>
    </form>

    <% if("press7".equals(request.getParameter("T7"))) { %>
      <jsp:include page="Afternoon" />
    <%}%>

    <br/>

    <form>
      <input type="submit" name = "T8" value="press8"/>
    </form>

    <% if("press8".equals(request.getParameter("T8"))) { %>
      <%if ((n >= 0) && (n <= 6)){%>
        <jsp:forward page="night.jsp" />
      <%}else if ((n > 6) && (n <= 12)){%>
        <jsp:forward page="morning.jsp" />
      <%}else if ((n > 12) && (n <= 17)){%>
        <jsp:forward page="afternoon.jsp" />
      <%}else{%>
        <jsp:forward page="evening.jsp" />
      <%}%>
    <%}%>

    <br><a href = "Jjj">Go to Jjj</a>

    <br><a href = "Jjj">Go to Jjj 12</a>

    <br/>
    <form action="Jjj" method="post">
      <input type="submit" name="submit" value="Jjj 13">
    </form>
  </body>
</html>
