import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;
import java.nio.Buffer;
import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.Formatter;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.Scanner;
import java.util.TreeMap;


public class ClockSync_Client {

	static int sequenceNumber = 0 ;
	static List<String>unsuccessfullist = new ArrayList<String>();
	static List<Integer>successfullist = new ArrayList<Integer>();
	static Queue<Double > queue = new LinkedList<>();
	//static Double []  rttTime = new Double[8];
	//static ArrayList<ArrayList<Double>> lists= new ArrayList<ArrayList<Double>>();
	//static ArrayList<ArrayList<Double>> succesLists = new ArrayList<ArrayList<Double>>();
	static List<Double>latestEightOffset = new ArrayList<Double>();
	static List<Double>latestEightRTT = new ArrayList<Double>();
	static List<Double>allOffset = new ArrayList<Double>();
	static List<Double>allRTT = new ArrayList<Double>();
	//static Map<Double, Double> map = new HashMap<Double, Double>();
	//static Map<Double, Double> successmap = new HashMap<Double, Double>();
	Formatter formatter = new Formatter(Locale.US);
	static PrintWriter writer ;
	public ClockSync_Client() throws IOException {
		 File file = new File ("ClientLog_8.txt");
         FileWriter fileWriter = new FileWriter(file, true);
         writer = new PrintWriter(fileWriter);
	}
	
	//Form the DataGram Packet
	public static DatagramPacket formatRequest(InetAddress address, int port) {
		
		//UDP Packet
		Instant instant = Instant.now();
		String clientReqtime = instant.getEpochSecond()+"."+(instant.getNano()/1000);
		System.out.println("clientReqtime time in seconds is "+clientReqtime);
		sequenceNumber++;
		System.out.println("Request Number: "+sequenceNumber);
		writer.println("Request Number: "+sequenceNumber);
		//Add the sequence number in list
		//list.add(sequenceNumber);
		String finalString = Integer.toString(sequenceNumber) +" " + clientReqtime;
		byte[] buf = finalString.getBytes();
		int length = buf.length;
		InetSocketAddress dest = new InetSocketAddress(address, port);
		DatagramPacket clientPacket = new DatagramPacket(buf, length, dest);
		//DatagramPacket clientPacket = new DatagramPacket(buf, length, address, port);
		return clientPacket;
		//model.setSequenceNumber(++sequenceNumber);
		//model.setRequestTime(requestTime);
	}
	

	public static  Double [] calculateRTT(String serverResponse, String clientReceivedTime) {
		String [] stringArr = serverResponse.split(" ");
		Double t3 = 0.0;
		t3=Double.parseDouble(stringArr[1]);
		Double t2 = 0.0;
		t2=Double.parseDouble(stringArr[2]);
		Double t1= 0.0;
		t1= Double.parseDouble(stringArr[3]);
		Double t0 = 0.0;
		t0= Double.parseDouble(clientReceivedTime);
		
		for(int i =0;i<stringArr.length;i++) {
			System.out.println(stringArr[i]);
		}
		Double roundTripTime = (t2 - t3) + (t0 - t1);
		System.out.println("Round Trip time = "+roundTripTime*1000000+" micro-seconds");
		System.out.println("Round Trip time = "+String.format("%.3f",roundTripTime*1000000)+" micro-seconds");
		writer.println("Round Trip time = "+String.format("%.3f",roundTripTime*1000000)+" micro-seconds");
		Double offset = ((t2 - t3) - (t0 - t1)) / 2 ;
		System.out.println("Offset is "+offset*1000000+" micro-seconds");
		System.out.println("Offset is "+String.format("%.3f",offset*1000000)+" micro-seconds");
		writer.println("Offset is "+String.format("%.3f",offset*1000000)+" micro-seconds");
		Double[] retArr = {roundTripTime,offset};
		
		Instant instant = Instant.now();
		String currentTime = instant.getEpochSecond()+"."+(instant.getNano()/1000);
		System.out.println("currentTime in second is "+currentTime);
		Double clinetCurrentTime = 0.0 ;
		clinetCurrentTime = Double.parseDouble(currentTime);
		Double clientCorrectedTime = clinetCurrentTime+offset;
		System.out.println("Client Local Time: "+ String.format("%.6f", clinetCurrentTime)+ " seconds,  corrected client local time is "+  String.format("%.6f",clientCorrectedTime)
		+ " seconds and smoothed by  "+String.format("%.6f",offset)+" seconds");
		
		writer.println("Client Local Time: "+ String.format("%.6f", clinetCurrentTime)+ " seconds,  corrected client local time is "+  String.format("%.6f",clientCorrectedTime)
				+ " seconds and smoothed by  "+String.format("%.6f",offset)+" seconds");
		return retArr;
	}

	//Get the estimate based on the least RTT
	public static void getEstimate() {
		Double leastRTT = 0.0;
		Double smoothedFactor = 0.0;
		//get least RTT from map
		if(!latestEightRTT.isEmpty()) {
			int minIndex = latestEightRTT.indexOf(Collections.min(latestEightRTT));
			smoothedFactor = latestEightOffset.get(minIndex);
			System.out.println("Client clock  is off by "+String.format("%.3f",smoothedFactor*1000000)+" micro-seconds ");
			System.out.println("Client clock  is off by "+smoothedFactor*1000000+" micro-seconds ");
		   writer.println("Client clock  is off by "+String.format("%.3f",smoothedFactor*1000000)+" micro-seconds ");
		} else {
			 writer.println("Map is empty");
		}
	}
	//Add new RTT and Offset on the Map and Queue
	public static void updateQueueAndMap(Double roundTripTime, Double offset) {
		//Add a queue of length 8 to hold latest 8 successful interactions
		ArrayList<Double> internalList = new ArrayList<Double>();
		Double toBeRemoved = 0.0;
		//int size = queue.size();
		int size = latestEightRTT.size();
		if(size>=8) {
			//Remove 1st entry from both RTT and OffsetList
			latestEightRTT.remove(0);
			latestEightOffset.remove(0);
			}
		
		latestEightRTT.add(roundTripTime);
		latestEightOffset.add(offset);
		allRTT.add(roundTripTime);
		allOffset.add(offset);
	 
		//Add the most recent entry in queue
		//queue.add(roundTripTime);
		//Map to hold RTT and drift
		
		//internalList.add(roundTripTime);
		//internalList.add(offset);
		//lists.add(internalList);
		//succesLists.add(internalList);
		//map.put(roundTripTime, offset);
	   //successmap.put(roundTripTime, offset);
	}
	public static void avgRTTandDrift() {
		Double avgRTT = 0.0;
		Double totalRTT = 0.0;
		Double avgDrift = 0.0;
		Double totalDrift = 0.0;
		//get least RTT from map
		if(!allRTT.isEmpty()) {
			for (Double rtt :allRTT) {
				totalRTT +=rtt;
			}
		
			for (Double offset : allOffset) {
				totalDrift += offset;
			}
			
		   avgRTT = totalRTT/allRTT.size() ;
		   avgDrift = totalDrift/allOffset.size();
		   System.out.println("Averege round trip after "+allRTT.size()+ " interaction is "+avgRTT*1000000+" micro-seconds");
		   System.out.println("Averege drift after "+allOffset.size()+ " interaction is "+avgDrift*1000000+" micro-seconds ");
		   System.out.println("Packet loss rate is "+(unsuccessfullist.size()/successfullist.size()));
		   writer.println("Averege round trip after "+allRTT.size()+ " interaction is "+String.format("%.3f",avgRTT*1000000)+" micro-seconds");
		   writer.println("Averege drift after "+allOffset.size()+ " interaction is "+String.format("%.3f",avgDrift*1000000)+" micro-seconds ");
		   writer.println("Packet loss rate is "+(unsuccessfullist.size()/successfullist.size()));
		   
		} else {
			 System.out.println("Map is empty");
		}
		
	}
	//
/*	public static void addLocalTimeandCorrectedTime(Double offset ) {
		Instant instant = Instant.now();
		String currentTime = instant.getEpochSecond()+"."+(instant.getNano()/1000);
		System.out.println("instant time is "+currentTime);
		System.out.println("System.currentTimeMillis() is :"+System.currentTimeMillis());
		Double clinetCurrentTime = 0.0 ;
		clinetCurrentTime = Double.parseDouble(currentTime);
		Double clientCorrectedTime = clinetCurrentTime+offset;
		Double [] array = {clinetCurrentTime, clientCorrectedTime, offset};
		interactionList.add(array);
	}*/
	public static void main(String[] args) throws IOException {
		
		ClockSync_Client clockSync_Client = new ClockSync_Client();
		 byte[] receiveData = new byte[64];
		Scanner scan = new Scanner(System.in);
		System.out.println("Please enter server IP Address: ");
		String serverIPAddress= scan.next();
		System.out.println("Please enter the port number ");
		int portNum = scan.nextInt();
		while(true) {
			writer.println("\n-----------------------------------");
			System.out.println("\n-----------------------------------");
			System.out.println("Current Queue Size is "+queue.size());
			System.out.println("Total lost requests are "+unsuccessfullist.size());
			System.out.println("Total successful requests are "+successfullist.size());
			System.out.println("Current size of best RTT "+latestEightRTT.size());
			System.out.println("Current size of best Offset "+latestEightOffset.size());
			System.out.println("Current size of success RTT "+allRTT.size());
			System.out.println("Current size of success offset "+allOffset.size());
			
		try {
			DatagramSocket socket  = new DatagramSocket();
			socket.setSoTimeout(3000);
			socket.send(formatRequest((InetAddress.getByName(serverIPAddress)), portNum));
			DatagramPacket serverPacket = new DatagramPacket(receiveData, receiveData.length);
			socket.receive(serverPacket);
			Instant instant1 = Instant.now();
			String clientReceivedTime = instant1.getEpochSecond()+"."+(instant1.getNano()/1000);
			System.out.println("clientReceivedTime time is "+clientReceivedTime);
			String data = new String(serverPacket.getData());
			data = data.trim();
            socket.close();
            successfullist.add(sequenceNumber);
            Double[] retArr = calculateRTT(data,clientReceivedTime );
            //Get the drift
            getEstimate();
            //Update the maps
            updateQueueAndMap(retArr[0], retArr[1]);
            // Display Abg RTT and Offset
            avgRTTandDrift();
          //  writer.println("Starting to sleep at :"+ new Date());
			System.out.println("Starting to sleep at :"+ new Date());
			Thread.sleep(10000);
			//writer.println("\n Woke up at :"+ new Date());	
			System.out.println("\n Woke up at :"+ new Date());			
			
		} catch (SocketTimeoutException e) {
			String message = "Request with Sequence number " + sequenceNumber + " timedOut";
			unsuccessfullist.add(message);
			// TODO: handle exception
		} 
		catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}catch (IOException e) {
			e.printStackTrace();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	}
}
