import java.io.*;
import java.util.*;
import java.math.*;

public class e {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        BigInteger a = new BigInteger(in.next());
        BigInteger b = new BigInteger(in.next());
        BigInteger ans = a.multiply(b);

        out.println(ans);

    }

    public void run() {
        try {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            in = new FastScanner(inputStream);
            out = new PrintWriter(outputStream);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
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
        new e().run();
    }
}
