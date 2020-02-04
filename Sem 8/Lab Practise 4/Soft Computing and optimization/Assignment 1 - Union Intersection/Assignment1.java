package com.assignment1;

import java.io.ObjectInputStream.GetField;
import java.util.List;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

public class Assignment1 {
        public static void main(String[] args) {
                List<FuzzyClass> listA = new LinkedList<FuzzyClass>();
                List<FuzzyClass> listB = new LinkedList<FuzzyClass>();

                Scanner sc = new Scanner(System.in);
                Scanner sc1 = new Scanner(System.in);

                System.out.println("Enter the elements of List A");
                while(true){
                        System.out.println("Enter the name of the element. (-1 to exit)");
                        String element = sc.nextLine();

                        if(element.equals("-1")){
                                break;
                        }

                        System.out.println("Enter the member function of the element for 1st list.");
                        Float memberFunctionA = sc1.nextFloat();
                        FuzzyClass fuzzyElementA = new FuzzyClass(memberFunctionA, element);
                        listA.add(fuzzyElementA);

                        System.out.println("Enter the member function of the element for 2nd list.");
                        Float memberFunctionB = sc1.nextFloat();
                        FuzzyClass fuzzyElementB = new FuzzyClass(memberFunctionB, element);
                        listB.add(fuzzyElementB);
                }

                List<FuzzyClass> resultList = new LinkedList<FuzzyClass>();

                System.out.println("List 1 is");
                display(listA);

                System.out.println();
                System.out.println("List 2 is");
                display(listB);

                System.out.println();
                System.out.println("The Union of List 1 u List 2 is");
                resultList = getUnion(listA, listB);
                display(resultList);

                System.out.println();
                System.out.println("The Intersection of List 1 n List 2 is");
                resultList = getIntersection(listA, listB);
                display(resultList);

                System.out.println();
                System.out.println("The Complement of List 1 is");
                resultList = getCompliment(listA);
                display(resultList);

                System.out.println();
                System.out.println("The Complement of List 2 is");
                resultList = getCompliment(listB);
                display(resultList);

                System.out.println();
                System.out.println("The Diffrence of List 1 - List 2 is");
                resultList = getIntersection(listA, getCompliment(listB));
                display(resultList);

                System.out.println();
                System.out.println("The product of List 1 * List 2 is");
                resultList = getVectorProduct(listA, listB);
                display(resultList);

                System.out.println();
                System.out.println("The cartesian product of List 1 x List 2 is");
                displayCartesianProduct(listA, listB);
        }

        private static void displayCartesianProduct(List<FuzzyClass> listA, List<FuzzyClass> listB) {
        	for(int i = 0; i < listA.size(); i++) {
        		for(int j = 0; j < listB.size(); j++) {
        			float min = -1.0f;
        			if(listA.get(i).getMemberFunction() < listB.get(j).getMemberFunction()) {
        				min = listA.get(i).getMemberFunction();
        			}
        			else {
        				min = listB.get(j).getMemberFunction();
        			}
        			System.out.print(min + " ");
        		}
        		System.out.println();
        	}
        }

        private static List<FuzzyClass> getVectorProduct(List<FuzzyClass> listA, List<FuzzyClass> listB) {
                List<FuzzyClass> result = new LinkedList<FuzzyClass>();

                for(int i = 0; i < listA.size(); i++){
                        result.add(new FuzzyClass((listA.get(i).getMemberFunction() * listB.get(i).getMemberFunction()), listA.get(i).getName()));
                }

                return result;
        }

        public static void display(List<FuzzyClass> resultList) {
                System.out.print("{ ");
                for(int i = 0; i < resultList.size(); i++){                     
                        if(i == resultList.size() - 1){
                                System.out.print("(" + resultList.get(i).getName() + ", " + (resultList.get(i).getMemberFunction()) + ") ");
                        }
                        else{
                                System.out.print("(" + resultList.get(i).getName() + ", " + (resultList.get(i).getMemberFunction()) + "), ");
                        }
                }
                System.out.print("} ");

        }

        public static List<FuzzyClass> getCompliment(List<FuzzyClass> listA) {
                List<FuzzyClass> result = new LinkedList<FuzzyClass>();

                for(int i = 0; i < listA.size(); i++){
                        result.add(new FuzzyClass(1 - listA.get(i).getMemberFunction(), listA.get(i).getName()));
                }

                return result;
        }

        public static List<FuzzyClass> getIntersection(List<FuzzyClass> listA, List<FuzzyClass> listB) {
                List<FuzzyClass> result = new LinkedList<FuzzyClass>();

                for(int i = 0; i < listA.size(); i++){
                        Float min = 0.0f;
                        if(listA.get(i).getMemberFunction() < listB.get(i).getMemberFunction()){
                                min = listA.get(i).getMemberFunction();
                        }
                        else{
                                min = listB.get(i).getMemberFunction();
                        }

                        result.add(new FuzzyClass(min, listA.get(i).getName()));

                }

                return result;
        }

        public static List<FuzzyClass> getUnion(List<FuzzyClass> listA, List<FuzzyClass> listB) {
                List<FuzzyClass> result = new LinkedList<FuzzyClass>();

                for(int i = 0; i < listA.size(); i++){
                        Float max = -1.0f;
                        if(listA.get(i).getMemberFunction() > listB.get(i).getMemberFunction()){
                                max = listA.get(i).getMemberFunction();
                        }
                        else{
                                max = listB.get(i).getMemberFunction();
                        }

                        result.add(new FuzzyClass(max, listA.get(i).getName()));
                }

                return result;
        }
}