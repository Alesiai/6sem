package tags;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;
import java.io.IOException;

public class Dossier extends TagSupport {
    @Override
    public int doStartTag() throws JspException {
        JspWriter writer = pageContext.getOut();
        try {
            writer.print("<form method=\"post\" action=\"Ttt\">");
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        return EVAL_BODY_INCLUDE;
    }

    @Override
    public int doEndTag() throws JspException {
        JspWriter writer = pageContext.getOut();
        try {
            writer.print("</form>");
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        return EVAL_PAGE;
    }


}
