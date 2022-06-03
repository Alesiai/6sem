package tags;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;
import java.io.IOException;

public class Submit extends TagSupport {
    private String type = "";

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    private String getTag(String type) {
        String label = type.equals("submit") ? "OK" : "Cancel";
        return "<button type=\"" + type + "\">" + label + "</button>";
    }

    @Override
    public int doStartTag() throws JspException {
        JspWriter writer = pageContext.getOut();
        try {
            writer.print(getTag(type));
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        return SKIP_BODY;
    }
}