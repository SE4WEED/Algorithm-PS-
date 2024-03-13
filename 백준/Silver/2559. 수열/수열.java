import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int N, k;
		N = scanner.nextInt();
		k = scanner.nextInt();
		int tmp;
		ArrayList<Integer> al = new ArrayList<>();
		for(int i=0;i<N;i++) {
			tmp = scanner.nextInt();
			al.add(tmp);
		}
		int max;
		int now=0;
		for(int i=0;i<k;i++) {
			now += al.get(i);
		}
		max = now;
		for(int i=k;i<N;i++) {
			now -= al.get(i-k);
			now += al.get(i);
			max = Math.max(max,now);
		}
		System.out.println(max);
		scanner.close();
	}
}
