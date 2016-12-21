<div class="jumbotron" style="background-image: url(assets/images/jumbotronbackground.jpg)">
  <h4><?= $this->indexPageMessage; ?></h4>
  <h3>Make a reservation and find exclusive promotions</h3>
    <form action="search" method="get" class="form-inline" role="search">
      <div class="form-group">
        <select class="form-control">
          <option>1 Person</option>
          <option>2 People</option>
          <option>3 People</option>
          <option>4 People</option>
          <option>5 People</option>
          <option>6 People</option>
          <option>7 People</option>
          <option>8 People</option>
          <option>9 People</option>
          <option>10 People</option>
          <option>Larger Party</option>
        </select>
      </div>
      <div class="form-group" id="reservation-date">
        <select class="form-control">
          <option><?php $today = new DateTime(); echo $today->format("F jS, Y"); ?></option>
          <option>Show Calender</option>
        </select>
      </div>
      <div class="form-group" id="reservation-time">
        <select class="form-control">
          <option>7:00 PM</option>
          <option>7:15 PM</option>
          <option>7:30 PM</option>
          <option>7:45 PM</option>
          <option>8:00 PM</option>
          <option>8:15 PM</option>
          <option>8:30 PM</option>
          <option>8:45 PM</option>
          <option>9:00 PM</option>
        </select>
      </div>
      <div class="form-group">
        <input id="search-bar" type="text" class="form-control" name="query" placeholder="Neighborhood or Restaurant name">
      </div>
      <button type="submit" class="btn btn-primary">Search</button>
    </form>
</div>    

