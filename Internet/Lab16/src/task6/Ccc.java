package task6;
import javax.servlet.RequestDispatcher;
import javax.servlet.Servlet;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class Ccc extends HttpServlet implements Servlet {

    private CBean cBean;

    @Override
    public void init() throws ServletException {
        super.init();
        this.cBean = new CBean();
    }

    private void setCBeanValues(String value1, String value2, String value3) {
        if (value1 != null && !value1.equals("")) {
            this.cBean.setValue1(value1);
        }
        if (value2 != null && !value2.equals("")) {
            this.cBean.setValue2(value2);
        }
        if (value3 != null && !value3.equals("")){
            this.cBean.setValue3(value3);
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String cbean = request.getParameter("CBean");
        String value1 = request.getParameter("Value1");
        String value2 = request.getParameter("Value2");
        String value3 = request.getParameter("Value3");
        getServletContext().setAttribute("atrCbean", this.cBean);

        if (cbean.equals("new") ) {
            this.cBean = new CBean();
            setCBeanValues(value1, value2, value3);
            getServletContext().setAttribute("atrCbean", this.cBean);
        } else if (cbean.equals("old")) {
            setCBeanValues(value1, value2, value3);
        }

        request.getRequestDispatcher("/JSP/Ccc.jsp").forward(request, response);
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
