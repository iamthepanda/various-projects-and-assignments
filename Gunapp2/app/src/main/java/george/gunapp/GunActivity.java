package george.gunapp;  // so AS knows where to find stuff

// libraries
import android.app.Activity;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import java.util.concurrent.LinkedBlockingQueue;

public class GunActivity extends Activity {
    // set no rotation in manifest

    final int singleBlast = R.raw.laser_blast;   // now set our sound effect to an integer variable so we can call it elsewhere. Technically we can just call R.raw.single_shot, but this makes things easier. final because we will not modify this variable

    @Override   // override a predefined method
    protected void onCreate(Bundle savedInstanceState) {    // this stuff happens upon creation of the activity

        // alt+enter AudioManager
        setVolumeControlStream(AudioManager.STREAM_MUSIC);

        super.onCreate(savedInstanceState); // do stuff from the parent class's onCreate
        setContentView(R.layout.activity_gun);  // the view is an xml file called activity_gun

        // had to alt+enter Button
        Button gunButton = (Button) findViewById(R.id.gun_button);   // make a new button called gunButton and tie it to the xml file we created

        // alt+enter LinkedBlockingQueue
        // for use with threadpool
        final LinkedBlockingQueue<Runnable> shotQueue = new LinkedBlockingQueue();

        // threadpool. spawns with onCreate
        for (int i = 0; i < 50; i++) {
            new Thread() {  // create thread
                public void run() { // run the thread
                    while (true) {  // continue to loop while there are threads available
                        try {   // exception handling
                            Runnable task = shotQueue.take();   // create the task and take from the queue
                            task.run(); // run the task
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }.start();  // start the thread
        }

        // alt+enter View
        // set an OnClickListener to detect a click
        gunButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(final View v) { // this method is called upon click
                Runnable task = new Runnable() {    // different task to be tied with other
                    public void run() { // run the runnable
                        gunShot(v);   // call gunShot()
                    }
                };
                shotQueue.add(task);    // add the task to the queue to be used
            }
        });
    }

    // custom method to play the gunshot sound
    private void gunShot(View v) {
        // alt+enter MediaPlayer
        // create a new media player instance in this class with specific sound file
        MediaPlayer mediaPlayer = MediaPlayer.create(GunActivity.this, singleBlast);
        mediaPlayer.start();    // start media
        try {
            Thread.sleep(1429); // the sound effect lasts for 1.429 seconds
            mediaPlayer.release();  // release the player so that more sounds can be produced
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}