<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>$Title$</title>
  </head>
  <body>
  <p>URL1: <%=pageContext.getServletContext().getInitParameter("URL1")%></p>
  <p>URL2: <%=pageContext.getServletContext().getInitParameter("URL2")%></p

    <br>
  <p>
    <a href="./ServletFirst?urln=1">URL 1</a>
    <br>
    <br>
    <a href="./ServletFirst?urln=2" >URL 2</a>
  </p>
  <br>
  <form action="Ccc" method="post">
    <div>
      <label>Value1 <input type="text" name="Value1"/></label>
    </div>
    <br>
    <div>
      <label>Value2 <input type="text" name="Value2"/></label>
    </div>
    <br>
    <div>
      <label>Value3 <input type="text" name="Value3"/></label>
    </div>
    <br>
    <div>
      <label><input type="radio" name="CBean" value="new" />New</label>
      <label><input type="radio" name="CBean" value="old" checked/>Old</label>
    </div>
    <br>
    <input type="submit" value="Send"/>
    <div>
      <label><input type="radio" name="F1" value="BlockCcc"/>Block Ccc</label>
      <label><input type="radio" name="F1" value="DeBlockCcc"/>No Block Ccc</label>
    </div>
    <div>
      <h3>F3</h3>
      <label><input type="radio" name="F3" value="BlockCcc"/>Block Ccc</label>
      <label><input type="radio" name="F3" value="DeBlockCcc"/>No Block Ccc</label>
    </div>
    <div>
      <h3>F4</h3>
      <label><input type="radio" name="F4" value="BlockCcc"/>Block Ccc</label>
      <label><input type="radio" name="F4" value="DeBlockCcc"/>No Block Ccc</label>
    </div>
  </form>

  <p><b>lab16</b></p>
  <form action="Ccc" method="get">
    <div>
      <label>Value1 <input type="text" name="Value1"/></label>
    </div>
    <div>
      <label>Value2 <input type="text" name="Value2"/></label>
    </div>
    <div>
      <label>Value3 <input type="text" name="Value3"/></label>
    </div>
    <div>
      <label><input type="radio" name="typee" value="request"/>Request</label>
      <label><input type="radio" name="typee" value="session"/>Session</label>
    </div>
    <div>
      <label><input type="radio" name="CBean" value="new"/>New</label>
      <label><input type="radio" name="CBean" value="old"/>Old</label>
    </div>
    <div>lab18</div>
    <div>
      <h3>F1</h3>
      <label><input type="radio" name="F1" value="BlockCcc"/>Block Ccc</label>
      <label><input type="radio" name="F1" value="DeBlockCcc"/>No Block Ccc</label>
    </div>
    <div>
      <h3>F3</h3>
      <label><input type="radio" name="F3" value="BlockCcc"/>Block Ccc</label>
      <label><input type="radio" name="F3" value="DeBlockCcc"/>No Block Ccc</label>
    </div>
    <div>
      <h3>F4</h3>
      <label><input type="radio" name="F4" value="BlockCcc"/>Block Ccc</label>
      <label><input type="radio" name="F4" value="DeBlockCcc"/>No Block Ccc</label>
    </div>
    <input type="submit" value="Send"/>


  </form>

  </body>
</html>
