import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		double total=0;
		double sum=0;
		double tmp;
		String gd = new String();
		String ob = new String();
		for(int i=0;i<20;i++) {
			ob = scanner.next();
			tmp = scanner.nextDouble();
			gd = scanner.next();
			if(gd.equals("P")) {
				continue;
			}
			total += tmp;
			switch (gd) {
			case "A+": {
				sum += tmp * 4.5;
				break;
			}
			case "A0": {

				sum += tmp * 4.0;
				break;
			}
			case "B+": {

				sum += tmp * 3.5;
				break;
			}
			case "B0": {

				sum += tmp * 3.0;
				break;
			}
			case "C+": {

				sum += tmp * 2.5;
				break;
			}
			case "C0": {

				sum += tmp * 2.0;
				break;
			}
			case "D+": {

				sum += tmp * 1.5;
				break;
			}
			case "D0": {

				sum += tmp * 1.0;
				break;
			}
			default:{//F학점
				break;
			}
			}
		}
		System.out.println(sum/total);




	}
}
