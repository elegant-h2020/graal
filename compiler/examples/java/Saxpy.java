import java.util.stream.IntStream;

public class Saxpy {

    public static void saxpy(float alpha, float[] x, float[] y) {
        for (int i = 0; i < y.length; i++) {
            y[i] = alpha * x[i];
        }
    }

    public static void main(String[] args) {
        int numElements = 512;
	int counter = 0;

        if (args.length > 0) {
            numElements = Integer.parseInt(args[0]);
        }

        final float alpha = 2f;

        final float[] x = new float[numElements];
        final float[] y = new float[numElements];

        IntStream.range(0, numElements).parallel().forEach(i -> x[i] = 450);

	do {
        	saxpy(alpha, x, y);
	} while (++counter < 5000);

        boolean wrongResult = false;
        for (int i = 0; i < y.length; i++) {
            if (Math.abs(y[i] - (alpha * x[i])) > 0.01) {
                wrongResult = true;
                break;
            }
        }
        if (!wrongResult) {
            System.out.println("Success");
        } else {
            System.out.println("Fail");
        }
    }

}

