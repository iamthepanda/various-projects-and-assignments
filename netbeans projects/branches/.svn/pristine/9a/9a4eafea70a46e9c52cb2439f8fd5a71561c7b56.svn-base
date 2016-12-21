<h3>Available restaurants:</h3> <br />
  <ul>
    <?php
        
        foreach ($this->searchResults as $restaurant) {
            echo "<li><div class='row'";
                echo '<div class="col-xs-2"><img src="image/getrt/' .$restaurant['rt_id']. '" height="50%" width="50%"></div>'
                    . '<div class="col-xs-10">'
                    . '<strong>'. $restaurant['name'] .'</strong> | '. $restaurant['description'] 
                    .'</div><br />';
                echo '<a href="reserve" class="btn btn-default">Reserve Now</a>';
            echo "</div</li><hr />";
        }
    ?>
</ul>
