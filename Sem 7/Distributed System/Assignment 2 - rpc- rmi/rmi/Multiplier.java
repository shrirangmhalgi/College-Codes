/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Ria Mittal
 */
import java.rmi.*;
public interface Multiplier extends Remote{
    public int mul(int x, int y) throws RemoteException;
}
