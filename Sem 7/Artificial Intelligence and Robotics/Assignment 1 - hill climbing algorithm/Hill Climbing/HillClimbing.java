package com.hillClimbing;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.StringTokenizer;

public class HillClimbing {
	
	public static void main(String[] args) {
//		Scanner sc = new Scanner(System.in);
//		System.out.println("Enter the number of vertices");
//		int numberOfVertices = sc.nextInt();
//		
//		int graph[][] = new int[numberOfVertices + 1][numberOfVertices + 1];
//		int heuristicFunction[] = new int[numberOfVertices + 1];
//					
//		System.out.println("Enter the edges");
//		int startNode = -1, endNode = -1;
//		
//		while(startNode != 0 && endNode != 0) {
//			startNode = sc.nextInt();
//			endNode = sc.nextInt();
//			graph[startNode][endNode] = 1;
//		}
//			
//		System.out.println("Enter the start node and goal node");
//		startNode = sc.nextInt();
//		endNode = sc.nextInt();
//		
//		System.out.println("Enter the Heuristic value of each node");
//		for(int i = 1; i < heuristicFunction.length; i++) {
//			heuristicFunction[i] = sc.nextInt();
//		}
//		
//		int currentNode = startNode;
//		ArrayList<Pair> openList = new ArrayList<Pair>();
//		ArrayList<Integer> closeList = new ArrayList<Integer>();
//		
//		closeList.add(currentNode);
//		while(currentNode != endNode) {
//			for(int i = 1; i < numberOfVertices + 1; i++) {
//				if(graph[currentNode][i] == 1) {
//					openList.add(new Pair(i, heuristicFunction[i]));
//				}
//			}
//			
//			openList.sort(new Comparator<Pair>() {
//				@Override
//				public int compare(Pair pair1, Pair pair2) {
//					return pair1.getHeuristicValue().compareTo(pair2.getHeuristicValue());
//				}
//			});
//			
//			if(openList.get(0).getHeuristicValue() < heuristicFunction[currentNode]) {
//				currentNode = openList.get(0).getNodeNumber();
//				openList.clear();
//				closeList.add(currentNode);
//			}
//			else {
//				break;
//			}
//		}
//		
//		boolean localMaxima = false;
//		System.out.println("Traced the path...");
//		for(int i = 0; i < closeList.size(); i++) {
//			System.out.print(closeList.get(i) + " -> ");
//			if(i == closeList.size() - 1 && closeList.get(i) != endNode) {
//				localMaxima = true;
//			}
//		}
//		
//		if(localMaxima) {
//			System.out.println("and stuck on Local Maxima");
//		}
//		else {
//			System.out.println("and reached the Goal Node");
//		}
		
//		--------------------------------------------------------------------------------------------------
		try {
			File file = new File("src/com/hillClimbing/input_hill_climbing.txt");
			Scanner sc1 = new Scanner(file);
			
			System.out.println("Enter the number of vertices");
			int numberOfVertices = new Integer(sc1.nextLine());
			System.out.println(numberOfVertices);
			
			int graph[][] = new int[numberOfVertices + 1][numberOfVertices + 1];
			int heuristicFunction[] = new int[numberOfVertices + 1];
						
			System.out.println("Enter the edges");
			int startNode = -1, endNode = -1;
			
			while(startNode != 0 && endNode != 0) {
				StringTokenizer tokenizer = new StringTokenizer(sc1.nextLine(), " ");
				startNode = new Integer(tokenizer.nextToken());
				endNode = new Integer(tokenizer.nextToken());
				System.out.println(startNode + " " + endNode);
				graph[startNode][endNode] = 1;
			}
			
			StringTokenizer tokenizer = new StringTokenizer(sc1.nextLine(), " ");
			System.out.println("Enter the start node and goal node");
			startNode = new Integer(tokenizer.nextToken());
			endNode = new Integer(tokenizer.nextToken());
			System.out.println(startNode + " " + endNode);
			
			tokenizer = new StringTokenizer(sc1.nextLine(), " ");
			System.out.println("Enter the Heuristic value of each node");
			for(int i = 1; i < heuristicFunction.length; i++) {
				heuristicFunction[i] = new Integer(tokenizer.nextToken());
				System.out.print(heuristicFunction[i] + " ");
			}
			System.out.println();
			
			int currentNode = startNode;
			ArrayList<Pair> openList = new ArrayList<Pair>();
			ArrayList<Integer> closeList = new ArrayList<Integer>();
			
			closeList.add(currentNode);
			while(currentNode != endNode) {
				for(int i = 1; i < numberOfVertices + 1; i++) {
					if(graph[currentNode][i] == 1) {
						openList.add(new Pair(i, heuristicFunction[i]));
					}
				}
				
				openList.sort(new Comparator<Pair>() {
					@Override
					public int compare(Pair pair1, Pair pair2) {
						return pair1.getHeuristicValue().compareTo(pair2.getHeuristicValue());
					}
				});
				
				if(openList.get(0).getHeuristicValue() < heuristicFunction[currentNode]) {
					currentNode = openList.get(0).getNodeNumber();
					openList.clear();
					closeList.add(currentNode);
				}
				else {
					break;
				}
			}
			
			boolean localMaxima = false;
			System.out.println("Traced the path...");
			for(int i = 0; i < closeList.size(); i++) {
				System.out.print(closeList.get(i) + " -> ");
				if(i == closeList.size() - 1 && closeList.get(i) != endNode) {
					localMaxima = true;
				}
			}
			
			if(localMaxima) {
				System.out.println("and stuck on Local Maxima");
			}
			else {
				System.out.println("and reached the Goal Node");
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}		
	}
}
