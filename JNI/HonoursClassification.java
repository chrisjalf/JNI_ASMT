class HonoursClassification { 
	public native void calculateDiploma(); 
	public native void calculateDegree();
	
	static   { 
		System.loadLibrary(""); 
    }
    
    public static void main(String[] args) { 
		HonoursClassification hc = new HonoursClassification();
    } 
} 