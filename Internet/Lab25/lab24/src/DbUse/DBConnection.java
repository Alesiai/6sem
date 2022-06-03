package DbUse;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {
    public static Connection connection;

    public static void connectToDB() throws SQLException, ClassNotFoundException {
        Class.forName("com.mysql.jdbc.Driver");

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
