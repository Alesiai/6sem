<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>LB-20</title>
  <script type="application/javascript" src="JS/ajax.js"></script>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js"></script>
</head>
<body>
<b> AJAX Example (Header) </b>
<form action="#" method="post" onsubmit="return false">
  <label>x: <input type="text" name="x"/></label>
  <label>y: <input type="text" name="y"/></label>
  <label>z: <input type="text" name="z"/></label>
  <button onclick="setHeaderToAJAX(this.form.x, this.form.y, this.form.z)">Send AJAX-Header</button>
</form>


<form action="#" method="post" onsubmit="return false" style="margin-top: 40px">
  <label>n: <input type="text" name="n"/></label>
  <button onclick="setHeaderGetXml(this.form.n)" >Send AJAX-XML</button>
  <p>Result: <span id="resultFromXmlReq"></span></p>
</form>

<form action="#" method="post" onsubmit="return false" style="margin-top: 40px">
  <label>n: <input type="text" name="n"/></label>
  <button onclick="setHeaderGetJson(this.form.n)" >Send AJAX-JSON</button>
  <p>Result: <span id="resultFromJsonReq"></span></p>
</form>

<form action="#" method="post" onsubmit="return false" style="margin-top: 40px">
  <div style="display: flex; flex-direction: column; margin-bottom: 10px">
    <label>x: <input type="text" name="x"/></label>
    <label>y: <input type="text" name="y"/></label>
    <label>z: <input type="text" name="z"/></label>
    <label>n: <input type="text" name="n"/></label>
  </div>
  <div>
    <label><input type="radio" value="" name="ajaxType"/>Sync</label>
    <label><input type="radio" value="true" name="ajaxType"/>Async</label>
  </div>
  <button onclick="callAllAjaxes(this.form.x, this.form.y, this.form.z, this.form.n, Boolean(this.form.ajaxType.value))" >Send AJAX-JSON</button>
</form>


<form action="#" method="post" onsubmit="return false" style="margin-top: 40px">
  <label>n: <input type="text" name="n"/></label>
  <button onclick="sendAjaxJQuery(this.form.n)" >Send AJAX-JQuery</button>
  <p>Result: <span id="resultFromJQueryReq"></span></p>
</form>

</body>
</html>