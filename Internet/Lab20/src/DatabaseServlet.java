import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.Writer;
import java.sql.*;

@WebServlet(name = "DatabaseServlet", urlPatterns = "/db")
public class DatabaseServlet extends HttpServlet {
    @Override
    public void init() throws ServletException {
        super.init();

        DBConnection db = new DBConnection();
        try {
            db.connectToDB();
        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int parid = Integer.parseInt(request.getParameter("id"));

        try {
            CallableStatement callState = DBConnection.connection.prepareCall("call SelectUserId(?)");

            callState.setInt(1, parid);

            Writer writer = response.getWriter();
            if(callState.execute()){
                ResultSet resultSet = callState.getResultSet();
                while (resultSet.next()){
                    writer.write("<html>");
                    writer.write(" id =  ");
                    int id = resultSet.getInt("id");
                    writer.write(Integer.toString(id));
                    writer.write("<br> name = ");
                    writer.write(resultSet.getString("name"));
                    writer.write("<br> age = ");
                    writer.write(resultSet.getString("age"));
                    writer.write("</html>");
                }
            }

        } catch (SQLException e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String type = request.getParameter("type");
        String userId = request.getParameter("user_id");

        response.setContentType("text/html");
        try {
            if (type != null && type.equals("dynamic")) {
                PreparedStatement prepState = DBConnection.connection.prepareStatement("SELECT * FROM TestUsers WHERE Id = ?");
                prepState.setString(1, userId);
                ResultSet resultSet = prepState.executeQuery();

                response.getWriter().write("<html><body>");
                while (resultSet.next()) {
                    String id = resultSet.getString("Id");
                    String name = resultSet.getString("Name");
                    int age = Integer.parseInt(resultSet.getString("Age"));

                    response.getWriter().write("<p>Id: " + id + " Name: " + name + " Age: " + age + "</p>");
                }
                response.getWriter().write("</body></html>");
            } else {
                Statement query = DBConnection.connection.createStatement();
                ResultSet resultSet = query.executeQuery("SELECT * FROM TestUsers");
                response.getWriter().write("<html><body><ul>");

                while (resultSet.next()) {
                    String id = resultSet.getString("Id");
                    String name = resultSet.getString("Name");
                    int age = Integer.parseInt(resultSet.getString("Age"));

                    response.getWriter().write("<p><b>Id:</b> " + id + " <b>Name:</b> " + name + " <b>Age:</b> " + age + "</p>");
                }
                response.getWriter().write("</ul></body></html>");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }
    }
}
