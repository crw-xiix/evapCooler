//Must output the website with no external refs, just plain html...
//Use % % % (with no spaces) to represent a line converted, it will be repeated
#include "output.h"

void outputSite(void (*printFunction)(const char *) ) {
	printFunction("<!doctype html>");
	printFunction("");
	printFunction("");
	printFunction("");
	printFunction("");
	printFunction("<html lang=\"en\">");
	printFunction("<head>");
	printFunction("    <meta charset=\"utf-8\">");
	printFunction("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
	printFunction("    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css\" integrity=\"sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO\" crossorigin=\"anonymous\">");
	printFunction("    <title>CRW System Monitor</title>");
	printFunction("    <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script>");
	printFunction("    <script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js\" integrity=\"sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49\" crossorigin=\"anonymous\"></script>");
	printFunction("    <script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js\" integrity=\"sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy\" crossorigin=\"anonymous\"></script>");
	printFunction("    <script src=\"//cdn.rawgit.com/Mikhus/canvas-gauges/gh-pages/download/2.1.5/radial/gauge.min.js\"></script>");
	printFunction("");
	printFunction("    <script>");
	printFunction("        function refresh() {");
	printFunction("            $.getJSON(\"/data.json\", function (data) {");
	printFunction("                console.log(data);");
	printFunction("                if (data.moving > 0) {");
	printFunction("                    animateOn();");
	printFunction("                } else {");
	printFunction("                    animateOff();");
	printFunction("                }");
	printFunction("            });");
	printFunction("        }");
	printFunction("");
	printFunction("        function timerHit() {");
	printFunction("            loadIt();");
	printFunction("            logButton();");
	printFunction("        }");
	printFunction("");
	printFunction("        function loadIt() {");
	printFunction("            $.getJSON(\"/data.json\", function (data) {");
	printFunction("                gauges[0].value = (data.Temp);");
	printFunction("                gauges[1].value = (data.Water);");
	printFunction("                gauges[2].value = (data.Time);");
	printFunction("                gauges[3].value = (data.LastOutTemp);");
	printFunction("                gauges[4].value = (data.LastRemoteTemp);");
	printFunction("                gauges[5].value = (data.ThermostatSetting);");
	printFunction("                if (data.Pump) {");
	printFunction("                    gauges[6].value = 133.0;");
	printFunction("                } else {");
	printFunction("                    gauges[6].value = 0.0;");
	printFunction("                }");
	printFunction("                gauges[7].value = (data.fanRPM);");
	printFunction("                gauges[8].value = (data.LastAtticTemp);");
	printFunction("                $(\"#dPump\").html(\"Cooler Pump:\" + data.Pump);");
	printFunction("                //$(\"#dFan\").html(\"Cooler Fan:\" + data.Fan);");
	printFunction("                $(\"#dThermo\").html(\"Thermo:\" + data.ThermostatCool); //ThermostatCool");
	printFunction("            });");
	printFunction("        }");
	printFunction("");
	printFunction("        function logButton() {");
	printFunction("            $.get(\"/log.json\", function (data) {");
	printFunction("                $(\"#dLog\").html(data);");
	printFunction("            });");
	printFunction("        }");
	printFunction("");
	printFunction("        $(document).ready(function () {");
	printFunction("            timerHit();");
	printFunction("            setInterval(timerHit, 5000);");
	printFunction("            $(\"#bLog\").click(logButton);");
	printFunction("        });");
	printFunction("");
	printFunction("    </script>");
	printFunction("");
	printFunction("</head>");
	printFunction("<!-- test -->");
	printFunction("<body>");
	printFunction("    <div class=\"container\">");
	printFunction("        <div class=\"jumbotron\">");
	printFunction("            <h1>CRW Water Monitoring</h1>");
	printFunction("            <h2></h2>");
	printFunction("            {%3}");
	printFunction("        </div>");
	printFunction("        <div class=\"row text-center\">");
	printFunction("            <div class=\"col\" id=\"dTemp\">");
	printFunction("                <canvas id=\"tempGauge\"");
	printFunction("                        data-type=\"radial-gauge\"");
	printFunction("                        data-width=\"300\"");
	printFunction("                        data-height=\"300\"");
	printFunction("                        data-units=\"Cooler Exit F\"");
	printFunction("                        data-min-value=\"-40\"");
	printFunction("                        data-max-value=\"120\"");
	printFunction("                        data-valueDec=\"1\"");
	printFunction("                        data-major-ticks=\"-40,-20,0,20,40,60,80,100,120\"");
	printFunction("                        data-minor-ticks=\"2\"");
	printFunction("                        data-stroke-ticks=\"true\"");
	printFunction("                        data-highlights='[");
	printFunction("        {\"from\": 80, \"to\": 120, \"color\": \"rgba(200, 50, 50, .75)\"},");
	printFunction("        {\"from\": -20, \"to\": 50, \"color\": \"rgba(50, 50,200, .75)\"}");
	printFunction("");
	printFunction("    ]'");
	printFunction("                        data-color-plate=\"#fff\"");
	printFunction("                        data-border-shadow-width=\"0\"");
	printFunction("                        data-borders=\"false\"");
	printFunction("                        data-needle-type=\"arrow\"");
	printFunction("                        data-needle-width=\"2\"");
	printFunction("                        data-needle-circle-size=\"7\"");
	printFunction("                        data-needle-circle-outer=\"true\"");
	printFunction("                        data-needle-circle-inner=\"false\"");
	printFunction("                        data-animation-duration=\"1500\"");
	printFunction("                        data-animation-rule=\"linear\"></canvas>");
	printFunction("            </div>");
	printFunction("            <div class=\"col\" id=\"dWater\">");
	printFunction("                <canvas id=\"windGauge\"");
	printFunction("                        data-type=\"radial-gauge\"");
	printFunction("                        data-width=\"300\"");
	printFunction("                        data-height=\"300\"");
	printFunction("                        data-units=\"Water Gallons\"");
	printFunction("                        data-min-value=\"0\"");
	printFunction("                        data-max-value=\"180\"");
	printFunction("                        data-valueDec=\"1\"");
	printFunction("                        data-major-ticks=\"0,20,40,60,80,100,120,140,160,180\"");
	printFunction("                        data-minor-ticks=\"5\"");
	printFunction("                        data-stroke-ticks=\"true\"");
	printFunction("                        data-highlights='[");
	printFunction("        {\"from\": 0, \"to\": 40, \"color\": \"rgba(200, 50, 50, .75)\"},");
	printFunction("        {\"from\": 40, \"to\": 95, \"color\": \"rgba(200, 50,50, .50)\"},");
	printFunction("        {\"from\": 95, \"to\": 165, \"color\": \"rgba(50, 200,50, .25)\"}]'");
	printFunction("                        data-color-plate=\"#fff\"");
	printFunction("                        data-border-shadow-width=\"0\"");
	printFunction("                        data-borders=\"false\"");
	printFunction("                        data-needle-type=\"arrow\"");
	printFunction("                        data-needle-width=\"2\"");
	printFunction("                        data-needle-circle-size=\"7\"");
	printFunction("                        data-needle-circle-outer=\"true\"");
	printFunction("                        data-needle-circle-inner=\"false\"");
	printFunction("                        data-animation-duration=\"1500\"");
	printFunction("                        data-animation-rule=\"linear\"></canvas>");
	printFunction("            </div>");
	printFunction("");
	printFunction("            <div class=\"col\" id=\"dTime\">");
	printFunction("                <canvas id=\"timeGauge\"");
	printFunction("                        data-type=\"radial-gauge\"");
	printFunction("                        data-width=\"300\"");
	printFunction("                        data-height=\"300\"");
	printFunction("                        data-units=\"Time\"");
	printFunction("                        data-min-value=\"0\"");
	printFunction("                        data-max-value=\"24\"");
	printFunction("                        data-valueDec=\".01\"");
	printFunction("                        data-major-ticks=\"0,3,6,9,12,15,18,21,24\"");
	printFunction("                        data-minor-ticks=\"1\"");
	printFunction("                        data-stroke-ticks=\"true\"");
	printFunction("                        data-color-plate=\"#fff\"");
	printFunction("                        data-border-shadow-width=\"0\"");
	printFunction("                        data-borders=\"false\"");
	printFunction("                        data-needle-type=\"arrow\"");
	printFunction("                        data-needle-width=\"2\"");
	printFunction("                        data-needle-circle-size=\"7\"");
	printFunction("                        data-needle-circle-outer=\"true\"");
	printFunction("                        data-needle-circle-inner=\"false\"");
	printFunction("                        data-animation-duration=\"250\"");
	printFunction("                        data-animation-rule=\"linear\"");
	printFunction("                        data-highlights='[");
	printFunction("        {\"from\": 0, \"to\": {%4}, \"color\": \"rgba(50, 50, 200, .75)\"},");
	printFunction("");
	printFunction("        {\"from\": {%5}, \"to\": 24, \"color\": \"rgba(50,50,200,.75)\"}]'></canvas>");
	printFunction("            </div>");
	printFunction("        </div>");
	printFunction("        <div class=\"row text-center\">");
	printFunction("            <div class=\"col\" id=\"dOTemp\">");
	printFunction("                <canvas id=\"tempOGauge\"");
	printFunction("                        data-type=\"radial-gauge\"");
	printFunction("                        data-width=\"300\"");
	printFunction("                        data-height=\"300\"");
	printFunction("                        data-units=\"Outside Temp F\"");
	printFunction("                        data-min-value=\"-40\"");
	printFunction("                        data-max-value=\"120\"");
	printFunction("                        data-valueDec=\"1\"");
	printFunction("                        data-major-ticks=\"-40,-20,0,20,40,60,80,100,120\"");
	printFunction("                        data-minor-ticks=\"2\"");
	printFunction("                        data-stroke-ticks=\"true\"");
	printFunction("                        data-highlights='[");
	printFunction("        {\"from\": 80, \"to\": 120, \"color\": \"rgba(200, 50, 50, .75)\"},");
	printFunction("        {\"from\": -20, \"to\": 50, \"color\": \"rgba(50, 50,200, .75)\"}");
	printFunction("");
	printFunction("    ]'");
	printFunction("                        data-color-plate=\"#fff\"");
	printFunction("                        data-border-shadow-width=\"0\"");
	printFunction("                        data-borders=\"false\"");
	printFunction("                        data-needle-type=\"arrow\"");
	printFunction("                        data-needle-width=\"2\"");
	printFunction("                        data-needle-circle-size=\"7\"");
	printFunction("                        data-needle-circle-outer=\"true\"");
	printFunction("                        data-needle-circle-inner=\"false\"");
	printFunction("                        data-animation-duration=\"1500\"");
	printFunction("                        data-animation-rule=\"linear\"></canvas>");
	printFunction("            </div>");
	printFunction("            <div class=\"col\" id=\"dUTemp\">");
	printFunction("                <canvas id=\"tempUGauge\"");
	printFunction("                        data-type=\"radial-gauge\"");
	printFunction("                        data-width=\"300\"");
	printFunction("                        data-height=\"300\"");
	printFunction("                        data-units=\"Upstairs Temp F\"");
	printFunction("                        data-min-value=\"-40\"");
	printFunction("                        data-max-value=\"120\"");
	printFunction("                        data-valueDec=\"1\"");
	printFunction("                        data-major-ticks=\"-40,-20,0,20,40,60,80,100,120\"");
	printFunction("                        data-minor-ticks=\"2\"");
	printFunction("                        data-stroke-ticks=\"true\"");
	printFunction("                        data-highlights='[");
	printFunction("        {\"from\": 80, \"to\": 120, \"color\": \"rgba(200, 50, 50, .75)\"},");
	printFunction("        {\"from\": -20, \"to\": 50, \"color\": \"rgba(50, 50,200, .75)\"}");
	printFunction("");
	printFunction("    ]'");
	printFunction("                        data-color-plate=\"#fff\"");
	printFunction("                        data-border-shadow-width=\"0\"");
	printFunction("                        data-borders=\"false\"");
	printFunction("                        data-needle-type=\"arrow\"");
	printFunction("                        data-needle-width=\"2\"");
	printFunction("                        data-needle-circle-size=\"7\"");
	printFunction("                        data-needle-circle-outer=\"true\"");
	printFunction("                        data-needle-circle-inner=\"false\"");
	printFunction("                        data-animation-duration=\"1500\"");
	printFunction("                        data-animation-rule=\"linear\"></canvas>");
	printFunction("            </div>");
	printFunction("            <div class=\"col\" id=\"dSUTemp\">");
	printFunction("                <canvas id=\"tempSUGauge\"");
	printFunction("                        data-type=\"radial-gauge\"");
	printFunction("                        data-width=\"300\"");
	printFunction("                        data-height=\"300\"");
	printFunction("                        data-units=\"Thermostat Setting F\"");
	printFunction("                        data-min-value=\"-40\"");
	printFunction("                        data-max-value=\"120\"");
	printFunction("                        data-valueDec=\"1\"");
	printFunction("                        data-major-ticks=\"-40,-20,0,20,40,60,80,100,120\"");
	printFunction("                        data-minor-ticks=\"2\"");
	printFunction("                        data-stroke-ticks=\"true\"");
	printFunction("                        data-highlights='[");
	printFunction("        {\"from\": 80, \"to\": 120, \"color\": \"rgba(200, 50, 50, .75)\"},");
	printFunction("        {\"from\": -20, \"to\": 50, \"color\": \"rgba(50, 50,200, .75)\"}");
	printFunction("");
	printFunction("    ]'");
	printFunction("                        data-color-plate=\"#fff\"");
	printFunction("                        data-border-shadow-width=\"0\"");
	printFunction("                        data-borders=\"false\"");
	printFunction("                        data-needle-type=\"arrow\"");
	printFunction("                        data-needle-width=\"2\"");
	printFunction("                        data-needle-circle-size=\"7\"");
	printFunction("                        data-needle-circle-outer=\"true\"");
	printFunction("                        data-needle-circle-inner=\"false\"");
	printFunction("                        data-animation-duration=\"1500\"");
	printFunction("                        data-animation-rule=\"linear\"></canvas>");
	printFunction("            </div>");
	printFunction("        </div>");
	printFunction("");
	printFunction("        <div class=\"row text-center\">");
	printFunction("            <div class=\"col\" id=\"dwPump\">");
	printFunction("                    <canvas id=\"pumpGauge\"");
	printFunction("                            data-type=\"radial-gauge\"");
	printFunction("                            data-width=\"300\"");
	printFunction("                            data-height=\"300\"");
	printFunction("                            data-units=\"Pump GPM\"");
	printFunction("                            data-min-value=\"0\"");
	printFunction("                            data-max-value=\"150\"");
	printFunction("                            data-valueDec=\"1\"");
	printFunction("                            data-major-ticks=\"0,50,100,150\"");
	printFunction("                            data-minor-ticks=\"2\"");
	printFunction("                            data-highlights='[ ]'");
	printFunction("                            data-stroke-ticks=\"true\"");
	printFunction("                            data-color-plate=\"#eef\"");
	printFunction("                            data-border-shadow-width=\"0\"");
	printFunction("                            data-borders=\"false\"");
	printFunction("                            data-needle-type=\"arrow\"");
	printFunction("                            data-needle-width=\"2\"");
	printFunction("                            data-needle-circle-size=\"7\"");
	printFunction("                            data-needle-circle-outer=\"true\"");
	printFunction("                            data-needle-circle-inner=\"false\"");
	printFunction("                            data-animation-duration=\"1500\"");
	printFunction("                            data-animation-rule=\"linear\"></canvas>");
	printFunction("                </div>");
	printFunction("            ");
	printFunction("            <div class=\"col\" id=\"dfanRPM\">");
	printFunction("                <canvas id=\"fanRPMGauge\"");
	printFunction("                        data-type=\"radial-gauge\"");
	printFunction("                        data-width=\"300\"");
	printFunction("                        data-height=\"300\"");
	printFunction("                        data-units=\"Fan RPM\"");
	printFunction("                        data-min-value=\"0\"");
	printFunction("                        data-max-value=\"1000\"");
	printFunction("                        data-valueDec=\"1\"");
	printFunction("                        data-major-ticks=\"0,100,200,300,400,500,600,700,800,900,1000\"");
	printFunction("                        data-minor-ticks=\"2\"");
	printFunction("                        data-stroke-ticks=\"true\"");
	printFunction("                        data-highlights='[{\"from\": 520, \"to\": 540, \"color\": \"rgba(50, 200, 50, .75)\"]'");
	printFunction("                        data-color-plate=\"#fff\"");
	printFunction("                        data-border-shadow-width=\"0\"");
	printFunction("                        data-borders=\"false\"");
	printFunction("                        data-needle-type=\"arrow\"");
	printFunction("                        data-needle-width=\"2\"");
	printFunction("                        data-needle-circle-size=\"7\"");
	printFunction("                        data-needle-circle-outer=\"true\"");
	printFunction("                        data-needle-circle-inner=\"false\"");
	printFunction("                        data-animation-duration=\"1500\"");
	printFunction("                        data-animation-rule=\"linear\"></canvas>");
	printFunction("            </div>");
	printFunction("            <div class=\"col\" id=\"dTempAttic\">");
	printFunction("                <canvas id=\"tempGaugeAttic\"");
	printFunction("                        data-type=\"radial-gauge\"");
	printFunction("                        data-width=\"300\"");
	printFunction("                        data-height=\"300\"");
	printFunction("                        data-units=\"Attic Temp F\"");
	printFunction("                        data-min-value=\"-40\"");
	printFunction("                        data-max-value=\"120\"");
	printFunction("                        data-valueDec=\"1\"");
	printFunction("                        data-major-ticks=\"-40,-20,0,20,40,60,80,100,120\"");
	printFunction("                        data-minor-ticks=\"2\"");
	printFunction("                        data-stroke-ticks=\"true\"");
	printFunction("                        data-highlights='[");
	printFunction("        {\"from\": 80, \"to\": 120, \"color\": \"rgba(200, 50, 50, .75)\"},");
	printFunction("        {\"from\": -20, \"to\": 50, \"color\": \"rgba(50, 50,200, .75)\"}");
	printFunction("");
	printFunction("    ]'");
	printFunction("                        data-color-plate=\"#fff\"");
	printFunction("                        data-border-shadow-width=\"0\"");
	printFunction("                        data-borders=\"false\"");
	printFunction("                        data-needle-type=\"arrow\"");
	printFunction("                        data-needle-width=\"2\"");
	printFunction("                        data-needle-circle-size=\"7\"");
	printFunction("                        data-needle-circle-outer=\"true\"");
	printFunction("                        data-needle-circle-inner=\"false\"");
	printFunction("                        data-animation-duration=\"1500\"");
	printFunction("                        data-animation-rule=\"linear\"></canvas>");
	printFunction("            </div>");
	printFunction("        </div>");
	printFunction("        <div id=\"dThermo\">Thermo</div>");
	printFunction("");
	printFunction("        <br><br>");
	printFunction("");
	printFunction("        <div>Log File</div>");
	printFunction("        <div id=\"dLog\"></div>");
	printFunction("        <br />");
	printFunction("        <div id=\"dRaw\"></div>");
	printFunction("    </div>");
	printFunction("</body>");
	printFunction("</html>");
}
