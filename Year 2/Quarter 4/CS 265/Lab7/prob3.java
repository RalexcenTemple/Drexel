//Reed Ceniviva - 5/11/16
// prob3.java
//assignment 3 from java ranch cattle drive
// "Leap"
//to tell if the year given is a leap year or nc class prob3
public class prob3
{
	public static void main(String[] args)
	{
			int i = Integer.parseInt(args[0]);
			if((i%100) == 0 && (i%400)==0)
			{
				System.out.println("Leap year!");
			}
			else if((i%4) == 0 && (i%100)!=0)
			{
				System.out.println("Leap year!"); 
			}
			else
			{
			System.out.println("not a Leap year"); 
			}
	}
}

