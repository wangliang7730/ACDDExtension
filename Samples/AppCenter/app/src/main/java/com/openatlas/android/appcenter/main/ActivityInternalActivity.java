package com.openatlas.android.appcenter.main;

import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

import com.openatlas.android.appcenter.AppProvider;
import com.openatlas.android.appcenter.R;
import com.openatlas.homelauncher.otto.OttoManger;
import com.openatlas.homelauncher.otto.OttoMessage;
import com.squareup.otto.Subscribe;


public class ActivityInternalActivity extends Activity {
Button btnInsert;
Button btnQuery;

	@Override
	protected void onPause() {
		super.onPause();
		OttoManger.getInstance().unregister(this);

	}

	@Override
	protected void onResume() {
		OttoManger.getInstance().register(this);
		super.onResume();
	}
	@Subscribe
	public void  dumpMessage(OttoMessage ottoMessage){
		Log.d(getClass().getCanonicalName(),"got otto>>>"+ottoMessage.toString());
	}
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_internal);
		btnInsert=(Button) findViewById(R.id.btnInsert);
		btnQuery=(Button) findViewById(R.id.btnQuery);
		btnInsert.setOnClickListener(new  OnClickListener() {
			
			@Override
			public void onClick(View v) {
				insertRecord("uname"+System.currentTimeMillis());
				
			}
		});
		btnQuery.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				displayRecords();
				
			}
		});
	}


	private void insertRecord(String userName) {
		ContentValues values = new ContentValues();
		values.put("USER_NAME", userName);
		Uri ret=getContentResolver().insert(AppProvider.AppProviderURI, values);
		System.out.println("insert  is "+ret);
	}
	private void displayRecords() {
		String columns[] = new String[] { "_id","USER_NAME" };
		Uri myUri = AppProvider.AppProviderURI;
		Cursor cur = managedQuery(myUri, columns,null, null, null );
		if (cur.moveToFirst()) {
			String id = null;
			String userName = null;
			do {
				id = cur.getString(cur.getColumnIndex("_id"));
				userName = cur.getString(cur.getColumnIndex("USER_NAME"));
				System.out.println("ActivityInternalActivity.displayRecords() id "+id+" uname "+userName);
			} while (cur.moveToNext());
		}
	}
}
