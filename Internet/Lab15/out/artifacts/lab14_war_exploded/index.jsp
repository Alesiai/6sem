<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="mylib" uri="tagconf.uri" %>
<html>
<head>
  <title>Ttt</title>
</head>
<body>
<mylib:dossier>
  <div>
    <label> lastname:
      <mylib:lastname value=""/>
    </label>
  </div>
  <div style="margin-top: 10px">
    <label>
      <mylib:surname value=""/>
    </label>
  </div>

  <div style="margin-top: 10px">
    <mylib:sex value="Male"/>
    <label>Male</label>
    <mylib:sex value="Female"/>
    <label>Female</label>
  </div>

  <div style="margin-top: 20px">
    <mylib:submit type="submit"/>
    <mylib:submit type="reset"/>
  </div>
</mylib:dossier>
</body>
</html>
