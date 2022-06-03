import javax.servlet.Servlet;
import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class Sss extends HttpServlet implements Servlet {

    public Sss() {
        super();
    }

    protected void doGet(HttpServletRequest rq, HttpServletResponse rs)
            throws ServletException, IOException {
        String filename = rq.getParameter("file");
        System.out.println(filename);
        String docdir = rq.getServletContext().getInitParameter("doc-dir");
        System.out.println(docdir);
        File dir = new File(docdir + "/" + filename);
        System.out.println(docdir + "/" + filename);
        OutputDoc(dir, rs);
    }

    protected void OutputDoc(File doc, HttpServletResponse rs) throws IOException {
        rs.setContentType("application/msword");
        rs.addHeader("Content-Disposition", "attachment; filename=" + doc.getName());
        rs.setContentLength((int) doc.length());
        FileInputStream in = new FileInputStream(doc);
        BufferedInputStream buf = new BufferedInputStream(in);
        ServletOutputStream out = rs.getOutputStream();
        int readBytes = 0;
        while ((readBytes = buf.read()) != -1)
            out.write(readBytes);

    }
}