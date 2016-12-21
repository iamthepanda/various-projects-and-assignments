
<h2>Pending Restaurants:</h2>
  <ul>
    <?php
        foreach ($this->restaurants as $restaurant) {
            if (!$restaurant['approve_status']) {
                echo "<li>";
                    echo '<strong>'. $restaurant['name'] .'</strong> | '. $restaurant['description'] .'<br />';
                    echo '<a href="approve/' .$restaurant['rt_id']. '">Approve Restaurant?</a>';
                echo "</li><hr />";
            }
        }
    ?>    
  </ul>

