<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="description" content="">
        <meta name="author" content="">

        <title>George's Cool Website!!!</title>

        <!-- Bootstrap Core CSS -->
        <link href="css/bootstrap.min.css" rel="stylesheet">
        <!-- Custom CSS -->
        <link href="css/custom.css" rel="stylesheet">
        <style>
            h2 {
                color: purple;
                text-shadow: -1px 0 white, 0 1px white, 1px 0 white, 0 -1px white;
            }
            /*            * {
                            margin: 0;
                        }
                        html, body {
                            height: 100%;
                        }
                        .wrapper {
                            min-height: 100%;
                            height: auto !important;
                            height: 100%;
                            margin: 0 auto -3em;
                        }
                        .footer, .push {
                            height: 3em;
                        }*/
        </style>
        <link href="css/half-slider.css" rel="stylesheet">

        <link rel="icon" type="image/gif" href="pics/tumblr_inline_mgpk1wODbe1qdlkyg.gif">
    </head>

    <!-- Navigation -->
    <nav class="navbar navbar-inverse navbar-fixed-top" role="navigation" id="navigation">
        <div class="container">
            <!-- Brand and toggle get grouped for better mobile display -->
            <div class="navbar-header">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <a class="navbar-brand" href="#">George Jone</a>
                <!--                    <a class="navbar-brand" onclick="myFunction()" href="#">George Jone</a>-->
            </div>
            <!-- Collect the nav links, forms, and other content for toggling -->
            <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                <ul class="nav navbar-nav">
                    <li class="active"><a href="#">Home</a></li>
                    <li><a href="about.html">About</a></li>
                    <li><a href="current.html">Random Stuff</a></li>
                    <li><a href="contact.html">Contact</a></li>
                    <li><a href="login.php">Post</a></li>
                    <li><a href="log.php">Log</a></li>
                </ul>
            </div>
            <!-- /.navbar-collapse -->
        </div>
        <!-- /.container -->
    </nav>

    <!-- Half Page Image Background Carousel Header -->
    <header id="myCarousel" class="carousel slide">
        <!-- Indicators -->
        <ol class="carousel-indicators">
            <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
            <li data-target="#myCarousel" data-slide-to="1"></li>
            <li data-target="#myCarousel" data-slide-to="2"></li>
        </ol>
        <!-- Wrapper for Slides -->
        <div class="carousel-inner">
            <div class="item active">
                <!-- Set the first background image using inline CSS below. -->
                <div class="fill" style="background-image:url('pics/Binary_by_feigned_existence.png');"></div>
                <div class="carousel-caption">
                    <h2>Computer Science</h2>
                </div>
            </div>
            <div class="item">
                <!-- Set the second background image using inline CSS below. -->
                <div class="fill" style="background-image:url('pics/California-Outline-and-Flag-Solid.png');"></div>
                <div class="carousel-caption">
                    <h2>San Francisco State University</h2>
                </div>
            </div>
            <div class="item">
                <!-- Set the third background image using inline CSS below. -->
                <div class="fill" style="background-image:url('pics/tumblr_mon7jusAFb1s8shk6o1_400.gif');"></div>
                <div class="carousel-caption">
                    <h2>Dogs!</h2>
                </div>
            </div>
        </div>

        <!-- Controls -->
        <a class="left carousel-control" href="#myCarousel" data-slide="prev">
            <span class="icon-prev"></span>
        </a>
        <a class="right carousel-control" href="#myCarousel" data-slide="next">
            <span class="icon-next"></span>
        </a>

    </header>

    <body>

        <!--<div class="wrapper">-->
        <!-- Page Content -->
        <div class="container">
            <div class="row">
                <div class="col-lg-12">
                    <h1>Welcome to my *Awesome* Website!</h1>
                    <div class="well">
                        <p>
                            I had a great time creating this website and working with you all.
                        </p>
                        <p>
                            We may move on to different classes and eventually leave school to start our careers, but we will always have our websites to look back on and remember the great times we shared in this lab.
                        </p>
                        <p>
                            Post something memorable on my log page!
                        </p>
                    </div>
                </div>
            </div>
        </div>
        <!-- /.row -->

        <!--            <div class="push"></div>
                </div>-->

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



        <!-- jQuery -->
        <script src="js/jquery.js"></script>
        <!-- Bootstrap Core JavaScript -->
        <script src="js/bootstrap.min.js"></script>

        <!-- Script to Activate the Carousel -->
        <script>
            $('.carousel').carousel({
                interval: 5000 //changes the speed
            })
        </script>

        <!--Script to change nav color-->
        <script>
            function myFunction() {
                var bgcolorlist = new Array("#DFDFFF", "#FFFFBF", "#80FF80", "#EAEAFF", "#C9FFA8", "#F7F7F7", "#FFFFFF", "#DDDD00")
                document.getElementById("navigation").style.backgroundColor = bgcolorlist[Math.floor(Math.random() * bgcolorlist.length)]
            }
        </script>

        <!--Script to hide an element-->
        <script>
            $(document).ready(function () {
                $("#button2").click(function () {
                    $("#hideme1").hide();
                });
            });
        </script>
    </body>


</html>