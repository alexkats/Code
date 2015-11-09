import java.io.*;
import java.util.*;
import java.math.*;

public class Template {
    FastScanner in;
    PrintWriter out;
    long startTime;
    long finishTime;

    public void solve() throws IOException {
        startTime = System.nanoTime();

        finishTime = System.nanoTime();
    }

    public void run() {
        try {
            in = new FastScanner(new File(".in"));
            out = new PrintWriter(new File(".out"));

            solve();

            long ttt = finishTime - startTime;
            double finalTtt = (double) (ttt) / 1e6;
            out.format(new Locale("en"), "%.3f\n", finalTtt);

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] arg) {
        new Template().run();
    }
}
