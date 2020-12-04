import java.util.*;
import java.math.*;

public class code {
	static HashMap<Long, Integer> map = new HashMap(1000000);
	
	static int chainLength(long num) {
		long prev = num;
		int length = 0;
		while (num != 1) {
			Integer mapped = map.get(num);
			if (mapped != null) {
				return length + mapped;
			}
			if (num != 0 && num % 2 == 0) {
				num /= 2;
			} else {
				num = num * 3 + 1;
			}
			length += 1;
		}
		map.put(prev, length);
		return length;
	}
	
	public static void main(String[] args) {
		long longestNum = 0;
		int longestChain = 0;
		
		for (long i = 50; i < 1000000; i++) {
			int length = chainLength(i);
			if (length > longestChain) {
				longestChain = length;
				longestNum = i;
			}
		}
		
		System.out.println("" + longestNum + " (" + longestChain + ")");
	}
}
