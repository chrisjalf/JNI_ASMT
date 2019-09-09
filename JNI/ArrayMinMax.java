import java.util.*;
class ArrayMinMax { 
	public native int [] displayResult(int arrSize); 
	public native int displayDifference(int [] arrRN);
	
	static { 
		System.loadLibrary("CArrayMinMax"); 
    }
    
    public static void main(String[] args) { 
		Scanner input = new Scanner(System.in);
		ArrayMinMax amm = new ArrayMinMax();
		int arrSize = 0;
		int [] arrRandNum;
		
		do{
			System.out.print("Please enter a valid size for the array, otherwise enter 0 to exit: ");
			if(input.hasNextInt()) {
				arrSize = input.nextInt();
				
				if(arrSize == 0){
					break;
				}
				
				arrRandNum = amm.displayResult(arrSize);
				System.out.println("\nDifference of max and min number: " + amm.displayDifference(arrRandNum));
			}
			else{
				arrSize = -1;
				input.nextLine();
			}
		}while(arrSize < 0);
    } 
} 