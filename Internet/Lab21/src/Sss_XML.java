import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Random;

@WebServlet(name = "Sss_XML", urlPatterns = "/Sss_XML")
public class Sss_XML extends HttpServlet {
    private final int lowBorder = 5;
    private final int highBorder = 10;
    private final String xmlHeader = "<?xml version=\"1.0\" encoding=\"utf-8\" ?><rand>\"";

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int randN = Integer.parseInt((request.getHeader("XRand_n")));

        int amountOfNumbers = 5 + (int)(Math.random() * 5);

        int task = Integer.parseInt(request.getHeader("task"));
        if (task == 4) {
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }

        StringBuilder resultXml = new StringBuilder(xmlHeader);
        for (int i = 0; i < amountOfNumbers; i++) {
            int number = (int)(Math.random()*randN * 2) - randN + 1;
            resultXml.append("<number>").append(number).append("</number>");
        }
        resultXml.append("</rand>");

        response.setContentType("text/xml;charset=UTF-8");
        response.getWriter().write(resultXml.toString());
    }
}
