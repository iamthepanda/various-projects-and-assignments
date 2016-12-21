
<h2>Owner:</h2>
<h1>Offers available</h1>
  <!-- Example row of columns -->
      <div class="row">
        <div class="col-lg-4">
          <h2>$12 for $20 Worth of Pizza </h2>
          <p>Hand-tossed pizzas slathered with sauce made from vine-ripened, California-grown tomatoes </p>
          <p><a class="btn btn-primary" href="#" role="button">Delete &raquo;</a></p>
        </div>
        <div class="col-lg-4">
          <h2>Italian Dinner for Two or Four or More </h2>
          <p>$25 for $40 worth of Italian dinner for two </p>
          <p>$50 for $80 worth of Italian dinner for four or more </p>

          <p><a class="btn btn-primary" href="#" role="button">Delete &raquo;</a></p>
       </div>
        <div class="col-lg-4">
          <h2>$22 for any Large Six-Topping Pizza</h2>
          <p>Large pizza with up to six toppings (Any Specialty or up to 6 Reg. Priced Toppings)</p>
          <p><a class="btn btn-primary" href="#" role="button">Delete &raquo;</a></p>
        </div>
      </div>
<h1>Create an offer: </h1>
<form enctype="multipart/form-data" action="offer_submit.php" method="post">
  
  <label>Offer: </label><input type="text" name="offer" /><br />
  <label for="describtion"> Describtion:  </label> <br />
  <textarea id="describtion" name="describtion" cols="40" rows="10"></textarea><br />
  <label> Insert image (optional):</label>  
  <br><input name="file" type="file" id=" file" size="80"> <br>
  <input class="btn btn-default" type="submit" />
</form>


