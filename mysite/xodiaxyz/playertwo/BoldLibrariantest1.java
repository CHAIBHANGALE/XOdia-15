package grow;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//your class name should be username+testno
//for e.g: username is xyz and your program is in test1 then class name is xyztest1
//for e.g: username is xyz and your program is in test2 then class name is xyztest2
//for e.g: username is xyz and your program is in final submit then class name is xyzfinal
public class BoldLibrariantest1 {
	
	public static void main(String[] args) throws IOException {
		BoldLibrariantest1 referee = new BoldLibrariantest1(); 
		referee.init();
	}

	public void init() throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	    char array[][][]=new char[20][20][9];
	    String s=br.readLine();
	    int i,j,k,i1=0,i2=0,i3=0,j1=0,j2=0,j3=0;
	    /*
	    for(i=0;i<20;i++)
	    {
	      for(j=0;j<20;j++)
	      {
	        for(k=0;k<9;k++)
	        {
	          array[i][j][k]=s.charAt(i*9*20+j*9+k);
	        }
	      }
	    }
	    */
	    System.err.println("0,0,1,1");
	    System.out.println("0,0,1,1");
	    
	}
}
