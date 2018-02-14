package mx.letmethink;

import java.util.List;
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(in, out);
        out.close();
    }
}


class Solution {
    private final String coin;
    private final List<BigInteger> divisors;

    public Solution(long mask, final List<BigInteger> divisors, int bitSize) {
        char[] bits = new char[bitSize];
        for (int i = 0; i < bitSize; i++) {
            if ((mask & (1L << i)) != 0) {
                bits[i] = '1';
            } else {
                bits[i] = '0';
            }
        }
        this.coin = new String(bits);
        this.divisors = divisors;
    }

    public String getCoin() {
        return coin;
    }

    public final List<BigInteger> getDivisors() {
        return divisors;
    }

}

/** Built using CHelper plug-in, Actual solution is at the top. */
class Solver {
    private static final int MAX = 1 << 22;
    private long[] sieve;
    private List<BigInteger> primes;

    public void solve(InputReader in, PrintWriter out) {
        init();
        int T = in.nextInt();
        for (int tc = 1; tc <= T; tc++) {
            int N = in.nextInt();
            int J = in.nextInt();
            System.out.println("Case #" + tc + ":");
            for (Solution solution : findSolutions(N, J)) {
                System.out.print(solution.getCoin());
                for (BigInteger divisor : solution.getDivisors()) {
                    System.out.print(" " + divisor);
                }
                System.out.println();
            }
        }
    }

    void init() {
        sieve = new long[MAX];
        primes = new ArrayList<>();

        long sr = (long)Math.sqrt(MAX);
        for (int i = 2; i <= sr; i++) {
            if (sieve[i] != 0) {
                continue;
            }
            for (int j = i * i; j < MAX; j += i) {
                sieve[j] = i;
            }
        }
        for (long i = 2; i < MAX; i++) {
            if (sieve[(int)i] == 0) {
                primes.add(new BigInteger(i + ""));
            }
            if (primes.size() == 5000) {
                break;
            }
        }
    }

    BigInteger convert(long mask, int base, int bitSize) {
        char[] digits = new char[bitSize];
        for (int i = 0; i < bitSize; i++) {
            digits[i] = ((mask & (1L << i)) != 0) ? '1' : '0';
        }
        return new BigInteger(new String(digits), base);
    }


    public List<Solution> findSolutions(int N, int J) {
        List<Solution> solutions = new ArrayList<>();
        for (long mask = 0; mask < (1L << (N - 2)); mask++) {
            long candidate = (mask << 1) | 1L | (1L << (N - 1));
            List<BigInteger> divisors = new ArrayList<>();
            for (int base = 2; base <= 10; base++) {
                BigInteger x = convert(candidate, base, N);
                BigInteger divisor = null;
                for (BigInteger p : primes) {
                    if ((p.compareTo(x) < 0) && (x.mod(p).equals(BigInteger.ZERO))) {
                        divisor = p;
                        break;
                    }
                }
                if (divisor != null) {
                    divisors.add(divisor);
                }
            }
            if (divisors.size() == 9) {
                solutions.add(new Solution(candidate, divisors, N));
            }
            if (solutions.size() == J) {
                break;
            }
        }
        return solutions;
    }


}

//region
class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream)
    {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next()
    {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        return tokenizer.nextToken();
    }

    public int nextInt()    { return Integer.parseInt(next());  }
    public long nextLong()  { return Long.parseLong(next());    }
}
