package listerners;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;
import javax.servlet.http.HttpSessionAttributeListener;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;
import javax.servlet.http.HttpSessionBindingEvent;

@WebListener()
public class L1 implements ServletContextListener {

    // Public constructor is required by servlet spec
    public L1() {
        System.out.println("listener listerners.L1 init");
    }

    // -------------------------------------------------------
    // ServletContextListener implementation
    // -------------------------------------------------------
    public void contextInitialized(ServletContextEvent sce) {
        System.out.println("listener listerners.L1 context Initialized");
    }

    public void contextDestroyed(ServletContextEvent sce) {
        System.out.println("listener listerners.L1 context Destroyed");
    }

}
