package filters;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import java.io.IOException;
import java.io.PrintWriter;

@WebFilter(filterName = "F4")
public class F4 implements Filter {
    public void destroy() {
    }

    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws ServletException, IOException {
        System.out.println("Filter F4 do filter");
        String blockCcc = req.getParameter("F4");
        if(!blockCcc.equals("BlockCcc") || blockCcc == null)
            chain.doFilter(req, resp);
        else{
            PrintWriter writer = resp.getWriter();
            writer.println("<body>");
            writer.println("<h1>Ccc blocked F4</h1>");
            writer.println("</body>");
        }
    }

    public void init(FilterConfig config) throws ServletException {

    }

}
