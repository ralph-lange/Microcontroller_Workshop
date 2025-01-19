const char* WEBSITE = R"(<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1"/>
    <meta http-equiv="refresh" content="1"/>
    <title>My Website</title>
    <style>
body {
  font-family: Monospace;
  font-size: 1.5em;
  margin: 0px auto;
  text-align: center;
}

h1 {
  font-size: 1.5em;
}

p.uptime {
  text-align: right;
  font-size: 50%;
  margin: 3em 4px 4px 4px;
}
    </style>
  </head>
  <body>
    <h1>My Website</h1>
	  <p>Value: [VALUE]<p>
    <p class="uptime">Uptime of ESP32: [UPTIME]&ThinSpace;s<p>
  </body>
</html>
)";
