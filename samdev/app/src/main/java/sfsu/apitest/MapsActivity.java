package sfsu.apitest;

import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.support.v4.app.FragmentActivity;
import android.os.Bundle;
import android.util.Log;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.gson.Gson;

import YelpAPI.YelpAPI;
import YelpData.BusinessData;

public class MapsActivity extends FragmentActivity {

    private GoogleMap mMap; // Might be null if Google Play services APK is not available.
    private LocationListener mLocationListener;
    private android.location.LocationManager mLocationManager;
    private Marker mMarker;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        setUpMapIfNeeded();
    }

    @Override
    protected void onResume() {
        super.onResume();
        setUpMapIfNeeded();
    }

    /**
     * Sets up the map if it is possible to do so (i.e., the Google Play services APK is correctly
     * installed) and the map has not already been instantiated.. This will ensure that we only ever
     * call {@link #setUpMap()} once when {@link #mMap} is not null.
     * <p/>
     * If it isn't installed {@link SupportMapFragment} (and
     * {@link com.google.android.gms.maps.MapView MapView}) will show a prompt for the user to
     * install/update the Google Play services APK on their device.
     * <p/>
     * A user can return to this FragmentActivity after following the prompt and correctly
     * installing/updating/enabling the Google Play services. Since the FragmentActivity may not
     * have been completely destroyed during this process (it is likely that it would only be
     * stopped or paused), {@link #onCreate(Bundle)} may not be called again so we should call this
     * method in {@link #onResume()} to guarantee that it will be called.
     */
    private void setUpMapIfNeeded() {
        // Do a null check to confirm that we have not already instantiated the map.
        if (mMap == null) {
            // Try to obtain the map from the SupportMapFragment.
            mMap = ((SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.map))
                    .getMap();
            // Check if we were successful in obtaining the map.
            if (mMap != null) {
                setUpMap();
            }
        }
    }

    /**
     * This is where we can add markers or lines, add listeners or move the camera. In this case, we
     * just add a marker near Africa.
     * <p/>
     * This should only be called once and when we are sure that {@link #mMap} is not null.
     */
    private void setUpMap() {


        YelpAPI api = YelpAPI.YelpInit();
        String response = api.searchForBusinessesByLocation("dildo", "San Francisco, CA");
        int i=0;
        i++;
        BusinessData business;
        business = new Gson().fromJson(response, BusinessData.class);
        int y = 0;
        y++;
        getLocation();
    }

    private void getLocation(){
        if(mLocationListener==null){
            mLocationListener = new LocationListener() {
                 @Override
                public void onStatusChanged(String provider, int status, Bundle extras) {
                //TODO(Darin) put stuff here
                }

                 @Override
                public void onProviderEnabled(String provider) {
                //TODO(Sam) put stuff here
                }

                 @Override
                public void onProviderDisabled(String provider) {
                //TODO(Sam) put stuff here
                }

                @Override
                public void onLocationChanged(Location location) {
                //TODO(Sam) put stuff here

                    if (mMarker == null)
                    {
                        MarkerOptions options = new MarkerOptions();
                        options.title("SamPlace");
                        options.position(new LatLng(location.getLatitude(), location.getLongitude()));
                        mMarker = mMap.addMarker(options);
                        mMap.animateCamera(CameraUpdateFactory.newLatLngZoom(new LatLng(location.getLatitude(), location.getLongitude()), 12.0f));
                    }
                    else
                    {
                        //If you move and the marker already exists, update your position and move the map
                        mMarker.setPosition(new LatLng(location.getLatitude(), location.getLongitude()));
                        mMap.animateCamera(CameraUpdateFactory.newLatLngZoom(new LatLng(location.getLatitude(), location.getLongitude()), 12.0f));
                    }

                    int i = 0;
                    i++;
                }

            };
            mLocationManager = (LocationManager) getSystemService(LOCATION_SERVICE);
                //TODO (Darin) put stuff here - configure min time and min distance
            mLocationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 300,
                    0, mLocationListener);
        }
    }
}
