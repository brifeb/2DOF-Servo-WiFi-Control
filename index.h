String MAIN_page = R"=====(

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
    <title>Servo Control</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black-translucent">
    <style>
        html, body {
        background: #f3efef; text-align: center; font-family: 'Verdana';  height: 100%;}
        ol {text-align: left;}
        * { -webkit-box-sizing: border-box; -moz-box-sizing: border-box;}
        .vslide_container {
            height: 400px;
            display: block;
        }
        .slide_container {
          width: 100%;
          height: 100px;
        }

        .slider {
          -webkit-appearance: none;
          width: 100%;
          height: 25px;
          background: #d3d3d3;
          outline: none;
          opacity: 0.7;
          -webkit-transition: .2s;
          transition: opacity .2s;
        }

        /* The slider handle (use -webkit- (Chrome, Opera, Safari, Edge) and -moz- (Firefox) to override default look) */
        .slider::-webkit-slider-thumb {
          -webkit-appearance: none;
          appearance: none;
          width: 100px;
          height: 100px;
          background: #04AA6D;
          cursor: pointer;
          border:none;
        }

        .slider::-moz-range-thumb {
          width: 100px;
          height: 100px;
          background: #04AA6D;
          cursor: pointer;
        }

        .vslider {
        margin-top: 150px;
        -webkit-appearance: none;
        width: 300px;
        -webkit-transform:rotate(-90deg);
        }
    </style>

<body>
    <p>X: <span id="xVal"></span> Y: <span id="yVal"></span></p>
    <div class="vslide_container">
        <input type="range" min="0" max="180" value="90" class="vslider slider " id="yRange">

    </div>
    <div class="slide_container">
        <input type="range" min="0" max="180" value="90" class="slider" id="xRange">
    </div>
    <div>

        <p>2 dof servo control</p>
        <p>@ndoware 2021</p>

    </div>

    <script>
        var sliderX = document.getElementById("xRange");
        var sliderY = document.getElementById("yRange");
        var outputX = document.getElementById("xVal");
        var outputY = document.getElementById("yVal");
        outputX.innerHTML = sliderX.value;
        outputY.innerHTML = sliderY.value;
        var X = 90;
        var Y = 90;

        sliderX.oninput = function() {
          X = this.value;
          outputX.innerHTML = X;
          fetch('sliderdata?x=' + X + '&y=' + Y);
        }
        sliderY.oninput = function() {
          Y = this.value;
          outputY.innerHTML = Y;
          fetch('sliderdata?x=' + X + '&y=' + Y);
        }
    </script>
</body>
</html>

)=====";
