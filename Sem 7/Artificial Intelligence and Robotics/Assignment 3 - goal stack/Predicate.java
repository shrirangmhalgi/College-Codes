package com.goalStack;

class Predicate
{
	int type_of_predicate; //1.ON(X,Y) 2.ONT(X) 3.CL(X) 4.H(X) 5.AE
	Block b1;
	Block b2;
	
	Predicate()
	{
		this.type_of_predicate = -1;
		b1 = null;
		b2 = null;
	}
	Predicate(int type_of_predicate)
	{
		this.type_of_predicate = type_of_predicate;
		this.b1 = null;
		this.b2 = null;
	}
	Predicate(int type_of_predicate,Block b1)
	{
		this.type_of_predicate = type_of_predicate;
		this.b1 = b1;
		this.b2 = null;
	}
	Predicate(int type_of_predicate,Block b1,Block b2)
	{
		this.type_of_predicate = type_of_predicate;
		this.b1 = b1;
		this.b2 = b2;
	}
	
	public boolean equals(Object obj)
	{
		Predicate other = (Predicate)obj;
		int myPred = other.type_of_predicate;
		
		if(myPred!= this.type_of_predicate)
			return false;
		if(myPred == 1 && (other.b1.getBlock() == this.b1.getBlock()) && (other.b2.getBlock() == this.b2.getBlock()))
			return true;
		if(myPred == 2 && (other.b1.getBlock() == this.b1.getBlock()))
			return true;
		if(myPred == 3 && (other.b1.getBlock() == this.b1.getBlock()))
			return true;
		if(myPred == 4 && (other.b1.getBlock() == this.b1.getBlock()))
			return true;
		if(myPred == 5)
			return true;
		return false;
	}
}
