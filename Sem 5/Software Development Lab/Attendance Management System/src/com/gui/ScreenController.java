package com.gui;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.URL;
import java.util.Hashtable;
import java.util.ResourceBundle;

import com.dataObjects.AttendenceBean;
import com.dataObjects.UsersBean;
import com.enumerations.Months;
import com.jfoenix.controls.JFXButton;
import com.jfoenix.controls.JFXPasswordField;
import com.jfoenix.controls.JFXTextField;

import javafx.animation.ParallelTransition;
import javafx.animation.TranslateTransition;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Cursor;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.BorderPane;
import javafx.util.Duration;

public class ScreenController implements Initializable{
	ObjectOutputStream out;
	ObjectInputStream in;
	UsersBean bean;
	Socket client;
	Hashtable<String, Integer> attendence;
	AttendenceBean attendenceBean;
	boolean flag = false;
	XYChart.Series series = new XYChart.Series();
	int average = 0;

    @FXML // fx:id="borderPaneMain"
    private BorderPane borderPaneMain; // Value injected by FXMLLoader

    @FXML // fx:id="borderPaneLoginScreen"
    private BorderPane borderPaneLoginScreen; // Value injected by FXMLLoader

    @FXML // fx:id="textfieldGrNo"
    private JFXTextField textfieldGrNo; // Value injected by FXMLLoader

    @FXML // fx:id="textfieldLoginStatus"
    private JFXTextField textfieldLoginStatus; // Value injected by FXMLLoader

    @FXML // fx:id="textfieldPassword"
    private JFXPasswordField textfieldPassword; // Value injected by FXMLLoader

    @FXML // fx:id="buttonLogin"
    private JFXButton buttonLogin; // Value injected by FXMLLoader

    @FXML // fx:id="Screen1"
    private BorderPane Screen1; // Value injected by FXMLLoader

    @FXML // fx:id="buttonLogoutScreen1"
    private JFXButton buttonLogoutScreen1; // Value injected by FXMLLoader

    @FXML // fx:id="textfieldUserNameScreen1"
    private JFXTextField textfieldUserNameScreen1; // Value injected by FXMLLoader

    @FXML // fx:id="tableViewAttendance"
    private TableView<TableData> tableViewAttendance; // Value injected by FXMLLoader

    @FXML // fx:id="tableColumnMonth"
    private TableColumn<TableData, String> tableColumnMonth; // Value injected by FXMLLoader

    @FXML // fx:id="tableColumnAttendance"
    private TableColumn<TableData, Integer> tableColumnAttendance; // Value injected by FXMLLoader

    @FXML // fx:id="buttonLoadGraph"
    private JFXButton buttonLoadGraph; // Value injected by FXMLLoader

    @FXML // fx:id="Screen2"
    private BorderPane Screen2; // Value injected by FXMLLoader

    @FXML // fx:id="buttonLogoutScreen2"
    private JFXButton buttonLogoutScreen2; // Value injected by FXMLLoader

    @FXML // fx:id="textfieldUserNameScreen2"
    private JFXTextField textfieldUserNameScreen2; // Value injected by FXMLLoader

    @FXML // fx:id="lineChartAttendance"
    private LineChart<String, Number> lineChartAttendance; // Value injected by FXMLLoader

    @FXML // fx:id="categoryAxisMonths"
    private CategoryAxis categoryAxisMonths; // Value injected by FXMLLoader

    @FXML // fx:id="numberAxisPercentage"
    private NumberAxis numberAxisPercentage; // Value injected by FXMLLoader

    @FXML // fx:id="buttonBack"
    private JFXButton buttonBack; // Value injected by FXMLLoader

    @FXML
    void login(ActionEvent event) {
    	try {
    		bean = new UsersBean("", "", "");
    		client = new Socket("localhost", 9498); //if you know the port and ipaddress then you can connect to any computer
			System.out.println("connected to server");
			
			out = new ObjectOutputStream(client.getOutputStream());
			in = new ObjectInputStream(client.getInputStream());	
			
			//get and set table data and graph data
			String grNo = textfieldGrNo.getText();
	    	String password = textfieldPassword.getText();
	    	
	    	bean.setGrNo(grNo);
			bean.setPassword(password);
			
			out.writeObject(bean);
			
			attendenceBean = new AttendenceBean();//(AttendenceBean) in.readObject();
			attendence = (Hashtable<String, Integer>) in.readObject();
			bean = (UsersBean) in.readObject();
			
			
			if(bean.getUserName().equals("")) {
				textfieldLoginStatus.setText("Login Failed");
				textfieldLoginStatus.setVisible(true);
			}
			else {
				textfieldLoginStatus.setText("login succcessful");				
				
				attendenceBean.setTable(attendence);
				Months months[] = Months.values();
				for(Months month : months) {
					average = average + attendenceBean.getTable().get(month.toString());
				}
				
				average = average/12;
				
				textfieldUserNameScreen1.setText("Welcome " +bean.getUserName());
				textfieldUserNameScreen2.setText("Welcome " +bean.getUserName());
				flag = true;
				scrollDown(borderPaneMain, Screen1);
				
				drawGraph();
				
				ObservableList<TableData> attendenceList = FXCollections.observableArrayList(
						new TableData(Months.January.toString(), attendenceBean.getTable().get(Months.January.toString())),
						new TableData(Months.February.toString(), attendenceBean.getTable().get(Months.February.toString())),
						new TableData(Months.March.toString(), attendenceBean.getTable().get(Months.March.toString())),
						new TableData(Months.April.toString(), attendenceBean.getTable().get(Months.April.toString())),
						new TableData(Months.May.toString(), attendenceBean.getTable().get(Months.May.toString())),
						new TableData(Months.June.toString(), attendenceBean.getTable().get(Months.June.toString())),
						new TableData(Months.July.toString(), attendenceBean.getTable().get(Months.July.toString())),
						new TableData(Months.August.toString(), attendenceBean.getTable().get(Months.August.toString())),
						new TableData(Months.September.toString(), attendenceBean.getTable().get(Months.September.toString())),
						new TableData(Months.October.toString(), attendenceBean.getTable().get(Months.October.toString())),
						new TableData(Months.November.toString(), attendenceBean.getTable().get(Months.November.toString())),
						new TableData(Months.December.toString(), attendenceBean.getTable().get(Months.December.toString())),
						new TableData("Average", average)
				);
				tableViewAttendance.setItems(attendenceList);
			}
			
			client.close(); //closing server connection

		} catch (IOException | ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }

    @FXML
    void logout(ActionEvent event) {
    	if(event.getSource() == buttonLogoutScreen1) {
    		scrollDown(Screen1, borderPaneMain);
    	}
    	else {
    		scrollDown(Screen2, borderPaneMain);
    	}
    	series.getData().clear();
    	textfieldGrNo.setText("");
    	textfieldPassword.setText("");
    }

    @FXML
    void showScreen1(ActionEvent event) {
    	scrollUp(Screen2, Screen1);
    }

    @FXML
    void showScreen2(ActionEvent event) {
    	scrollUp(Screen1, Screen2);
    	drawGraph();
    }
	
	void scrollDown(BorderPane currentScreen, BorderPane nextScreen){
	    	TranslateTransition tr1 = new TranslateTransition();
	    	tr1.setDuration(Duration.millis(500));
	    	tr1.setToX(0);
	    	tr1.setToY(600);
	    	tr1.setNode(currentScreen);
	    	TranslateTransition tr2 = new TranslateTransition();
	    	tr2.setDuration(Duration.millis(500));
	    	tr2.setFromX(0);
	    	tr2.setFromY(-600);
	    	tr2.setToX(0);
	    	tr2.setToY(0);
	    	tr2.setNode(nextScreen);
	    	ParallelTransition pt = new ParallelTransition(tr1, tr2); 
	    	pt.play();
	    }

	void scrollUp(BorderPane currentScreen, BorderPane nextScreen){
	    	TranslateTransition tr1 = new TranslateTransition();
	    	tr1.setDuration(Duration.millis(500));
	    	tr1.setToX(0);
	    	tr1.setToY(-600);
	    	tr1.setNode(currentScreen);
	    	TranslateTransition tr2 = new TranslateTransition();
	    	tr2.setDuration(Duration.millis(500));
	    	tr2.setFromX(0);
	    	tr2.setFromY(600);
	    	tr2.setToX(0);
	    	tr2.setToY(0);
	    	tr2.setNode(nextScreen);
	    	ParallelTransition pt = new ParallelTransition(tr1, tr2);
	    	pt.play();
	    }
	
	void drawGraph() {
		
			Months months[] = Months.values();
			lineChartAttendance.setTitle("Attendance");
			lineChartAttendance.setLegendVisible(true);
			categoryAxisMonths.setLabel("Months");
			numberAxisPercentage.setLabel("Percentage");
			
		    for(Months month : months) {
		      	series.getData().add(new XYChart.Data(month.toString(), attendenceBean.getTable().get(month.toString())));
		    }
		    lineChartAttendance.setAnimated(true);
		            
		    lineChartAttendance.getData().add(series);
		    
	}

	@Override
	public void initialize(URL location, ResourceBundle resources) {
		tableColumnMonth.setCellValueFactory(new PropertyValueFactory<TableData, String>("Month"));
		tableColumnAttendance.setCellValueFactory(new PropertyValueFactory<TableData, Integer>("Attendance"));
		
		tableColumnMonth.setStyle( "-fx-alignment: CENTER;");
		tableColumnAttendance.setStyle( "-fx-alignment: CENTER;");
		
	}
}
