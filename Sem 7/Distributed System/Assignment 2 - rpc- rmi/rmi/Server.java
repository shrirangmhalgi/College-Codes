/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Ria Mittal
 */
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class Server extends UnicastRemoteObject implements Adder,Subtractor,Multiplier,Divider{
    public Server() throws RemoteException{
        
    }
    public int add(int x, int y) throws RemoteException{
        return x+y;
    }
    public int sub(int x, int y) throws RemoteException{
        return x-y;
    }
    public int mul(int x, int y) throws RemoteException{
        return x*y;
    }
    public int div(int x, int y) throws RemoteException{
        if(y==0)
        	return 0;
        else
        	return x/y;
    }
    public static void main(String[] args) throws RemoteException{
        try{
            Registry reg = LocateRegistry.createRegistry(9999);
            reg.rebind("server", new Server());
            System.out.println("server is ready");
        } catch(RemoteException e){
            System.out.println(e);
        }
    }
}
