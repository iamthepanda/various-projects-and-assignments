<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="description" content="">
        <meta name="author" content="">

        <title>Log</title>

        <!-- Bootstrap Core CSS -->
        <link href="css/bootstrap.min.css" rel="stylesheet">

        <!-- Custom CSS -->
        <link href="css/custom.css" rel="stylesheet">
        <style>
            body {
                padding-top: 40px;
                /* Required padding for .navbar-fixed-top. Remove if using .navbar-static-top. */
            }
        </style>
        <link href="css/half-slider.css" rel="stylesheet">
        <link rel="icon" type="image/gif" href="pics/tumblr_inline_mgpk1wODbe1qdlkyg.gif">
    </head>

    <body>

        <div class="wrapper">
            <!-- Navigation -->
            <nav class="navbar navbar-inverse navbar-fixed-top" role="navigation">
                <div class="container">
                    <!-- Brand and toggle get grouped for better mobile display -->
                    <div class="navbar-header">
                        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                            <span class="sr-only">Toggle navigation</span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                        </button>
                        <a class="navbar-brand" href="index.php">George Jone</a>
                    </div>
                    <!-- Collect the nav links, forms, and other content for toggling -->
                    <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                        <ul class="nav navbar-nav">
                            <li><a href="index.php">Home</a></li>
                            <li><a href="about.html">About</a></li>
                            <li><a href="current.html">Random Stuff</a></li>
                            <li><a href="contact.html">Contact</a></li>
                            <li><a href="login.php">Post</a></li>
                            <li class="active"><a href="#">Log</a></li>
                        </ul>
                    </div>
                    <!-- /.navbar-collapse -->
                </div>
                <!-- /.container -->
            </nav>

            <!-- Page Content -->
            <div class="container" id="container">
                <div class="row" id="header">
                    <div class="col-lg-12 text-center" id="main">
                        <h1>Here's what people have to say</h1>
                        <div class="well">
                            <p class="lead">
                                <?php
                                $link = mysqli_connect('setapproject.org', 'csc412', 'csc412', 'csc412');
                                if (mysqli_connect_errno($con)) {
                                    echo "Failed to connect to MySQL: " . mysqli_connect_error();
                                }
                                $sql = "SELECT * FROM Georgedb";
                                $result = mysqli_query($link, $sql);
                                while ($row = mysqli_fetch_array($result)) {
                                    echo $row[0] . " " . $row[1];
                                    echo "<br>";
                                }

                                mysqli_close($link);
                                ?>
                            </p>
                        </div>
                    </div>
                </div>
                <!-- /.row -->
            </div>
            <div class="push"></div>
        </div>

        <div class="container footer">
            <!-- Footer -->
            <footer>
                <hr>
                <div class="row">
                    <div class="col-lg-12">
                        <p>Copyright &copy; gj1productions 2015</p>
                    </div>
                </div>
                <!-- /.row -->
            </footer>
        </div>


        <!-- /.container -->

        <!-- jQuery Version 1.11.1 -->
        <script src="js/jquery.js"></script>

        <!-- Bootstrap Core JavaScript -->
        <script src="js/bootstrap.min.js"></script>
    </body>
</html>