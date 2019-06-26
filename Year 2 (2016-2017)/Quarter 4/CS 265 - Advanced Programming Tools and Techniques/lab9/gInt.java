import junit.framework.*;

//Author Reed Ceniviva
//Authored: 21/11/16
//Gaussian Integer Class

public class gInt{
	int x = 0;
	int y = 0;

	//constructor not including imaginary int
	public gInt(int r)
	{
		x = r; 
	}

	//constructor including the imaginary int
	public gInt(int r, int i)
	{
		x = r;
		y = i;
	}

	//as seen in Operand.java
	//real reutrns value of the real int of the gInt
	//imag returns the value of the imaginary number of gInt
	public int real(){ return x; }
	public int imag(){ return y; }
	

	//return a new gInt, the sum of this and rhs. Note, the object recieving
	//this mesage is not modified
	public gInt add(gInt rhs)
	{
		//"not modified" = set equal to a different gInt
		//                    v---real number---v    v-imaginary number-v
		gInt eval = new gInt((this.x + rhs.real()), (this.y + rhs.imag()));
		return eval;
	}

	//very similar to the last function
	//"return new gInt, the product of this and rhs, note the object
	//recieving this message is not modified"
	public gInt multiply(gInt rhs)
	{
		gInt eval = new gInt((this.x * rhs.real()), (this.y * rhs.imag()));
		return eval;
	}


	//"return the L2-norm of the integer ( the distance from the origin).The
	//object is not modified"
	//with a little research: L2 = distance = someway of using the
	//pythagorean theorem to get the distance from the closest corner of the
	//complex plane that the imaginary number sits on
	//seems like you just square and root the numbers for the equation
	public float norm()
	{
		float eval = (float)(Math.sqrt((this.x * this.x) + (this.y * this.y)));
		return eval;
	}

}
