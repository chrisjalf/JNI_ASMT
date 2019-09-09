import java.util.*;
class ArrayMinMax { 
	public native void displayResult(int arrSize); 
	public native void displayDifference();
	
	static { 
		System.loadLibrary("CArrayMinMax"); 
    }
    
    public static void main(String[] args) { 
		Scanner input = new Scanner(System.in);
		ArrayMinMax amm = new ArrayMinMax();
		int arrSize = 0;
		
		do{
			System.out.print("Please enter a valid size for the array, otherwise enter 0 to exit: ");
			if(input.hasNextInt()) {
				arrSize = input.nextInt();
			}
			else{
				arrSize = -1;
				input.nextLine();
			}
			
			if(arrSize == 0){
				break;
			}
		}while(arrSize < 0);
		
		amm.displayResult(arrSize);
    } 
} 