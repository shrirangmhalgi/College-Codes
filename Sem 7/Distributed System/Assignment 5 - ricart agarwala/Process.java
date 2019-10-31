
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.Iterator;
import java.util.Timer;
import java.util.TimerTask;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Process implements Runnable{
    
    //Each process has a pid, a logical clock, an array of ports to which it communicates with other processes and its own server side port.
    private int pid;
    private int clock; 
    private int[] portArray;
    private int[] resources = {0, 0}; //Simulating two features
    private int[] confirmArray = {0, 0, 0};
    private int port; 
    private ArrayList<Tuple> queue;
    
    //Tuple class, is used to insert messages in the ordered queue, contains the process that sent the message, the logical clock that came in the message and the message itself
    private class Tuple implements Comparator<Tuple>{
            public int resource;
            public int pid;
            public int clock;
            public String message;
            
            public Tuple(int resource, int pid, int clock, String message){
                this.resource = resource;
                this.pid = pid;
                this.clock = clock;
                this.message = message;
            }
            
            public Tuple(){}
            
            @Override
            public int compare(Tuple t1, Tuple t2) {
                return t1.clock - t2.clock;
            }
        }
    
    
    public Process(int pid, int clock, int port, int[] portArray, int resource){
        this.pid = pid;
        this.clock = clock;
        this.port = port;
        this.portArray = portArray;
        this.resources[resource] = 2;
        queue = new ArrayList<>();
    }
    
    public Process(int pid, int clock, int port, int[] portArray){
        this.pid = pid;
        this.clock = clock;
        this.port = port;
        this.portArray = portArray;
        queue = new ArrayList<>();
    }
    
    @Override
    public void run() {
        Runnable s = new Server();
        new Thread(s).start();
        
        Runnable c = new Client();
        new Thread(c).start();  
        
    }
    
    private void print(){
        String buffer = "List from process "+pid+":";
        for (int i=0;i<queue.size();i++) {
            buffer +=" "+ queue.get(i).pid +"/"+ queue.get(i).clock + "/" + queue.get(i).message;
        }
        System.out.println(buffer);
    }
    
    private void sendConfirmation(int resource, int port) throws IOException{
            try (Socket socket = new Socket("127.0.0.1", port)) 
                {
                    DataOutputStream ostream = new DataOutputStream(socket.getOutputStream());
                    DataInputStream istream = new DataInputStream(socket.getInputStream());

                    ostream.writeUTF(resource + "-" + pid + "-" + clock + "-" + "OK");
                    ostream.flush();

                    socket.close();
                    
                    
                }
        }
        
    private void useResource(String[] tuples){
        int interval = 3000; // 3 segundos usando o recurso
        Date timeToRun = new Date(System.currentTimeMillis() + interval);
        Timer timer = new Timer();
        print();
        resources[Integer.parseInt(tuples[0])] = 2;
        System.out.println(resources[Integer.parseInt(tuples[0])]);
        System.out.println("Process " + pid + " started using feature " + tuples[0]);
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                resources[Integer.parseInt(tuples[0])] = 0;
                for (int x : confirmArray) {
                    x = 0;
                }
                for (int i = 0; i < queue.size(); i++) {
                    Tuple r = queue.remove(i);
                    System.out.println(portArray[r.pid - 1]);
                    try {
                        sendConfirmation(Integer.parseInt(tuples[0]), portArray[r.pid - 1]);
                    } catch (IOException ex) {
                        Logger.getLogger(Process.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                System.out.println("Process " + pid + " released feature " + tuples[0]);
            }
        }, timeToRun);
    }
    
    public class Client implements Runnable {
        public void incrementClock(){
            clock = clock+1;
        }
        
        public void wantResource(int r){
            resources[r] = 1;
        }
        
        public void notwantResource(int r){
            resources[r] = 0;
        }
        
        public void usingResource(int r){
            resources[r] = 2;
        }
        
        public void stopusingResource(int r){
            resources[r] = 0;
        }
        
        public void request(int resource) throws IOException {
            incrementClock();
            boolean permission;
            if(portArray == null) return;
            for (int port : portArray) {
                
                permission = true;
                try (Socket socket = new Socket("127.0.0.1", port)) 
                {
                    DataOutputStream ostream = new DataOutputStream(socket.getOutputStream());
                    DataInputStream istream = new DataInputStream(socket.getInputStream());

                    ostream.writeUTF(resource + "-" + pid + "-" + clock + "-" + "REQUEST");
                    ostream.flush();

                    String recv = istream.readUTF();
                    if(recv.length() > 0){
                        System.out.println("Process "+ pid + " receiving OK: "+recv);
                        String[] tuples = recv.split("-");
                        if(tuples[3].compareTo("OK") == 0){
                            confirmArray[Integer.parseInt(tuples[1])-1] = 1;
                            for(int x : confirmArray){
                                if(x == 0){
                                    permission = false;
                                    break;
                                }
                            }
                            if(permission){
                                useResource(tuples);
                            }
                        }
                        //print();
                    }
                    socket.close();
                }
            }
        }
        
        

        @Override
        public void run() {
            System.out.println(pid + " is up!");
            try {
                request(0);
            } catch (IOException ex) {
                Logger.getLogger(Process.class.getName()).log(Level.SEVERE, null, ex);
            }
            
        }

    }
    
    public class Server implements Runnable {
        @Override
        public void run() {
            Socket socket = null;
            ServerSocket serverSocket;

            try {    
                serverSocket = new ServerSocket(port);
                while (true) {
                    socket = serverSocket.accept();
                    DataOutputStream ostream = new DataOutputStream(socket.getOutputStream());
                    DataInputStream istream = new DataInputStream(socket.getInputStream());
                    
                    String message = istream.readUTF();
                    String[] tuples = message.split("-");
                    
   
                    clock = Integer.max(Integer.parseInt(tuples[1]), clock) + 1;
                    
                    System.out.println("PID "+pid+": "+resources[Integer.parseInt(tuples[0])]);
                    if(tuples[3].compareTo("OK") == 0){
                        boolean permission = true;
                        confirmArray[Integer.parseInt(tuples[1]) - 1] = 1;
                        for (int x : confirmArray) {
                            System.out.print(x);
                            if (x == 0) {
                                permission = false;
                                break;
                            }
                        }
                        if (permission) {
                            useResource(tuples);
                        }
                    }else{
                        switch (resources[Integer.parseInt(tuples[0])]) {
                            case 0:
                                ostream.writeUTF(tuples[0] + "-" + pid + "-" + clock + "-" + "OK");
                                ostream.flush();
                                break;
                            case 1:
                                if (clock < Integer.parseInt(tuples[2])) {
                                    queue.add(new Tuple(Integer.parseInt(tuples[0]), Integer.parseInt(tuples[1]), Integer.parseInt(tuples[2]), tuples[3]));
                                    Collections.sort(queue, new Tuple());
                                } else {
                                    ostream.writeUTF(tuples[0] + "-" + pid + "-" + clock + "-" + "OK");
                                    ostream.flush();
                                }
                                break;
                            case 2:
                                if (tuples[1].compareTo(pid + "") == 0) {
                                    ostream.writeUTF(tuples[0] + "-" + pid + "-" + clock + "-" + "OK");
                                    ostream.flush();
                                    break;
                                } else {
                                    queue.add(new Tuple(Integer.parseInt(tuples[0]), Integer.parseInt(tuples[1]), Integer.parseInt(tuples[2]), tuples[3]));
                                    Collections.sort(queue, new Tuple());
                                    break;
                                }
                        }
                    }
                    
                    
                    
                    
                }
            } catch (IOException e) {
                System.err.println("Closing Connection");
                System.err.println(e.toString());
                if (socket != null) {
                    try {
                        socket.close();
                    } catch (IOException ex) {
                    }
                }
            }

        }
    }
}
