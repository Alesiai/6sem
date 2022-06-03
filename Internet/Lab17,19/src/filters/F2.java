package filters;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import java.io.IOException;
import java.io.PrintWriter;

@WebFilter(filterName = "F2")
public class F2 implements Filter {
    public void destroy() {
    }

    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws ServletException, IOException {
        //chain.doFilter(req, resp);
        System.out.println("Filter F2 do filter");
        PrintWriter writer = resp.getWriter();
        writer.println("<body>");
        writer.println("<h1>Ccc.jsp blocked</h1>");
        writer.println("</body>");
    }

    public void init(FilterConfig config) throws ServletException {

    }

}
