var buttons = document.getElementsByClassName("button");
var display = document.getElementById("display");

// display.innerText = 0;
var operand1 = 0;
var operand2 = null;
var operator = null;

function isOperator(value) {
    return value == "+" || value == "-" || value == "*" || value == "/";
}


// basic calculation
for (var i = 0; i < buttons.length; i++) {
    buttons[i].addEventListener('click', function () {

        var value = this.getAttribute('data-value');
        var text = display.innerText.trim();
        console.log(text);

        if (isOperator(value)) {
            operator = value;
            operand1 = parseFloat(text);
            display.innerText = "";
            console.log(display.innerText);
        }

        else if (value == "ac") {
            display.innerText = "";
            console.log(display.innerText);
        }

        else if (value == "sign") {
            operand1 = parseFloat(text);
            operand1 = -1 * operand1;
            display.innerText = operand1;

            console.log(display.innerText);
        }

        else if (value == ".") {
            if (text.length && !text.includes('.')) {
                display.innerText = text + '.';
                console.log(text + '.');
            }
        }

        else if (value == "%") {
            operand1 = parseFloat(text);
            operand1 = operand1 / 100;
            display.innerText = operand1;
            console.log(display.innerText);
        }

        else if (value == "=") {
            operand2 = parseFloat(text);
            var result = eval(operand1 + ' ' + operator + ' ' + operand2);
            if (result) {
                console.log(display.innerText);
                display.innerText = result;
                operand1 = result;
                operand2 = null;
                operator = null;
            }
        }

        else {
            console.log(display.innerText);
            display.innerText += value;
        }
    });
}