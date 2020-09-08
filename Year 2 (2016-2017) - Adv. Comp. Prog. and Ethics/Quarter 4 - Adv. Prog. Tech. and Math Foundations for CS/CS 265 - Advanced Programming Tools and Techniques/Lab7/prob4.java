//Reed Ceniviva - 5/11/16 - prob4.java
//assignment 8 from javaranch, cattle drive
// "GeekWatch"
import java.util.Date;

public class prob4
{

	public static void main (String[] args)
	{
		Date date = new Date();
		int type = Integer.parseInt(args[0]);
		long milli = date.getTime();
		long sec = (milli/1000);
		long days = (sec/86400);
		switch (type)
		{
				case 0:
						System.out.println("millisoconds since January 1, 1970: " + milli);
						break;
				case 1:
						System.out.println("seconds since January 1, 1970: " + sec);
						break;
				case 2:
						System.out.println("days since January 1, 1970: " + days);
						break;
				case 3:
						System.out.println("current date and time: " + date);
						break;
				default:
						System.out.println("that is not an option for this program");
		}
	}
}
