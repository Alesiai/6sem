import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {
    public static Connection connection;



    public void connectToDB() throws SQLException, ClassNotFoundException {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            System.out.println("Driver loaded!");
        } catch (ClassNotFoundException e) {
            throw new IllegalStateException("Cannot find the driver in the classpath!", e);
        }

        String URL = "jdbc:mysql://localhost:3306/db";
        connection = DriverManager.getConnection(URL, "root", "secret");
        if (connection != null) {
            System.out.println("Connect to db has been performed successfully");
        }
        else {
            System.out.println("dont Connect to db");
        }
    }
}
