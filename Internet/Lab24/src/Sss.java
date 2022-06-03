import org.apache.commons.httpclient.*;
import org.apache.commons.httpclient.auth.*;
import org.apache.commons.httpclient.methods.*;
import org.apache.commons.httpclient.methods.PutMethod;
import org.apache.commons.httpclient.methods.multipart.*;
import org.apache.jackrabbit.webdav.client.methods.*;

import javax.servlet.Servlet;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;

public class Sss extends HttpServlet implements Servlet {
	
	protected void doPost(HttpServletRequest rq, HttpServletResponse rs) throws ServletException, IOException {
		String op_type = rq.getParameter("Add");
		if(rq.getParameter("add").equals("Create Directory"))
		{
			String response = null;
			HttpClient client = new HttpClient( );
			String url = "https://webdav.yandex.ru";
			client.getState().setCredentials(
				new AuthScope(AuthScope.ANY_HOST, AuthScope.ANY_PORT), 
				new UsernamePasswordCredentials("alesiaiai", "ckinhmqojbcsgeew"));
			DavMethod method = new MkColMethod(url);
			client.executeMethod(new MkColMethod(url + "/" + rq.getParameter("dir")));
			method.releaseConnection();

			PrintWriter writer = rs.getWriter();
			writer.println("Directory was created");
			writer.close();
		}


		if(rq.getParameter("add").equals("Download"))
		{
			String response = null;
			HttpClient client = new HttpClient( );
			String url = "https://webdav.yandex.ru";
			client.getState().setCredentials(
				new AuthScope(AuthScope.ANY_HOST, AuthScope.ANY_PORT),
					new UsernamePasswordCredentials("alesiaiai", "ckinhmqojbcsgeew"));
			DavMethod method = new MkColMethod(url);
			try
            {
                String docdir   = getServletContext().getInitParameter("doc-dir");
				GetMethod httpMethod = new GetMethod(url + "/" + rq.getParameter("dir"));
				client.executeMethod(httpMethod);
                InputStream inputStream = httpMethod.getResponseBodyAsStream();
				File fff = new File(docdir + rq.getParameter("dir"));
				System.out.println(fff.exists());
				OutputStream outputStream = new FileOutputStream(fff);
					byte[] buf = new byte[1024];
					int len;
					while ((len = inputStream.read(buf)) > 0){
						outputStream.write(buf, 0, len);
					}
					outputStream.close();
					inputStream.close();
			}
            catch (IOException ex)
            {
            }
            finally
            {
                method.releaseConnection();
            }
			PrintWriter writer = rs.getWriter();
			writer.println("Successfully downloaded"); 
			writer.close();
		}


		if(rq.getParameter("add").equals("Upload"))
		{
			String response = null;
			HttpClient client = new HttpClient( );
			String url = "https://webdav.yandex.ru";
			client.getState().setCredentials(
				new AuthScope(AuthScope.ANY_HOST, AuthScope.ANY_PORT),
					new UsernamePasswordCredentials("alesiaiai", "ckinhmqojbcsgeew"));
			
			String docdir   = getServletContext().getInitParameter("doc-dir");
				String path = rq.getParameter("dir");
				System.out.println(docdir);
				System.out.println(path);
				File from = new File(docdir+path);
				PutMethod method = new PutMethod(url + "/" + from.getName());
				RequestEntity requestEntity = new InputStreamRequestEntity(
		    		new FileInputStream(from));
				method.setRequestEntity(requestEntity);
				client.executeMethod(method);
			
			PrintWriter writer = rs.getWriter();
			writer.println("Successfully uploaded");
			writer.close();
		}


        if(rq.getParameter("add").equals("Delete")) 
		{ 
			HttpClient client = new HttpClient( ); 
			String url = "https://webdav.yandex.ru";
			client.getState().setCredentials( 
			new AuthScope(AuthScope.ANY_HOST, AuthScope.ANY_PORT),
					new UsernamePasswordCredentials("alesiaiai", "ckinhmqojbcsgeew"));
			org.apache.commons.httpclient.methods.DeleteMethod method = 
				new org.apache.commons.httpclient.methods.DeleteMethod(
					url + "/" + rq.getParameter("dir")); 
			try 
			{ 
				client.executeMethod(method); 
			} 
			catch (IOException ex)
			{ 
			} 
			finally 
			{ 
				method.releaseConnection(); 
			} 
			PrintWriter writer = rs.getWriter();
			writer.println("Successfully deleted");
			writer.close();
		}
		if(rq.getParameter("add").equals("Copy")) 
		{ 
			HttpClient client = new HttpClient( ); 
			String url = "https://webdav.yandex.ru";
			client.getState().setCredentials( 
			new AuthScope(AuthScope.ANY_HOST, AuthScope.ANY_PORT),
					new UsernamePasswordCredentials("alesiaiai", "ckinhmqojbcsgeew"));
			CopyMethod method = 
				new CopyMethod(
					url + "/" + rq.getParameter("dir"),url + "/" + rq.getParameter("todir") + "/" +  rq.getParameter("dir"),true); 
			try 
			{ 
				client.executeMethod(method); 
			} 
			catch (IOException ex)
			{ 
			} 
			finally 
			{ 
				method.releaseConnection(); 
			} 
			PrintWriter writer = rs.getWriter();
			writer.println("Successfully copied"); 
			writer.close();
		}
	}   	
}