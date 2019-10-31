package com.goalStack;

import java.util.ArrayList;

class Operator
{
	int type_of_op; //1.S(X,Y) 2.US(X,Y) 3.PU(X) 4.PD(X)
	Block b1;
	Block b2;
	ArrayList<Predicate> preCond;
	ArrayList<Predicate> addList;
	ArrayList<Predicate> deleteList;
	
	Operator(int type_of_op,Block b1)
	{
		this.type_of_op = type_of_op;
		this.b1 = b1;
		this.b2 = null;
		preCond = new ArrayList<Predicate>();
		addList = new ArrayList<Predicate>();
		deleteList = new ArrayList<Predicate>();
	}
	
	Operator(int type_of_op,Block b1,Block b2)
	{
		this.type_of_op = type_of_op;
		this.b1 = b1;
		this.b2 = b2;
		preCond = new ArrayList<Predicate>();
		addList = new ArrayList<Predicate>();
		deleteList = new ArrayList<Predicate>();
	}
	
	ArrayList<Predicate> getPreCond()
	{
		switch(type_of_op)
		{
			case 1: preCond.add(new Predicate(3,b2));
				preCond.add(new Predicate(4,b1));
				break;
			case 2: preCond.add(new Predicate(1,b1,b2));
				preCond.add(new Predicate(3,b1));
				preCond.add(new Predicate(5));
				break;
			case 3: preCond.add(new Predicate(2,b1));
				preCond.add(new Predicate(3,b1));
				preCond.add(new Predicate(5));
				break;
			case 4: preCond.add(new Predicate(4,b1));
				break;
			default:System.out.println("Wrong operator");
		}
		return preCond;
	}
	ArrayList<Predicate> getAddList()
	{
		switch(type_of_op)
		{
			case 1: addList.add(new Predicate(5));
				addList.add(new Predicate(1,b1,b2));
				addList.add(new Predicate(3,b1));
				break;
			case 2: addList.add(new Predicate(4,b1));
				addList.add(new Predicate(3,b2));
				break;
			case 3: addList.add(new Predicate(4,b1));
				break;
			case 4: addList.add(new Predicate(2,b1));
				addList.add(new Predicate(5));
				addList.add(new Predicate(3,b1));
				break;
			default:System.out.println("Wrong operator");		
		}
		return addList;
	}
	ArrayList<Predicate> getDeleteList()
	{
		switch(type_of_op)
		{
			case 1: deleteList.add(new Predicate(3,b2));
				deleteList.add(new Predicate(4,b1));
				break;
			case 2: deleteList.add(new Predicate(1,b1,b2));
				deleteList.add(new Predicate(5));
				deleteList.add(new Predicate(3,b1));
				break;
			case 3: deleteList.add(new Predicate(2,b1));
				deleteList.add(new Predicate(5));
				deleteList.add(new Predicate(3,b1));
				break;
			case 4: deleteList.add(new Predicate(4,b1));
				break;
			default:System.out.println("Wrong operator");
		}
		return deleteList;
	}
	
}
