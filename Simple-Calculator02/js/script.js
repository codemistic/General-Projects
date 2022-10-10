function getHistory() {
    return document.getElementById("history-value").innerText;

}
function printHIstory(num) {
    document.getElementById("history-value").innerText = num;
}

function getOutput() {
    return document.getElementById("output-value").innerText;
}
function printOutput(num) {

    if (num == "") {
        document.getElementById("output-value").innerText = num;
    } else {
        document.getElementById("output-value").innerText = getFormativeNum(num);
    }
}

function getFormativeNum(num) {

    if (num == '-') {
        return "";
    }

    var n = Number(num);
    var value = n.toLocaleString('en');
    return value;
}

function reverseNumberFormat(num) {
    return Number(num.replace(/,/g, ''));
}

// printOutput("99999");

// alert(reverseNumberFormat( getOutput() ));

var oprators = document.getElementsByClassName("operator");

for (var i = 0; i < oprators.length; i++) {
    oprators[i].addEventListener('click', function () {
        if (this.id == "clear") {
            printHIstory("");
            printOutput("");
        }
        else if (this.id == "backspace") {
            var output = reverseNumberFormat(getOutput()).toString();
            if (output) {
                output = output.substr(0, output.length - 1);
                printOutput(output);
            }
        }
        else if(this.id=="!"){
            var output = getOutput();
            var history = getHistory();
            console.log(output);
            console.log(history);
            let n= output;
            console.log("v");
            let answer = 1;
            if (n == 0 || n == 1){
                answer =1;
            }
            else{
                for(var i = n; i >= 1; i--){
                    answer = answer * i;
                }
                output =answer;
                history=history+output;
                var res = eval(history);
                printOutput(res);
                printHIstory("");
            }  
        }
        else if(this.id=="sign"){
            var output = getOutput();
            var history = getHistory();
            history=history+output;
            var res = eval(history);
            res=res*-1;
            printOutput(res);
            printHIstory(""); 
        }  
        else {
            var output = getOutput();
            var history = getHistory();

            if (output == "" && history != "") {
                if (isNaN(history[history.length - 1])) {
                    history = history.substr(0, history.length - 1);
                }
            }

            if (output != "" || history != "") {
                output = output === "" ? output : reverseNumberFormat(output);
                history = history + output;

                if (this.id == "=") {
                    var res = eval(history);
                    printOutput(res);
                    printHIstory("");
                }
                else {
                    history = history + this.id;
                    printHIstory(history);
                    printOutput("");
                }
            }
        }
    })
}

var numbers = document.getElementsByClassName("number");

for (var i = 0; i < numbers.length; i++) {
    numbers[i].addEventListener('click', function () {
        var output = reverseNumberFormat(getOutput());
        console.log(output);
        if (output != NaN) {
            output = output + this.id;
            printOutput(output);
        }
    });
}


// For Darkmode
var darkmode = document.getElementById("darkmode-icon");

darkmode.onclick = function () {
    document.body.classList.toggle("light-mode");
    if (document.body.classList.contains("light-mode")) {
        document.getElementsByClassName("container")[0].style.backgroundImage = "url(img/light.jpg)";
        
        darkmode.src = "/img/sun.png";

    }
    else {
        
        document.getElementsByClassName("container")[0].style.backgroundImage = "url(img/dark.jpg)";
        darkmode.src = "/img/moon.png";
    }

}


var play=true;
var count=1;
document.querySelector("#mute").addEventListener('click',function(){
    if(count%2){
        play=false;
        mute.innerText='🔇';
    }
    else{
       play=true;
       mute.innerText='🔊';
    }
    count++;
});

document.querySelector(".keyboard").addEventListener('click', function(){
    if(play){
        var audio= new Audio("./Audio/calculatorclick.mp3");
        audio.play();
    }
});
