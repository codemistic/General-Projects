// alert("link check");

var input = document.querySelector("textarea[name='input']");
var btn = document.querySelector(".btn");
var output = document.querySelector("textarea[name='output']");

function errorHandling(error){
    alert("There is some error in the server \n" + error);
}

function clickHandler(){
    var url = "https://api.funtranslations.com/translate/valyrian.json"
    txtInput = url + "?" + "text=" + input.value
    let fetched = fetch(txtInput)
    fetched
        .then(function(response){
            return response.json()
        })
        .then(function(json){
            translatedTxt = (json.contents.translated)
            output.innerText = translatedTxt
        })
        .catch(errorHandling)
}

btn.addEventListener('click', clickHandler);