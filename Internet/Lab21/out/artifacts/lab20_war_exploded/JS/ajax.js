function setHeaderToAJAX(x, y, z, isAsync = true, isCombined = false) {
    const xmlHttpRequest = new XMLHttpRequest();
    xmlHttpRequest.open("POST", "http://localhost:8080/lab20_war_exploded/Sss_Header", isAsync);
    xmlHttpRequest.setRequestHeader("Value-x", x.value);
    xmlHttpRequest.setRequestHeader("Value-y", y.value);
    xmlHttpRequest.setRequestHeader("task", isCombined ? "4" : "1");

    try {
        xmlHttpRequest.onreadystatechange = () => {
            if (xmlHttpRequest.readyState === xmlHttpRequest.DONE && xmlHttpRequest.status === 200) {
                z.value = xmlHttpRequest.getResponseHeader("Value-z");
            }
        };

        xmlHttpRequest.send();
    } catch (error) {
        console.error(error);
    }
}


function setHeaderGetXml(n, isAsync = true, isCombined = false) {
    let xmlHttpRequest = new XMLHttpRequest();
    xmlHttpRequest.open("POST", "http://localhost:8080/lab20_war_exploded/Sss_XML", isAsync);
    xmlHttpRequest.setRequestHeader("XRand_n", n.value);
    xmlHttpRequest.setRequestHeader("task", isCombined ? "4" : "1");

    try {
        xmlHttpRequest.onreadystatechange = () => {
            if (xmlHttpRequest.readyState === xmlHttpRequest.DONE && xmlHttpRequest.status === 200) {
                document.getElementById("resultFromXmlReq").innerHTML = "";

                const items = Array.from(xmlHttpRequest.responseXML.getElementsByTagName("number"));
                items.forEach(item => {
                    document.getElementById("resultFromXmlReq").innerHTML += item.innerHTML + " ";
                });
            }
        };

        xmlHttpRequest.send();
    } catch (error) {
        console.error(error);
    }
}


function setHeaderGetJson(n, isAsync = true, isCombined = false) {
    let xmlHttpRequest = new XMLHttpRequest();
    xmlHttpRequest.open("POST", "http://localhost:8080/lab20_war_exploded/Sss_JSON", isAsync);
    xmlHttpRequest.setRequestHeader("XRand_n", n.value);
    xmlHttpRequest.setRequestHeader("task", isCombined ? "4" : "1");

    try {
        xmlHttpRequest.onreadystatechange = () => {
            if (xmlHttpRequest.readyState === xmlHttpRequest.DONE && xmlHttpRequest.status === 200) {
                document.getElementById("resultFromJsonReq").innerHTML = "";

                let parsedJsonObject = JSON.parse(xmlHttpRequest.responseText);
                parsedJsonObject.numbers.forEach((item) => {
                    document.getElementById("resultFromJsonReq").innerHTML += item + " ";
                });
            }
        };

        xmlHttpRequest.send();
    } catch(error) {
        console.error(error);
    }
}


function callAllAjaxes(x, y, z, n, isAsync = true) {
    setHeaderToAJAX(x, y, z, isAsync, true);
    setHeaderGetXml(n, isAsync, true);
    setHeaderGetJson(n, isAsync, true);
}


function sendAjaxJQuery(n) {
    document.getElementById("resultFromJQueryReq").innerHTML = "";

    $.ajax({
        url: 'http://localhost:8080/lab20_war_exploded/Sss_JSON',
        type: 'POST',
        dataType: 'json',
        headers: {
            'XRand_n': n.value,
            'task': '1',
        }
    }).done(response => {
        response.numbers.forEach((item) => {
            document.getElementById("resultFromJQueryReq").innerHTML += item + " ";
        });
    });
}