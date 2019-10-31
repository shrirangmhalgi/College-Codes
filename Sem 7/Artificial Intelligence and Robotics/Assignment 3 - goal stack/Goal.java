package com.goalStack;

import java.util.ArrayList;

class Goal
{
	ArrayList<Predicate> goalList;
	Operator op;
	int flag; //1. Compound 2.Single 3.Operator
	Goal(ArrayList<Predicate> goalList)
	{
		this.goalList = goalList;
		this.op = null;
		if(goalList.size() == 1)
		{
			flag = 2;
		}
		else
			flag = 1;
	}
	Goal(Operator op)
	{
		this.goalList = null;
		this.op = op;
		flag = 3;
	}
}
