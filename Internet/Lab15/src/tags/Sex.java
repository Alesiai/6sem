package tags;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;
import java.io.IOException;

public class Sex extends TagSupport {
    private String value = "";

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    @Override
    public int doStartTag() throws JspException {
        JspWriter writer = pageContext.getOut();
        try {
            writer.print("<input type=\"radio\" name=\"sex\" value=\"" + value + "\" />");
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        return SKIP_BODY;
    }
}
