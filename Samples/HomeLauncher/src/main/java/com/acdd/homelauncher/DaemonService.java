package com.acdd.homelauncher;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

import com.openatlas.homelauncher.otto.OttoManger;
import com.openatlas.homelauncher.otto.OttoMessage;

public class DaemonService extends Service {
    Thread thread =new Thread(new Runnable() {
        @Override
        public void run() {
          while (true){
              OttoManger.getInstance().post(new OttoMessage("post message",getClass().getName(),System.nanoTime()));
              System.out.println("messsed posed "+OttoManger.getInstance());
              try {
                  Thread.sleep(500);
              } catch (InterruptedException e) {
                  e.printStackTrace();
              }
          }
        }
    });
    public DaemonService() {
    }

    @Override
    public void onCreate() {
        super.onCreate();
        System.out.println("DaemonService created");
        thread.start();
    }

    @Override
    public void onStart(Intent intent, int startId) {
        super.onStart(intent, startId);
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        return super.onStartCommand(intent, flags, startId);
    }

    @Override
    public IBinder onBind(Intent intent) {
        // TODO: Return the communication channel to the service.
        throw new UnsupportedOperationException("Not yet implemented");
    }
}
