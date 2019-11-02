package com.hillClimbing;

public class Pair {
	private Integer nodeNumber;
	private Integer heuristicValue;
	
	public Pair(Integer nodeNumber, Integer heuristicValue) {
		this.nodeNumber = nodeNumber;
		this.heuristicValue = heuristicValue;
	}
	
	public Integer getNodeNumber() {
		return nodeNumber;
	}
	
	public void setNodeNumber(Integer nodeNumber) {
		this.nodeNumber = nodeNumber;
	}
	
	public Integer getHeuristicValue() {
		return heuristicValue;
	}
	
	public void setHeuristicValue(Integer heuristicValue) {
		this.heuristicValue = heuristicValue;
	}	
}
