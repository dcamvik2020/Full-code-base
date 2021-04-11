window.onload = function () {
	document.getElementById("comments").innerHTML = "\
	<h1>Комментарии</h1>\
	<form action=\"/cgi-bin/comments\" method=\"post\" enctype=\"multipart/form-data\">\
		<table>\
			<tr>\
				<td>Имя:</td>\
				<td><input type=\"text\" name=\"name\"></td>\
			</tr>\
			<tr>\
				<td>Комментарий:</td>\
				<td style=\"width:100%;\"><textarea name=\"text\" style=\"width:100%;\"></textarea></td>\
			</tr>\
		</table>\
		<input type=\"submit\">\
	</form>\
\
	<table id=\"comments-content\" style=\"width:100%;\"><tr><td></td></tr></table>\
";
	var i = location.href.lastIndexOf('/');
	var baseName = location.href.substr(i + 1);
	if (baseName == "")
		baseName = "index.html";
	i = baseName.lastIndexOf('.');
	if (i != -1)
		baseName = baseName.substr(0, i);

	var request = new XMLHttpRequest();
	request.open('GET', baseName + '.txt', true);
	request.setRequestHeader('Cache-Control', 'no-store, no-cache, must-revalidate, post-check=0, pre-check=0');
	request.setRequestHeader('Expires', 0);
	request.send(null);
	request.onreadystatechange = function () {
		if (request.readyState === 4 && request.status === 200) {
			var type = request.getResponseHeader('Content-Type');
			if (type.indexOf("text") !== -1) {
				var responseText = request.responseText.replace(/\r/g, "");
				document.getElementById("comments-content").innerHTML =
						responseText.split("\n").map(function(textLine) {
							var textFields = textLine.split(/\t+/);
							return JSON.parse("\"<tr><td>" + textFields.join("</td><td>") + "</td></tr>\"").replace(/\r/g, "").replace(/\n/g, "<br>");
						}).join("\n");
			}
		}
	}
}
