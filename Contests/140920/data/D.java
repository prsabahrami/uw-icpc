import java.util.*;
public class D {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();// cols
    int m = sc.nextInt();// rows
    int f = sc.nextInt();
    boolean[][] furn = new boolean[n][m]; // row, col
    {
        for (int i=0; i<f; i++)
            furn[sc.nextInt()-1][sc.nextInt()-1] = true;
    }
    int h = n;
    
    {        
        for (int i=0; i<m; i++) { // for each col
            int latest = -1;
            for (int j=0; j<n; j++) {
                if (furn[j][i]) {
                    if (latest != j-1) {
                        h = Math.min(h, j-latest-1);
                    }
                    latest = j;
                }
            }
            if (latest != n-1)
                h = Math.min(h, n-1-latest);
        }
        
        // now h is the broom height
    }
    
    // NEW!
    boolean[][] bottomCanGo = new boolean[n][m];
    {
        for (int i=0; i<m; i++) {
            int latest = -1;
            for (int j=0; j<n; j++) {
                if (furn[j][i]) 
                    latest = j;
                bottomCanGo[j][i] = (latest <= j-h);
            }
        }
    }
    // END NEW!
    
    boolean[][] dirrrty = new boolean[n][m]; // row, col
    
    {
        for (int i=0; i<m; i++) for (int j=0; j<n; j++) 
            dirrrty[j][i] = !furn[j][i];
    }
    
    int sweeps = 0;
    
    {    
        for (int i=0; i<m; i++) for (int j=1; j<=n; j++) {
            if (dirrrty[j-1][i] && (j==n || furn[j][i])) {
                makeSweep(j-1, i); //j-1..j-h
                sweeps++;
            }
        }
        for (int i=0; i<m; i++) for (int j=-1; j<n-1; j++) {
            if (dirrrty[j+1][i] && (j==-1 || furn[j][i])) {
                makeSweep(j+h, i); //j+1..j+h
                sweeps++;
            }
        }
        for (int i=0; i<m; i++) for (int j=n-1; j>=0; j--) {
            if (dirrrty[j][i]) {
                makeSweep(j, i); 
                sweeps++;
            }
        }
    }
    
    void makeSweep(int bottom, int col) {
        //System.out.println(bottom+" "+col);
        for (int dir=-1; dir<=1; dir+=2) {
            int c = col;
            outer: while (c >= 0 && c < m) {
                if (!bottomCanGo[bottom][c]) break; // NEW!
                //for (int i=bottom; i>=bottom-h+1; i--) //OLD!
                    //if (furn[i][c]) break outer;// OLD!
                for (int i=bottom; i>=bottom-h+1; i--)
                    dirrrty[i][c] = false;
                c += dir;
            }
        }
    }
    
    {
        System.out.println(h);
        System.out.println(sweeps);
    }
    
    public static void main(String[] args) {
        new D();
    }
}
