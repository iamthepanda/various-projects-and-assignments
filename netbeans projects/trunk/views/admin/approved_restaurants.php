
<h2>Approved Restaurants:</h2>
  <ul>
    <?php
        foreach ($this->restaurants as $restaurant) {
            if ($restaurant['approve_status']) {
                echo "<li>";
                    echo '<strong>'. $restaurant['name'] .'</strong> | '. $restaurant['description'] .'<br />';
                    echo '<a href="restaurant/' .$restaurant['rt_id']. '">Edit Restaurant</a>';
                echo "</li><hr />";
            }
        }
    ?>    
  </ul>

