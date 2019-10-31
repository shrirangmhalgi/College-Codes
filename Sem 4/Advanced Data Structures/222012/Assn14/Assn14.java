package ads.assignments.servers;

import java.util.LinkedList;
import java.util.Stack;
import java.util.Vector;

public class Assignment14CollectionUtilities {

	public static void main(String[] args) {
		System.out.println("----------STACK DEMONSTRATION----------");
		Stack<Integer> sObj = new Stack<Integer>();
		System.out.println("ADDING ELEMENTS TO THE STACK :");
		for(int i = 0; i < 20; i++)
			sObj.push(i);
		System.out.println("REMOVING AND DISPLAYING THE ELEMENTS OF THE STACK \n");
		int temp;
		for(int i = 0; i < 20; i++){
			temp = sObj.pop();
			System.out.print(temp +"\t");
		}	
		
		System.out.println("\n----------LINKED LIST DEMONSTRATION----------");
		LinkedList<Integer> lObj = new LinkedList<Integer>();
		System.out.println("ADDING ELEMENTS TO THE LINKED LIST :");
		for(int i = 0; i < 20; i++)
			lObj.add(i); //already increments the ptr

		System.out.println("REMOVING AND DISPLAYING THE ELEMENTS OF THE LINKED LIST \n");
		for(int i = 0; i < 20; i++){
			temp = lObj.remove(); //already increments the ptr
			System.out.print(temp +"\t");
		}	
		
		Vector<Integer> vObj = new Vector<Integer>();
		System.out.println("\nADDING ELEMENTS TO THE QUEUE :");
		for(int i = 0; i < 10; i++)
			vObj.add(i);
		System.out.println("REMOVING AND DISPLAYING THE ELEMENTS OF THE QUEUE \n");
		for(int i = 0; i < 10; i++){
			temp = vObj.remove(i);
			System.out.print(temp +"\t");
		}
	}
}
 
