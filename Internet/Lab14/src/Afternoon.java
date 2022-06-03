import javax.servlet.Servlet;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/Afternoon")
public class Afternoon extends HttpServlet implements Servlet {

    public void init(ServletConfig var1) throws ServletException {
        super.init();
        System.out.println("Afternoon:init");
    }

    public void destroy() {
        super.destroy();
        System.out.println("Afternoon:destroy");
    }

    protected void service(HttpServletRequest var1, HttpServletResponse var2) throws ServletException, IOException {
        System.out.println("Afternoon:service:" + var1.getMethod());
        PrintWriter var3 = var2.getWriter();
        var3.println("Servlet:Good afternoon\n");
        var3.flush();
    }
}
