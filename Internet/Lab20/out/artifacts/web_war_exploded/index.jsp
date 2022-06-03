<%-- Created by IntelliJ IDEA. --%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title></title>
  </head>
  <body>
    <a href="db">Get all users</a>

    <form method="get" action="db">
      <label>User Id: <input type="text" name="user_id"/></label>
      <button type="submit" name="type" value="dynamic">Get current user</button>
    </form>

    <form method="post" action="db">
      <label>Id: <input type="text" name="id"/></label>
      <button type="submit">get user</button>
    </form>
  </body>
</html>