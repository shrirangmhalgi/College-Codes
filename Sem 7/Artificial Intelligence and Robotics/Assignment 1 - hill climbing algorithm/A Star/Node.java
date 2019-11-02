package com.aStar;

public class Node {
	private Integer vertex;
	private Integer value;
	private Integer parent;
	private Integer g;
	
	public Node(Integer vertex, Integer parent, Integer value, Integer g) {
		this.vertex = vertex;
		this.parent = parent;
		this.value = value;
		this.g = g;
	}
	
	public Integer getVertex() {
		return vertex;
	}
	
	public void setVertex(Integer vertex) {
		this.vertex = vertex;
	}
	
	public Integer getValue() {
		return value;
	}
	
	public void setValue(Integer value) {
		this.value = value;
	}
	
	public Integer getParent() {
		return parent;
	}
	
	public void setParent(Integer parent) {
		this.parent = parent;
	}
	
	public Integer getG() {
		return g;
	}
	
	public void setG(Integer g) {
		this.g = g;
	}
}
