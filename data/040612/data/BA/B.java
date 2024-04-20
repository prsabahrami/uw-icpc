// three powers problem
// took me about 20 min, but I was struggling with java.
// I could see somebody doing it <10 min.
import java.math.*;
import java.io.*;
import java.util.*;

class B {
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(
				new InputStreamReader(System.in));
        String line;
	StringTokenizer st;
	BigInteger a,b,n,r;
	BigInteger two,three;
	int p,first;

	two = new BigInteger("2");
	three = new BigInteger("3");
	try {
	    while(true) {
                line = in.readLine();
                if(line == null) break;
		st = new StringTokenizer(line);
		n = new BigInteger(st.nextToken());
		if (n.intValue() == 0) break;
		n = n.subtract(BigInteger.valueOf(1));
		System.out.print("{");
		
		for (p=0, first=1; n.signum()>0; p++) {
			r = n.mod(two);
			if (r.intValue() == 1) {
				if (first==0) System.out.print(", ");
				else System.out.print(" ");
				first = 0;
				System.out.print(three.pow(p));
			}
			n = n.divide(BigInteger.valueOf(2));		
		}
		System.out.println(" }");
	    }
	} catch(Exception e) {
            System.err.println(e.toString());
	}
    }
}
