import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.methods.GetMethod;
import org.apache.commons.httpclient.methods.PostMethod;

import javax.servlet.Servlet;
import java.io.IOException;
import java.util.Enumeration;

public class Aaa extends javax.servlet.http.HttpServlet implements Servlet {
    protected void doPost(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {

    }

    protected void doGet(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {
        HttpClient hc = new HttpClient();
        String uri = "http://172.16.193.69:8080/AS_3315IAA18/Bbb";
        PostMethod pm = new PostMethod(uri);
        pm.addRequestHeader("MyHeader1", "MyHeadetValue1");
        pm.addRequestHeader("MyHeader2", "MyHeadetValue2");
        pm.addRequestHeader("MyHeader3", "MyHeadetValue3");
        String s;
        Enumeration enr = request.getParameterNames();

        while (enr.hasMoreElements()) {
            s = (String) enr.nextElement();
            pm.addParameter(s, request.getParameter(s));
        }
        hc.executeMethod(pm);
        response.setContentType("text/html");
        InOutServlet inout = new InOutServlet(response.getOutputStream(),
                pm.getResponseBodyAsStream());
        inout.perform();

    }
}
