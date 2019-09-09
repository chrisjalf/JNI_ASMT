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
		
		do{	// loop if invalid entered, can be stopped with either correct input or through exit
			System.out.print("Please enter a valid size for the array, otherwise enter 0 to exit: ");
			if(input.hasNextInt()) {	// if input is integer, then proceed normally
				arrSize = input.nextInt();
				
				if(arrSize == 0){	// 0 to break loop and exit
					break;
				}
				
				arrRandNum = amm.displayResult(arrSize);	// pass array size and receive back array with integers inside
				System.out.println("\nDifference of max and min number: " + amm.displayDifference(arrRandNum));
			}
			else{	// else set size negative (for invalid input looping) and move next line to prevent endless looping
				arrSize = -1;
				input.nextLine();
			}
		}while(arrSize < 0);
    } 
} 