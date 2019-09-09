import java.util.*;
class HonoursClassification { 
/**/	public native void calculateDiploma(); 
	public native void calculateDegree();
	
	static { 
		System.loadLibrary("CHonoursClassification"); 
    }
    
    public static void main(String[] args) { 
		Scanner input = new Scanner(System.in);
		HonoursClassification hc = new HonoursClassification();
		String choice;
		
		System.out.println("---------------------------------------------");
		System.out.println("|   Classification of Honours               |");
		System.out.println("|-------------------------------------------|");
		System.out.println("|   Please select a programme               |");
		System.out.println("|   Enter dip to select Diploma Programme   |");
		System.out.println("|   Enter deg to select Degree Programme    |");
		System.out.println("---------------------------------------------\n");
		
		System.out.print(">");
		
		// convert user input to lower case for comparing
		choice = input.nextLine().toLowerCase();
		
		// loop when invalid input is entered, continues until the input is valid or exit
		while(choice.compareTo("dip") != 0 && choice.compareTo("deg") != 0){
			System.out.println("\nPlease enter a valid code to select a programme, otherwise enter no to exit");
			choice = input.nextLine().toLowerCase();
			
			if(choice.compareTo("no") == 0){
				break;
			}
		}
		
		/**/if(choice.compareTo("dip") == 0){
			hc.calculateDiploma();
		}
		else if(choice.compareTo("deg") == 0){
			hc.calculateDegree();
		}
		
    } 
} 