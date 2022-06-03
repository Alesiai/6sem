import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "Ggg", urlPatterns = {"/ggg"})
public class Ggg extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println("GGG");
        response.setContentType("text/html");
        PrintWriter writer = response.getWriter();
        String value = request.getParameter("value");

        try {
            writer.println("<h2>Found: " + value + "</h2>");
        } finally {
            writer.close();
        }
    }
}
