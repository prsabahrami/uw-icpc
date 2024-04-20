import java.math.*;
import java.io.*;
import java.util.*;

class D {

	int doit(BigDecimal H, BigDecimal V, BigDecimal h, BigDecimal v, 
		 BigDecimal x, BigDecimal y, int c)
	{
		BigDecimal a = H.multiply(h);
		BigDecimal b = V.multiply(v);
		if (x.compareTo(a) < 0) {
			if (y.compareTo(b) > 0) return c;
			return doit(a, b, h, v, x, y, c^1);
		}
		if (y.compareTo(b) < 0) return c;
		return doit(H.subtract(a), V.subtract(b), h, v,
			    x.subtract(a), y.subtract(b), c^1);
	}

	public static void main(String[] args) {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BigDecimal H, V, h, v, x, y,zero;
		String line,num;
		StringTokenizer st;
		C me;

		try {
			zero = new BigDecimal("0");
			int cnum = 1;
			me = new C();
			while(true) {
				line = in.readLine();
				if(line == null) break;
				st = new StringTokenizer(line);
				
				H = new BigDecimal(st.nextToken());
				if (H.compareTo(zero) == 0) break;
				V = new BigDecimal(st.nextToken());
				h = new BigDecimal(st.nextToken());
				v = new BigDecimal(st.nextToken());

				System.out.println("Case " + cnum++ + ":");

				int i;
				int n = Integer.parseInt(in.readLine());
				for (i=0; i<n; i++) {
					line = in.readLine();
					st = new StringTokenizer(line);
					x = new BigDecimal(st.nextToken());
					y = new BigDecimal(st.nextToken());
					int c = me.doit(H,V,h,v,x,y,0);
					if (c == 0) System.out.println("black");
					else System.out.println("white");
				}
			}
		} catch(Exception e) {
			System.err.println(e.toString());
		}
	}
}
