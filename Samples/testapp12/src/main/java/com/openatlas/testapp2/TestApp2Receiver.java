package com.openatlas.testapp2;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

public class TestApp2Receiver extends BroadcastReceiver {
    public TestApp2Receiver() {
    }

    @Override
    public void onReceive(Context context, Intent intent) {
        Log.d("testapp2","got  message "+intent.getAction());
    }
}
