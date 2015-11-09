import java.io.*;
import java.util.*;
import java.math.*;

public class Test {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {

        File f = new File("test.in");

        BufferedReader br = new BufferedReader(new FileReader(f));
        in = new FastScanner(f);

        while (true) {
            String s = br.readLine();

            if (s == null) {
                break;
            } else {
                out.println(s);
            }
        }
    }

    public void run() {
        try {
            out = new PrintWriter(new File("test.out"));

            solve();

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
        new Test().run();
    }
}
