import java.util.Scanner;

class Number{
	public native int[] firstNative(int array);
	public native int secondNative(int[] result);
	
	public static void main(String[] args){
		Number Number = new Number();
		
		Scanner scanner = new Scanner(System.in);
		System.out.println("Please enter one number to determine the size of an array: ");
		int input = scanner.nextInt();
		
		int []arraySize = Number.firstNative(input);
		System.out.println("The difference of min and max number is: "+ Number.secondNative(arraySize));
	}
	
	static{
		System.loadLibrary("CNumber");
	}
}