package com.bestFirstSearch;

public class Node {
	private Integer vertex;
	private Integer parent;
	private Integer value;
	
	public Node(Integer vertex, Integer parent, Integer value) {
		this.vertex = vertex;
		this.parent = parent;
		this.value = value;
	}
	
	public Integer getVertex() {
		return vertex;
	}
	
	public void setVertex(Integer vertex) {
		this.vertex = vertex;
	}
	
	public Integer getParent() {
		return parent;
	}
	
	public void setParent(Integer parent) {
		this.parent = parent;
	}
	
	public Integer getValue() {
		return value;
	}
	
	public void setValue(Integer value) {
		this.value = value;
	}
}
