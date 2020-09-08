import junit.framework.*;

//Author: Reed Ceniviva
//Authored: 21/11/16
//test file for the gInt class

public class gIntTest extends TestCase
			{

			public gIntTest suite()
			{
				return new TestSuite(gIntTest.class);
			}

			public void testAdd()
			{
				gInt test;
				test = new gInt(2 , 2);

				gInt eval = test1.add(test);
				gInt eval2 = test2.add(test);
				assertEquals(eval.real(), (test1.real() + 2));
				assertEquals(eval.imag(), (test1.imag() + 2));
				assertEquals(eval2.imag(),(test2.imag() + 2));
				assertEquals(eval2.real(),(test2.real() + 2));
			}

			public void testMult()
			{
				gInt test;
				test = new gInt(2 , 2);

				gInt eval = test1.multiply(test);
				gInt eval2 = test2.multiply(test);
				assertEquals(eval.real(), (test1.real() * 2));
				assertEquals(eval.imag(), (test1.imag() * 2));
				assertEquals(eval2.imag(),(test2.imag() * 2));
				assertEquals(eval2.real(),(test2.real() * 2));
			}
			
			public void testNorm()
			{
				float eval = test1.norm();
				float eval2 = test2.norm();

				assertEquals(eval, (float)Math.sqrt(13));
				assertEquals(eval2, (float)Math.sqrt(41));
			}

			private gInt test1;
         private gInt test2;
			
			
			protected void setUp()
			{
			
			test1 = new gInt(2 , 3);
			test2 = new gInt(4 , 5);

			}



			public void main(String[] args)
			{		
				setUp();
				testAdd();
				setUp();
				testMult();
				setUp();
				testNorm();
			}


		}
		
