package listerners;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;
import javax.servlet.http.HttpSessionAttributeListener;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;
import javax.servlet.http.HttpSessionBindingEvent;
import javax.servlet.ServletContext;



@WebListener()
public class L2 implements HttpSessionAttributeListener {

    // Public constructor is required by servlet spec
    public L2() {
        System.out.println("listener listerners.L2 init");
    }

    public void attributeAdded(HttpSessionBindingEvent sbe) {
        System.out.println("Lst2:attributeAdded:AtributeName= "
                +sbe.getName());
        System.out.println("Lst2:attributeAdded:AtributeValue "
                +sbe.getValue());

    }

    public void attributeRemoved(HttpSessionBindingEvent e) {
        System.out.println("Lst2:attributeRemoved:AtributeName= "
                +e.getName());
        System.out.println("Lst2:attributeRemoved:AtributeValue "
                +e.getValue());
    }

    public void attributeReplaced(HttpSessionBindingEvent e) {
        System.out.println("Lst2:attributeReplaced:AtributeName="
                +e.getName());
        System.out.println("Lst2:attributeReplaced:AtributeOldValue "
                +e.getValue());
    }
}
