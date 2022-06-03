import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "Ttt", urlPatterns = "/Ttt")
public class Ttt extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String surname = request.getParameter("surname");
        String lastname = request.getParameter("lastname");
        String sex = request.getParameter("sex");

        response.getWriter().write("lastname: " + lastname);
        response.getWriter().write("\nSurname: " + surname);
        response.getWriter().write("\nSex: " + sex);
    }
}
