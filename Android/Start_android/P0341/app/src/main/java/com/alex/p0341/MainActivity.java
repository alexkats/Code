package com.alex.p0341;

import android.app.Activity;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity implements View.OnClickListener {

    public final static String TAG = "My logs";

    EditText etName;
    EditText etEmail;
    Button btnAdd;
    Button btnRead;
    Button btnClear;
    DBHelper dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        etName = (EditText) findViewById(R.id.etName);
        etEmail = (EditText) findViewById(R.id.etEmail);
        btnAdd = (Button) findViewById(R.id.btnAdd);
        btnRead = (Button) findViewById(R.id.btnRead);
        btnClear = (Button) findViewById(R.id.btnClear);
        btnAdd.setOnClickListener(this);
        btnRead.setOnClickListener(this);
        btnClear.setOnClickListener(this);

        dbHelper = new DBHelper(this);
    }

    @Override
    public void onClick(View v) {
        ContentValues cv = new ContentValues();

        String name = etName.getText().toString();
        String email = etEmail.getText().toString();

        SQLiteDatabase db = dbHelper.getWritableDatabase();

        switch (v.getId()) {
            case R.id.btnAdd:
                Log.d(TAG, "--- Insert in mytable: ---");
                cv.put("Name", name);
                cv.put("Email", email);
                long rowID = db.insert("mytable", null, cv);
                Log.d(TAG, "row inserted, ID = " + rowID);
                break;
            case R.id.btnRead:
                Log.d(TAG, "--- Rows in mytable: ---");
                Cursor c = db.query("mytable", null, null, null, null, null, null);

                if (c.moveToFirst()) {
                    int idColIndex = c.getColumnIndex("id");
                    int nameColIndex = c.getColumnIndex("Name");
                    int emailColIndex = c.getColumnIndex("Email");

                    do {
                        Log.d(TAG, "ID = " + c.getInt(idColIndex) + "; Name = " + c.getString(nameColIndex) + "; E-mail = " + c.getString(emailColIndex));
                    } while (c.moveToNext());
                } else {
                    Log.d(TAG, "0 rows");
                }

                c.close();
                break;
            case R.id.btnClear:
                Log.d(TAG, "--- Clear my table: ---");
                int clearCount = db.delete("mytable", null, null);
                Log.d(TAG, "deleted rows count = " + clearCount);
                break;
            default:
                break;
        }

        dbHelper.close();
    }

    class DBHelper extends SQLiteOpenHelper {
        public DBHelper(Context context) {
            super(context, "myDB", null, 1);
        }

        @Override
        public void onCreate(SQLiteDatabase db) {
            Log.d(TAG, "--- onCreate database ---");
            db.execSQL("create table mytable (" + "id integer primary key autoincrement," + "Name text," + "Email text" + ");");
        }

        @Override
        public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        }
    }
}