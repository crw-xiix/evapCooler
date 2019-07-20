//Must output the website with no external refs, just plain html...
//Use % % % (with no spaces) to represent a line converted, it will be repeated
#include "outputEdit.h"

void outputEditSite(void (*printFunction)(const char *) ) {
	printFunction("<!doctype html>");
	printFunction("<html lang=\"en\">");
	printFunction("<head>");
	printFunction("    <meta charset=\"utf-8\">");
	printFunction("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
	printFunction("    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css\" integrity=\"sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO\" crossorigin=\"anonymous\">");
	printFunction("    <title>{%1} - Edit Config</title>");
	printFunction("    <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script>");
	printFunction("    <script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js\" integrity=\"sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49\" crossorigin=\"anonymous\"></script>");
	printFunction("    <script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js\" integrity=\"sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy\" crossorigin=\"anonymous\"></script>");
	printFunction("");
	printFunction("");
	printFunction("    <script>");
	printFunction("        String.prototype.formatUnicorn = String.prototype.formatUnicorn ||");
	printFunction("            function () {");
	printFunction("                \"use strict\";");
	printFunction("                var str = this.toString();");
	printFunction("                if (arguments.length) {");
	printFunction("                    var t = typeof arguments[0];");
	printFunction("                    var key;");
	printFunction("                    var args = (\"string\" === t || \"number\" === t) ?");
	printFunction("                        Array.prototype.slice.call(arguments)");
	printFunction("                        : arguments[0];");
	printFunction("");
	printFunction("                    for (key in args) {");
	printFunction("                        str = str.replace(new RegExp(\"\\"\\"{\" + key + \"\\"\\"}\", \"gi\"), args[key]);");
	printFunction("                    }");
	printFunction("                }");
	printFunction("                return str;");
	printFunction("            };");
	printFunction("");
	printFunction("        function refresh() {");
	printFunction("            $.getJSON(\"/data.json\", function (data) {");
	printFunction("                console.log(data);");
	printFunction("            });");
	printFunction("        }");
	printFunction("");
	printFunction("        function timerHit() {");
	printFunction("        }");
	printFunction("");
	printFunction("        function loadIt() {");
	printFunction("            $.getJSON(\"/data.json\", function (data) {");
	printFunction("            });");
	printFunction("        }");
	printFunction("");
	printFunction("        function logButton() {");
	printFunction("            $.get(\"/log.json\", function (data) {");
	printFunction("                $(\"#dLog\").html(data);");
	printFunction("            });");
	printFunction("        }");
	printFunction("        function FillPage() {");
	printFunction("        }");
	printFunction("        function huh() {");
	printFunction("            $.getJSON(\"/setup.json\", function (data) {");
	printFunction("                $(\"#iTitle\").html(data.Title);");
	printFunction("                $(\"#iVersion\").html(data.Version);");
	printFunction("                $(\"#DName\").val(data.Title);");
	printFunction("                $(\"#DVersion\").val(data.Version);");
	printFunction("                $(\"#DST\").prop('checked', data.DST);");
	printFunction("                $(\"#DDayTemp\").val(data.DayTemp);");
	printFunction("                $(\"#DNightMax\").val(data.NightMax);");
	printFunction("                $(\"#DNightMin\").val(data.NightMin);");
	printFunction("                $(\"#DFanMode\").val(data.FanMode);");
	printFunction("                $(\"#DPumpMode\").val(data.PumpMode);");
	printFunction("                $(\"#DVacationMode\").val(data.VacationMode);    //off/on");
	printFunction("            });");
	printFunction("        }");
	printFunction("");
	printFunction("        function loadTaskItems(items) {");
	printFunction("            for (i = 0; i < items.length; i++) {");
	printFunction("                $('.taskList').append($('<option>', items[i]));");
	printFunction("            }");
	printFunction("        }");
	printFunction("        function loadTaskForm(items) {");
	printFunction("            for (i = 0; i < items.length; i++) {");
	printFunction("                var st = items[i].task + ' ';//Just so we have something to split, just in case");
	printFunction("                var postVert = st.split(\"|\");");
	printFunction("                var postColon = postVert[0].split(\":\");");
	printFunction("                var ttask = postColon[0];");
	printFunction("                var others = postColon[1].split(\",\");");
	printFunction("                //Now we can set the values on screen");
	printFunction("                $(\"#task\" + i).val(ttask);");
	printFunction("                $(\"#time\" + i).val(others[0]);");
	printFunction("                $(\"#sunrise\" + i).prop('checked', (others[1] != 0));");
	printFunction("                $(\"#sunset\" + i).prop('checked', (others[2] != 0));");
	printFunction("                $(\"#option\" + i).val(postVert[1].trim());");
	printFunction("            }");
	printFunction("        }");
	printFunction("");
	printFunction("        function sendData() {");
	printFunction("            var st = \"\";");
	printFunction("            st += \"Title=\" + $(\"#DName\").val();");
	printFunction("            st += \"\\"n\";");
	printFunction("            st += \"Version=\" + $(\"#DVersion\").val();");
	printFunction("            st += \"\\"n\";");
	printFunction("            st += \"DST=\";");
	printFunction("            if ($(\"#DST\").prop('checked')) {");
	printFunction("                st += \"1\";");
	printFunction("            } else { st += \"0\"; }");
	printFunction("            st += \"\\"n\";");
	printFunction("");
	printFunction("            for (i = 0; i < 20; i++) {");
	printFunction("");
	printFunction("                var t = \"Task=\";");
	printFunction("                var taskSelected = $(\"#task\" + i + \" option:selected\").val();");
	printFunction("                if (taskSelected == 0) continue;");
	printFunction("");
	printFunction("                t = t + taskSelected;");
	printFunction("");
	printFunction("                t = t + \":\" + $(\"#time\" + i).val() + \",\";");
	printFunction("                if ($(\"#sunrise\" + i).prop('checked')) {");
	printFunction("                    t += \"1,\";");
	printFunction("                } else {");
	printFunction("                    t += \"0,\";");
	printFunction("                }");
	printFunction("                if ($(\"#sunset\" + i).prop('checked')) {");
	printFunction("                    t += \"1|\";");
	printFunction("                } else {");
	printFunction("                    t += \"0|\";");
	printFunction("                }");
	printFunction("                t += $(\"#option\" + i).val();");
	printFunction("                st += t + \"\\"n\";");
	printFunction("            }");
	printFunction("            st += \"END\\"n\";");
	printFunction("            var xhr = new XMLHttpRequest();");
	printFunction("            xhr.open('POST', '/SetConfig', true);");
	printFunction("            xhr.setRequestHeader('Content-Type', 'text/html; charset=UTF-8');");
	printFunction("            // send the collected data as JSON");
	printFunction("            xhr.send(st);");
	printFunction("            console.log(st);");
	printFunction("            xhr.onloadend = function () {");
	printFunction("                window.location.href = \"/\";");
	printFunction("            };");
	printFunction("        }");
	printFunction("        function back() {");
	printFunction("            window.location.href = \"/\";");
	printFunction("        }");
	printFunction("        $(document).ready(function () {");
	printFunction("            huh();");
	printFunction("            $(\"#bSave\").click(sendData);");
	printFunction("            $(\"#bBack\").click(back);");
	printFunction("            FillPage();");
	printFunction("        });");
	printFunction("");
	printFunction("    </script>");
	printFunction("");
	printFunction("</head>");
	printFunction("<!-- test -->");
	printFunction("<body>");
	printFunction("    <div class=\"container\">");
	printFunction("        <div class=\"jumbotron\">");
	printFunction("            <h1>{%1}</h1>");
	printFunction("            <h2>{%2}</h2>");
	printFunction("        </div>");
	printFunction("        <div class=\"jumbotron\">");
	printFunction("            Edit Setup");
	printFunction("            <label for=\"DName\">Device Name:</label>");
	printFunction("            <input type=\"text\" class=\"form-control\" id=\"DName\">");
	printFunction("            <label for=\"DVersion\">Device Version:</label>");
	printFunction("            <input type=\"text\" class=\"form-control\" id=\"DVersion\">");
	printFunction("            <br />");
	printFunction("            <label class=\"checkbox-inline\"><input type=\"checkbox\" id=\"DST\" value=\"\">Daylight Savings Time</label><br />");
	printFunction("            <br />");
	printFunction("            <div class=\"well\">");
	printFunction("                <div class=\"row\">");
	printFunction("                    <div class=\"col\">");
	printFunction("                        <h2>Maintenance</h2>");
	printFunction("                    </div>");
	printFunction("                </div>");
	printFunction("                <div class=\"row\">");
	printFunction("                    <div class=\"col\">");
	printFunction("                        <label for=\"DFanMode\">Fan Mode</label>");
	printFunction("                        <select class=\"form-control\" id=\"DFanMode\">");
	printFunction("                            <option value=\"0\">Off</option>");
	printFunction("                            <option value=\"1\">Auto</option>");
	printFunction("                            <option value=\"2\">On</option>");
	printFunction("                        </select>");
	printFunction("                    </div>");
	printFunction("                    <div class=\"col\">");
	printFunction("                        <label for=\"DPumpMode\">Pump Mode</label>");
	printFunction("                        <select class=\"form-control\" id=\"DPumpMode\">");
	printFunction("                            <option value=\"0\">Off</option>");
	printFunction("                            <option value=\"1\">Auto</option>");
	printFunction("                            <option value=\"2\">On</option>");
	printFunction("                        </select>");
	printFunction("                    </div>");
	printFunction("                    <div class=\"col\">");
	printFunction("                        <label for=\"DVacationMode\">Vacation Mode</label>");
	printFunction("                        <select class=\"form-control\" id=\"DVacationMode\">");
	printFunction("                            <option value=\"0\">Off</option>");
	printFunction("                            <option value=\"1\">On</option>");
	printFunction("                        </select>");
	printFunction("                    </div>");
	printFunction("                </div>");
	printFunction("            </div>");
	printFunction("            <br />");
	printFunction("            <br />");
	printFunction("            <div class=\"well\">");
	printFunction("                <div class=\"row\">");
	printFunction("                    <div class=\"col\">");
	printFunction("                        <h2>Thermostat</h2>");
	printFunction("                    </div>");
	printFunction("                </div>");
	printFunction("                <div class=\"row\">");
	printFunction("                    <div class=\"col\">");
	printFunction("                        <label for=\"DDayTemp\">Daytime F</label>");
	printFunction("                        <input type=\"text\" class=\"form-control\" id=\"DDayTemp\">");
	printFunction("                    </div>");
	printFunction("                    <div class=\"col\">");
	printFunction("                        <label for=\"DNightMax\">Night Max F</label>");
	printFunction("                        <input type=\"text\" class=\"form-control\" id=\"DNightMax\">");
	printFunction("                    </div>");
	printFunction("                    <div class=\"col\">");
	printFunction("                        <label for=\"DNightMin\">Night Min F</label>");
	printFunction("                        <input type=\"text\" class=\"form-control\" id=\"DNightMin\">");
	printFunction("                    </div>");
	printFunction("                </div>");
	printFunction("                <br />");
	printFunction("");
	printFunction("                <div class=\"row text-right\">");
	printFunction("                    <div class=\"col\">&nbsp;</div><div class=\"col\">&nbsp;</div>");
	printFunction("                    <div class=\"col\">");
	printFunction("                        <button type=\"button\" class=\"btn btn-success\" id=\"bSave\" data-toggle=\"modal\" data-target=\"#myModal\">Save</button>");
	printFunction("                        <button type=\"button\" class=\"btn btn-success\" id=\"bBack\">Back</button>");
	printFunction("                    </div>");
	printFunction("                </div>");
	printFunction("                <div class=\"modal fade\" id=\"myModal\" role=\"dialog\">");
	printFunction("                    <div class=\"modal-dialog\">");
	printFunction("");
	printFunction("                        <!-- Modal content-->");
	printFunction("                        <div class=\"modal-content\">");
	printFunction("                            <div class=\"modal-header\">");
	printFunction("                                <button type=\"button\" class=\"close\" data-dismiss=\"modal\">&times;</button>");
	printFunction("                                <h4 class=\"modal-title text-center\">Save settings to EEPROM</h4>");
	printFunction("                            </div>");
	printFunction("                            <div class=\"modal-body\">");
	printFunction("                                <label for=\"DNPassword\">EEPROM write password:</label>");
	printFunction("                                <input type=\"password\" class=\"form-control\" id=\"DPassword\">");
	printFunction("                            </div>");
	printFunction("                            <div class=\"modal-footer\">");
	printFunction("                                <button type=\"button\" class=\"btn btn-default\" data-dismiss=\"modal\">Cancel</button>");
	printFunction("                                <button type=\"button\" class=\"btn btn-default\" data-dismiss=\"modal\">Save</button>");
	printFunction("                            </div>");
	printFunction("                        </div>");
	printFunction("");
	printFunction("                    </div>");
	printFunction("                </div>");
	printFunction("            </div>");
	printFunction("        </div>");
	printFunction("    </div>");
	printFunction("");
	printFunction("");
	printFunction("</body>");
	printFunction("</html>");
	printFunction("");
}

