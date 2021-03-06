package ru.ifmo.ctddev.kacman.bank;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.concurrent.ConcurrentHashMap;

public interface RemotePerson extends Remote, Person {

    String getName() throws RemoteException;
    String getSurname() throws RemoteException;
    String getPassportNumber() throws RemoteException;
    ConcurrentHashMap<String, Account> getAccounts() throws RemoteException;
    int setAmount(String accountId, int amount) throws RemoteException;
    String showMoney(String key) throws RemoteException;
    int getMoney(String key) throws RemoteException;
}
