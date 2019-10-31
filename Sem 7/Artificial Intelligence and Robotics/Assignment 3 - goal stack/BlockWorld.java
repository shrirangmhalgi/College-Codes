package com.goalStack;

import java.util.*;
import java.io.*;

class BlockWorld
{
	static ArrayList<ArrayList<Block>> start;
	static ArrayList<ArrayList<Block>> goal;

	static ArrayList<Predicate> getStatePredicates(ArrayList<ArrayList<Block>> initial_state, int n)
	{
		ArrayList<Predicate> initial = new ArrayList<Predicate>();
		for(int i=0;i<n;i++)
		{
			ArrayList<Block> al = initial_state.get(i);
			if(al.size() == 1)
			{
				Block curr = (Block)al.get(0);
				initial.add(new Predicate(2,curr));
				initial.add(new Predicate(3,curr));
			}
			else
			{
				for(int j=0;j<al.size()-1;j++)
				{
					Block curr = (Block)al.get(j);
					Block next = (Block)al.get(j+1);
					if(j==0)
						initial.add(new Predicate(2,curr));
					initial.add(new Predicate(1,next,curr));
					if(j==al.size()-2)
					{
						initial.add(new Predicate(3,next));
					}
				}
			}
		}
		initial.add(new Predicate(5));
		return initial;
	}

	public static void main(String args[])throws IOException
	{
		start = new ArrayList<ArrayList<Block>>();
		goal = new ArrayList<ArrayList<Block>>();

		//Start state
		System.out.println("Welcome to the Block World Problem. The planning follows the STRIPS Goal-Stacking to solve the problem");
		System.out.println("Please enter the number of different block stacks in the start state");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n<=0)
		{
			System.out.println("Enter positive number");
			n = sc.nextInt();
		}
		for(int i=0;i<n;i++)
			start.add(new ArrayList<Block>());
		System.out.println("Please enter the block stacked upon each other without spaces, and separate two block stacks using space or new line");
		int numStacks = 0;
		while(numStacks < n)
		{
			String str = sc.next().trim();
			for(int i=0;i< str.length();i++)
				start.get(numStacks).add(new Block(str.charAt(i)));
			numStacks++;
		}

		//Goal state
		System.out.println("Please enter the number of different block stacks in the goal state");
		int p = sc.nextInt();
		while(p<=0)
		{
			System.out.println("Enter positive number");
			p = sc.nextInt();
		}
		for(int i=0;i<p;i++)
			goal.add(new ArrayList<Block>());
		System.out.println("Please enter the block stacked upon each other without spaces, and separate two block stacks using space or new line");
		numStacks = 0;
		while(numStacks < p)
		{
			String str = sc.next().trim();
			for(int i=0;i<str.length();i++)
				goal.get(numStacks).add(new Block(str.charAt(i)));
			numStacks++;
		}
		ArrayList<Predicate> start_stack = getStatePredicates(start,n);
		ArrayList<Predicate> goal_stack = getStatePredicates(goal,p);

		ArrayList<Goal> main_stack= new ArrayList<Goal>();
		main_stack.add(new Goal(goal_stack));

		ArrayList<Operator> op = new ArrayList<Operator>();
		int count =0;
		while(main_stack.size()!=0)
		{
			Goal curr_goal = main_stack.get(main_stack.size()-1);
			if(curr_goal.flag == 1) // compound goal
			{
				ArrayList<Predicate> compound = (Arraylist<Predicate>curr).goalList;
				if(start_stack.containsAll(compound))
					main_stack.remove(main_stack.size()-1);
				else
				{
					for(int i=0;i<compound.size();i++)
					{
						Predicate curr_pred = (Predicate)compound.get(i);
						if(!start_stack.contains(curr_pred))
						{
							ArrayList<Predicate> al = new ArrayList<Predicate>();
							al.add(curr_pred);
							main_stack.add(new Goal(al));
						}
					}
				}
			}
			else if(curr_goal.flag == 2)
			{
				ArrayList<Predicate> single = (ArrayList<Predicate>)curr.goalList;
				Predicate singlePred = single.get(0);
				if(start_stack.contains(singlePred))
					main_stack.remove(main_stack.size()-1);
				else
				{

				}
			}
		}

	}
}
