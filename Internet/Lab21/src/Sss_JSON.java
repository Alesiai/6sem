import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Random;

@WebServlet(name = "Sss_JSON", urlPatterns = "/Sss_JSON")
public class Sss_JSON extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int randN = Integer.parseInt((request.getHeader("XRand_n")));

        int amountOfNumbers = 5 + (int)(Math.random() * 5);
        int task = Integer.parseInt(request.getHeader("task"));

        if (task == 4) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
        JSONArray randomNumbers = new JSONArray();
        for (int i = 0; i < amountOfNumbers; i++) {
            randomNumbers.add((int)(Math.random()*randN * 2) - randN + 1);
        }
        JSONObject jsonObject = new JSONObject();
        jsonObject.put("numbers", randomNumbers);

        response.setContentType("application/json");
        response.getWriter().write(jsonObject.toJSONString());
    }
}
