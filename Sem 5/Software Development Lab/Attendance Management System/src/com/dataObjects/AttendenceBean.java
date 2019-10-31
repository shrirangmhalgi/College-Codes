package com.dataObjects;

import java.io.Serializable;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;

import com.enumerations.Months;

public class AttendenceBean implements Serializable{
	String grNo;
	Dictionary<String, Integer> monthlyAttendence = new Hashtable<>(12);
	
	public AttendenceBean() {
		Months months[] = Months.values();
		for(Months month : months) {
			monthlyAttendence.put(month.toString(), 0); //initial attendance is 0 for every month
		}
	}
	
	public AttendenceBean(String grNo, Dictionary<String, Integer> monthlyAttendance) {
		this.grNo = grNo;
		this.monthlyAttendence = monthlyAttendance;
	}

	public String getGrNo() {
		return grNo;
	}

	public Dictionary<String, Integer> getTable() {
		return monthlyAttendence;
	}

	public void setGrNo(String grNo) {
		this.grNo = grNo;
	}

	public void setTable(Dictionary<String, Integer> monthlyAttendence) {
		this.monthlyAttendence = monthlyAttendence;
	}
	
	
}
