
/**
 * �� Ŭ������ ����ڰ� ������ �ִ밪���� �Ҽ��� �����Ѵ�. ���� �˰����� �������׳׽��� ü��.
 * 201524582 ����
 */
public class GeneratePrimes {
	/**
	 * @param MaxValue
	 *            �Ҽ��� ã�Ƴ� �ִ밪 0�̻� 100 ������ ���� �Էµ� �� �ִ�
	 * @exception IllegalArgumentException
	 *                0 �̸� 100 �ʰ��� maxValue �Է�
	 */
	private static int minValue = 2;
	private int[] result = new int[0];
	private int previousRequest = 0;

	public final int[] generatePrimes(final int maxValue) {
		if (previousRequest == maxValue) {
			return result;
		}
		previousRequest = maxValue;
		if (maxValue > minValue) {
			int s = maxValue + 1;
			boolean[] f = new boolean[s];
			int i, j, k;
			short z;
			for (i = 0; i < s; i++) {
				f[i] = true;
			}
			f[0] = false;
			f[1] = false;
			for (i = 1; i < Math.sqrt(s) + 1; i++) {
				if (f[i]) {
					for (j = 2 * i; j < s; j += i) {
						f[j] = false;
					}
				}
			}
			z = (short) (s + 1);
			int count = 0;
			for (i = 0; i < Math.sqrt(s) + 1; i++) {
				if (f[i]) {
					count++;
				}
			}
			int[] primes = new int[count];
			for (i = 0, j = 0; i < Math.sqrt(s) + 1; i++) {
				if (f[i]) {
					primes[j++] = i;
				}
			}
			f = null;
			result = primes;
			return result;
		} else if (maxValue == minValue) {
			result = new int[0];
			return result;
		}  else {
			result = new int[0];
			return result;
		}
	}

	@Override
	final public boolean equals(Object obj) {
		if (obj instanceof GeneratePrimes) {
			GeneratePrimes instance = (GeneratePrimes) obj;
			return minValue == instance.minValue
					&& result.equals(instance.result)
					&& previousRequest == instance.previousRequest;
		}
		return false;
	}
}
