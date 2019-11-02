package com.aStar;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Astar {
	public static void main(String[] args) {
//		Scanner sc = new Scanner(System.in);
//		
//		System.out.println("Enter the number of vertices");
//		Integer numberOfVertices = sc.nextInt();
//		
//		Integer graph[][] = new Integer[numberOfVertices + 1][numberOfVertices + 1];
//		Integer heuristicFunction[] = new Integer[numberOfVertices + 1];
//		
//		System.out.println("Enter the edges (start, end, cost)");
//		Integer startNode = -1, endNode = -1, edgeCost = -1;
//		while(startNode != 0 && endNode != 0 && edgeCost != 0) {
//			startNode = sc.nextInt();
//			endNode = sc.nextInt();
//			edgeCost = sc.nextInt();
//			graph[startNode][endNode] = edgeCost;
//		}
//		
//		System.out.println("Enter the start node and goal node");
//		startNode = sc.nextInt();
//		endNode = sc.nextInt();
//		
//		System.out.println("Enter the heuristic value of each node");
//		for(int i = 1; i < heuristicFunction.length; i++) {
//			heuristicFunction[i] = sc.nextInt();
//		}
//		
//		int currentNode = startNode, parentNode, g = 0;
//		Map<Integer, Integer> closedList = new HashMap<Integer, Integer>();
//		ArrayList<Node> openList = new ArrayList<Node>();
//		Node node = new Node(currentNode, currentNode, 0, g);
//		node.setValue(heuristicFunction[currentNode] + g);
//		openList.add(node);
//		
//		while(currentNode != endNode) {
//			openList.sort(new Comparator<Node>() {
//
//				@Override
//				public int compare(Node node1, Node node2) {
//					return node1.getValue().compareTo(node2.getValue());
//				}
//				
//			});
//			
//			node = openList.get(0);
//			openList.remove(0);
//			currentNode = node.getVertex();
//			parentNode = node.getParent();
//			g = node.getG();
//			
//			for(int i = 1; i <= numberOfVertices; i++) {
//				try {
//					if(graph[currentNode][i] != 0 && closedList.get(i) == null) {
//						node.setVertex(i);
//						node.setParent(currentNode);
//						node.setG(g + graph[currentNode][i]);
//						node.setValue(node.getG() + heuristicFunction[i]);
//						openList.add(node);
//					}
//				}
//				catch (NullPointerException e) {
//					
//				}
//			}
//			
//			closedList.put(currentNode, parentNode);	
//		}
//		
//		System.out.println("Traced the path");
//		int totalCost = 0;
//		while(currentNode != startNode) {
//			System.out.print(currentNode + " <- ");
//			totalCost += graph[closedList.get(currentNode)][currentNode];
//			currentNode = closedList.get(currentNode);
//		}
//		System.out.println(currentNode);
//		System.out.println("with total cost = " + totalCost);

//-----------------------------------------------------------------------------------------
		try {
			File file = new File("src/com/aStar/input_Astar.txt");
			Scanner sc1 = new Scanner(file);
			
			System.out.println("Enter the number of vertices");
			int numberOfVertices = new Integer(sc1.nextLine());
			System.out.println(numberOfVertices);
			
			int graph[][] = new int[numberOfVertices + 1][numberOfVertices + 1];
			int heuristicFunction[] = new int[numberOfVertices + 1];
						
			System.out.println("Enter the edges (start, end, cost)");
			Integer startNode = -1, endNode = -1, edgeCost = -1;
			
			while(startNode != 0 && endNode != 0 && edgeCost != 0) {
				StringTokenizer tokenizer = new StringTokenizer(sc1.nextLine(), " ");
				startNode = new Integer(tokenizer.nextToken());
				endNode = new Integer(tokenizer.nextToken());
				edgeCost = new Integer(tokenizer.nextToken());
				System.out.println(startNode + " " + endNode + " " + edgeCost);
				graph[startNode][endNode] = edgeCost;
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
			
			int currentNode = startNode, parentNode, g = 0;
			Map<Integer, Integer> closedList = new HashMap<Integer, Integer>();
			ArrayList<Node> openList = new ArrayList<Node>();
			Node node = new Node(currentNode, currentNode, 0, g);
			node.setValue(heuristicFunction[currentNode] + g);
			openList.add(node);
			
			while(currentNode != endNode) {
				openList.sort(new Comparator<Node>() {
	
					@Override
					public int compare(Node node1, Node node2) {
						return node1.getValue().compareTo(node2.getValue());
					}
					
				});
				
				node = openList.get(0);
				openList.remove(0);
				currentNode = node.getVertex();
				parentNode = node.getParent();
				g = node.getG();
				
				for(int i = 1; i <= numberOfVertices; i++) {
					try {
						if(graph[currentNode][i] != 0 && closedList.get(i) == null) {
							node.setVertex(i);
							node.setParent(currentNode);
							node.setG(g + graph[currentNode][i]);
							node.setValue(node.getG() + heuristicFunction[i]);
							openList.add(node);
						}
					}
					catch (NullPointerException e) {
						
					}
				}
				
				closedList.put(currentNode, parentNode);	
			}
			
			System.out.println("Traced the path");
			int totalCost = 0;
			while(currentNode != startNode) {
				System.out.print(currentNode + " <- ");
				totalCost += graph[closedList.get(currentNode)][currentNode];
				currentNode = closedList.get(currentNode);
			}
			System.out.println(currentNode);
			System.out.println("with total cost = " + totalCost);
		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}
