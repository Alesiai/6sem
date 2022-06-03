package filters;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import java.io.IOException;
import java.io.PrintWriter;

@WebFilter(filterName = "F1")
public class F1 implements Filter {
    public void destroy() {
    }

    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws ServletException, IOException {
        System.out.println("Filter F1 do filter");
        String blockCcc = req.getParameter("F1");
        if(!blockCcc.equals("BlockCcc") || blockCcc == null)
            chain.doFilter(req, resp);
        else{
            PrintWriter writer = resp.getWriter();
            writer.println("<body>");
            writer.println("<h1>Ccc blocked F1</h1>");
            writer.println("</body>");
        }
    }

    public void init(FilterConfig config) throws ServletException {
        System.out.println("Filter F1 init");
    }

}
