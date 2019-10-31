package com.gui;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;

public class TableData {
	private final SimpleIntegerProperty attendance;
	private final SimpleStringProperty month;
	
	public String getMonth() {
		return month.get();
	}

	public Integer getAttendance() {
		return attendance.get();
	}

	public TableData(String month, Integer attendance) {
		this.month = new SimpleStringProperty(month);
		this.attendance = new SimpleIntegerProperty(attendance);
	}
}
