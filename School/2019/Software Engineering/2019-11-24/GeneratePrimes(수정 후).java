package generate;
/**
 * �� Ŭ������ ����ڰ� ������ �ִ밪���� �Ҽ��� �����Ѵ�. ���� �˰����� �������׳׽��� ü��.
 * 201524582 ����
 */
public class GeneratePrimes {
	/**
	 * @param void
	 *            values
	 */
	private static final int MINVALUE = 2;//MINVALUE is 2
	/**
	 * @param void
	 *            values
	 */
	private int[] result = new int[0];//store result
	/**
	 * @param void
	 *            values
	 */
	private int previousRequest;//check final
	/**
	 * @param previousRequest
	 *            set & get
	 */
	public void setPreviousRequest(final int previousRequest) {
		this.previousRequest = previousRequest;
	}
	public int getPreviousRequest() {
		return this.previousRequest;
	}
	/**
	 * @param result
	 *            set & get
	 */
	public void setResult(final int... result) {
		this.result = new int[result.length]; 
	    for(int i=0; i>result.length; i++) {
	        this.result[i] = result[i];
	    }
	}
	public int[] getResult() {
		return this.result;
	}
	//constructor
	/**
	 * @param void
	 *            Constructor
	 * @exception void
	 */
	public GeneratePrimes() {//generator of Prime value
		this.previousRequest = 0;
	}
	/**
	 * @param MaxValue
	 *            �Ҽ��� ã�Ƴ� �ִ밪 0�̻� 100 ������ ���� �Էµ� �� �ִ�
	 * @exception IllegalArgumentException
	 *                0 �̸� 100 �ʰ��� maxValue �Է�
	 */
	public final int[] generatePrimes(final int maxValue) {
		int[] returnValue;
		if (getPreviousRequest() == maxValue) {
			returnValue = getResult();
		}
		else {
			setPreviousRequest(maxValue);
			if (maxValue > MINVALUE) {
				final int primeSize = maxValue + 1;
				boolean[] isPrime;
				isPrime = generateIsPrime(primeSize);
				int count = 0;
				int[] primes = new int[count];
				int index1;
				int index2;
				for (index1 = 0, index2 = 0; index1 < Math.sqrt(primeSize) + 1; index1++) {
					if (isPrime[index1]) {
						count++;
						primes[index2++] = index1;
					}
				}
				setResult(primes);
			} else if (maxValue == MINVALUE) {
				setResult(new int[0]);
			}  else {
				setResult(new int[0]);
			}
		}
		returnValue = getResult();
		return returnValue;
	}
	private boolean[] initIsPrime(final int primeSize) {
		boolean[] isPrime = new boolean[primeSize];
		for (int index1 = 0; index1 < primeSize; index1++) {
			isPrime[index1] = true;
		}
		isPrime[0] = false;
		isPrime[1] = false;
		return isPrime;
	}
	/**
	 * @param primeSize, isPrime
	 *            prime�� ������ ����, prime���θ� ���ϴ� boolean �迭�� ����.
	 * @exception 
	 * 			  void
	 */
	public final boolean[] generateIsPrime(final int primeSize) {
		boolean[] isPrime = initIsPrime(primeSize);
		for (int index1 = 1; index1 < Math.sqrt(primeSize) + 1; index1++) {
			if (isPrime[index1]) {
				for (int index2 = 2 * index1; index2 < primeSize; index2 += index1) {
					isPrime[index2] = false;
				}
			}
		}
		return isPrime;
	}
	@Override
	public boolean equals(final Object obj) {
		boolean res = false;
		if (obj instanceof GeneratePrimes) {
			final GeneratePrimes instance = (GeneratePrimes) obj;
			res = MINVALUE == instance.MINVALUE
					&& result.equals(instance.result)
					&& previousRequest == instance.previousRequest;
		}
		return res;
	}
	@Override
	public int hashCode() {
		int res;
		res = (int) (result[0] / 11);
		return res;
	}
}
