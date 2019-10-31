package com.gui;
	
import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.stage.Stage;
import javafx.stage.StageStyle;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.fxml.FXMLLoader;


public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		try {
			Parent root = FXMLLoader.load(getClass().getResource("/com/gui/Screen.fxml"));
			Scene scene = new Scene(root);
			scene.setRoot(root);
			primaryStage.setScene(scene);
			primaryStage.setMaximized(false);
			primaryStage.initStyle(StageStyle.UTILITY);
			primaryStage.setTitle("Student Attendance Module");
			primaryStage.maximizedProperty().addListener(new ChangeListener<Boolean>() {
				@Override
				public void changed(ObservableValue<? extends Boolean> observable, Boolean oldValue, Boolean newValue) {
					if (newValue)
		                primaryStage.setMaximized(false);
				}
			});
			
			primaryStage.show();
			
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
			launch(args);
	}
}
