//Reed Ceniviva - 5/11/16
//prob1.java
// assignment 1 from java ranch
//print the word passed from the command line 100 times


public class prob1
{
	public static void main( String [] args )
	{
		String word = args[0];
		for(int i = 0; i < 100; i++)
		{
			System.out.print(word + " ");
		}
	}
}
