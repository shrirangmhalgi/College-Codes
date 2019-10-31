public class MutualExclusion {
    
    
    
    public static void main(String[] args){
        //Defining an array of ports from which processes will send messages, in which case all receive messages, including the process itself.
        int[] portArray = {50000, 50001, 50002}; 
        try {
            //Process Class implements the Runnable interface that is used to create a thread.
            Runnable p1 = new Process(1,2, 50000, portArray);
            new Thread(p1).start();
            
            Runnable p2 = new Process(2,3, 50001, portArray, 0);
            new Thread(p2).start();
            
            Runnable p3 = new Process(3,5, 50002, null);
            new Thread(p3).start();
            
            
        }catch(Exception ex){
            System.out.print(ex.getMessage());
        }        
    }
    
}
