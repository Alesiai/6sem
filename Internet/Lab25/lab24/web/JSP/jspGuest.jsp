<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <title>--UWSR--</title>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js"></script>
    <script src="JS/UsingDataMSREF.js"></script>
    <script src="JS/UsingDataMSREFComments.js"></script>
    <link rel="icon" href="data:,">
</head>
<body onload="getWSREFS()">
<h1>--UWSR--</h1>
<div id="Search">
    <form method="post" action="ChangeRole">
        <input type="hidden" name="Role" value="owner">
        <input type="text" width="200px" name="Password">
        <input class="button" type="submit" value="Set" >
    </form>
    <input class="button" type="button" value="Set2" onclick="inowner()" >
    <form method="post" action="ChangeRole">
        <input type="hidden" name="Role" value="guest">
    </form>
</div>
<br>
<input type="button" value="filter" onclick="visibilityFilterForm()">
<br>
<div id="form"></div><br>
<br>
<table id="tableWSREF">

</table>

</body>
</html>
