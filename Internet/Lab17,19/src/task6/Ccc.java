package task6;
import javax.servlet.RequestDispatcher;
import javax.servlet.Servlet;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

public class Ccc extends HttpServlet implements Servlet {

    private CBean cBean;

    @Override
    public void init() throws ServletException {
        super.init();
        this.cBean = new CBean();
        System.out.println("Servlet Ccc init");
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
        String cbean = request.getParameter("CBean");
        String typee = request.getParameter("typee");
        String value1 = request.getParameter("Value1");
        String value2 = request.getParameter("Value2");
        String value3 = request.getParameter("Value3");

        if (typee.equals("request")) {
            if (cbean.equals("new")) {
                CBean newCbean = new CBean();
                if (value1 != null && !value1.equals("")) {
                    newCbean.setValue1(value1);
                }
                if (value2 != null && !value2.equals("")) {
                    newCbean.setValue2(value2);
                }
                if (value3 != null && !value3.equals("")){
                    newCbean.setValue3(value3);
                }
                request.setAttribute("atrCbeanRequest", newCbean);
                getServletContext().setAttribute("newReq", "request");
            } else if (cbean.equals("old")) {
                setCBeanValues(value1, value2, value3);
                request.setAttribute("atrCbeanRequest", request.getAttribute("atrCbeanRequest"));
                getServletContext().setAttribute("oldReq", "request");
            }

        } else if (typee.equals("session")) {
            HttpSession session = request.getSession();
            if (cbean.equals("new")) {
                CBean newCBean = new CBean();
                if (value1 != null && !value1.equals("")) {
                    newCBean.setValue1(value1);
                }
                if (value2 != null && !value2.equals("")) {
                    newCBean.setValue2(value2);
                }
                if (value3 != null && !value3.equals("")){
                    newCBean.setValue3(value3);
                }
                session.setAttribute(session.getId(), newCBean);
            } else if (cbean.equals("old")) {
                setCBeanValues(value1, value2, value3);
                //CBean cs = (CBean)session.getAttribute(session.getId());
                //session.setAttribute(session.getId(), cs);
                session.setAttribute(session.getId(), session.getAttribute(session.getId()));
            }
        }
        request.getRequestDispatcher("/JSP/Ccc.jsp").forward(request, response);

    }
}
